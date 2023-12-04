/**
 * @file codec2.c  CODEC2 audio codec
 *
 * Copyright (C) 2015 Alfred E. Heggestad
 * Adapted for tSIP by Tomasz Ostrowski
 */
#include <re.h>
#include <rem.h>
#include <baresip.h>
#include <module.h>
#include <assert.h>
#include <codec2/codec2.h>
//#include "Log.h"
#include "Settings.h"

extern mem_alloc_cb mem_alloc_fn;
extern mem_deref_cb mem_deref_fn;
extern aucodec_register_cb aucodec_register_fn;
extern aucodec_unregister_cb aucodec_unregister_fn;

/**
 * @defgroup codec2 codec2
 *
 * The CODEC2 low-bitrate speech audio codec
 *
 * https://en.wikipedia.org/wiki/Codec2
 */


struct auenc_state {
	struct CODEC2 *c2;
};

struct audec_state {
	struct CODEC2 *c2;
};

uint32_t codec2_mode = CODEC2_MODE_2400;


static void encode_destructor(void *data)
{
	struct auenc_state *st = data;

	if (st->c2)
		codec2_destroy(st->c2);
}


static int encode_update(struct auenc_state **aesp,
			 const struct aucodec *ac,
			 struct auenc_param *prm, const char *fmtp)
{
	struct auenc_state *st;
	int err = 0;
	(void)prm;
	(void)fmtp;

	if (!aesp || !ac)
		return EINVAL;

	if (*aesp)
		return 0;

	st = mem_alloc_fn(sizeof(*st), encode_destructor);
	if (!st)
		return ENOMEM;
	memset(st, 0, sizeof(*st));

	st->c2 = codec2_create(codec2_mode);
	if (!st->c2) {
		err = ENOMEM;
		goto out;
	}

#if 0	
	LOG("codec2: %d samples per frame, %d bits per frame\n",
	     codec2_samples_per_frame(st->c2),
	     codec2_bits_per_frame(st->c2));
#endif	     

 out:
	if (err)
		mem_deref_fn(st);
	else
		*aesp = st;

	return err;
}


static void decode_destructor(void *data)
{
	struct audec_state *st = data;

	if (st->c2)
		codec2_destroy(st->c2);
}


static int decode_update(struct audec_state **adsp,
			 const struct aucodec *ac, const char *fmtp)
{
	struct audec_state *st;
	int err = 0;
	(void)fmtp;

	if (!adsp || !ac)
		return EINVAL;

	if (*adsp)
		return 0;

	st = mem_alloc_fn(sizeof(*st), decode_destructor);
	if (!st)
		return ENOMEM;
	memset(st, 0, sizeof(*st));

	st->c2 = codec2_create(codec2_mode);
	if (!st->c2) {
		err = ENOMEM;
		goto out;
	}

 out:
	if (err)
		mem_deref_fn(st);
	else
		*adsp = st;

	return err;
}


static int encode(struct auenc_state *aes, uint8_t *buf, size_t *len,
                  const int16_t *sampv, size_t sampc)
{
	size_t bytes_per_frame;

	if (!buf || !len || !sampv)
		return EINVAL;

	bytes_per_frame = (codec2_bits_per_frame(aes->c2) + 7) / 8;

	if (*len < bytes_per_frame)
		return ENOMEM;
	if (sampc != (size_t)codec2_samples_per_frame(aes->c2))
		return EPROTO;

	codec2_encode(aes->c2, buf, (short *)sampv);

	*len = bytes_per_frame;

	return 0;
}


static int decode(struct audec_state *ads, int16_t *sampv, size_t *sampc,
                  const uint8_t *buf, size_t len)
{
	size_t bytes_per_frame;

	if (!sampv || !sampc || !buf)
		return EINVAL;

	bytes_per_frame = (codec2_bits_per_frame(ads->c2) + 7) / 8;

	if (*sampc < (size_t)codec2_samples_per_frame(ads->c2))
		return ENOMEM;
	if (len < bytes_per_frame)
		return EPROTO;

	codec2_decode(ads->c2, sampv, buf);

	*sampc = codec2_samples_per_frame(ads->c2);

	return 0;
}


static struct aucodec codec2 = {
	.name      = "CODEC2",
	.srate     = 8000,
	.ch        = 1,
.encupdh   = encode_update,
	.ench      = encode,
	.decupdh   = decode_update,
	.dech      = decode,
};


static int module_init(void)
{
#if 0
	conf_get_u32(conf_cur(), "codec2_mode", &codec2_mode);

	info("codec2: using mode %d\n", codec2_mode);
#endif
	aucodec_register_fn(&codec2);
	
	GetSettings();

	return 0;
}


static int module_close(void)
{
	aucodec_unregister_fn(&codec2);

	SaveSettings();
	
	return 0;
}


EXPORT_SYM const struct mod_export DECL_EXPORTS(codec2) = {
	"codec2",
	"audio codec",
	module_init,
	module_close,
};

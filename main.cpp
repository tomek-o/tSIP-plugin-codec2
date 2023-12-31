#include "main.h"
#include <re.h>
#include <baresip.h>
#define _EXPORTING
#include <module.h>
#include <string>
#include <assert.h>


mem_alloc_cb mem_alloc_fn = NULL;
void set_mem_alloc_cb(mem_alloc_cb fn) {
    mem_alloc_fn = fn;
}

mem_deref_cb mem_deref_fn = NULL;
void set_mem_deref_cb(mem_deref_cb fn) {
    mem_deref_fn = fn;
}

aucodec_register_cb aucodec_register_fn = NULL;
void set_aucodec_register_cb(aucodec_register_cb fn) {
    aucodec_register_fn = fn;
}

aucodec_unregister_cb aucodec_unregister_fn = NULL;
void set_aucodec_unregister_cb(aucodec_unregister_cb fn) {
    aucodec_unregister_fn = fn;
}

void get_interface_description(struct S_DLL_INTERFACE* desc) {
    desc->major_version = DLL_INTERFACE_MAJOR_VERSION;
    desc->minor_version = DLL_INTERFACE_MINOR_VERSION;
}

int validate_dll(void) {
    if (!mem_alloc_fn)
        return 1;
    if (!mem_deref_fn)
        return 1;
    if (!aucodec_register_fn)
        return 1;
    if (!aucodec_unregister_fn)
        return 1;
    return 0;
}

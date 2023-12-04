/*
  Copyright (C) 2018 James C. Ahlstrom

  All rights reserved.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License version 2.1, as
  published by the Free Software Foundation.  This program is
  distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or
  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
  License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this program; if not, see <http://www.gnu.org/licenses/>.
*/

/*
  These are the coefficients for various FIR filters.  A declaration of these
  filter coefficients is in filter.h. Multiple filters can use these
  coefficients because they are read-only.

  Although a sample rate is specified, the filters may be used at other sample
  rates. For example, if filtP750S1040 is used at 48000 sps, the pass and stop
  frequencies are 4500 and 6240 Hz.
*/

// Low pass filter, sample rate 8000 hz, 0.2 dB ripple, 100 dB atten, pass 550
// Hz, stop 750 Hz. Used to build 700D BPF
float filtP550S750[160] = {
    0.000001500540125945,  0.000020553368071006,  0.000052842049763802,
    0.000112071233638701,  0.000202565299657164,  0.000325476960438197,
    0.000474396686568771,  0.000633746562372497,  0.000778858561033731,
    0.000878592697224500,  0.000900611877226272,  0.000818750000130019,
    0.000621157718914443,  0.000317269738067462,  -0.000058614729046822,
    -0.000448959090901751, -0.000780751290682747, -0.000978953969922609,
    -0.000983534965413392, -0.000766540799920385, -0.000344938705664714,
    0.000214927788687815,  0.000804118320944653,  0.001289527679116282,
    0.001541598437149897,  0.001466078039230554,  0.001032493743140772,
    0.000291727467744814,  -0.000623607913580581, -0.001518948630011706,
    -0.002175907515711935, -0.002402252989524116, -0.002082876981631170,
    -0.001219318501019004, 0.000053915753894017,  0.001483599323867600,
    0.002743518309691092,  0.003504691193108974,  0.003515993126242027,
    0.002676486805582815,  0.001080325423865147,  -0.000980649349095093,
    -0.003062866925046052, -0.004660487490214220, -0.005321805637618908,
    -0.004767235761853469, -0.002979877569160189, -0.000242864453416682,
    0.002892365745006815,  0.005707645107750651,  0.007473145256589892,
    0.007624527169837005,  0.005921569713871673,  0.002547381438730890,
    -0.001883079571618079, -0.006418195698900790, -0.009958090016198632,
    -0.011502199858687428, -0.010403943660694560, -0.006572745274759415,
    -0.000569370325758693, 0.006440667006225166,  0.012881777376768124,
    0.017083918451421990,  0.017661533458054445,  0.013877952730549446,
    0.005912685575826365,  -0.005037640104142052, -0.016864250576905999,
    -0.026855876467499887, -0.032168177048912679, -0.030370760878632559,
    -0.019967289813872333, -0.000782327027950076, 0.025871098651626040,
    0.057290144048617792,  0.089743290905422241,  0.119038289777397190,
    0.141198609990722840,  0.153125933205703250,  0.153125933205703250,
    0.141198609990722840,  0.119038289777397190,  0.089743290905422241,
    0.057290144048617792,  0.025871098651626040,  -0.000782327027950076,
    -0.019967289813872333, -0.030370760878632559, -0.032168177048912679,
    -0.026855876467499887, -0.016864250576905999, -0.005037640104142052,
    0.005912685575826365,  0.013877952730549446,  0.017661533458054445,
    0.017083918451421990,  0.012881777376768124,  0.006440667006225166,
    -0.000569370325758693, -0.006572745274759415, -0.010403943660694560,
    -0.011502199858687428, -0.009958090016198632, -0.006418195698900790,
    -0.001883079571618079, 0.002547381438730890,  0.005921569713871673,
    0.007624527169837005,  0.007473145256589892,  0.005707645107750651,
    0.002892365745006815,  -0.000242864453416682, -0.002979877569160189,
    -0.004767235761853469, -0.005321805637618908, -0.004660487490214220,
    -0.003062866925046052, -0.000980649349095093, 0.001080325423865147,
    0.002676486805582815,  0.003515993126242027,  0.003504691193108974,
    0.002743518309691092,  0.001483599323867600,  0.000053915753894017,
    -0.001219318501019004, -0.002082876981631170, -0.002402252989524116,
    -0.002175907515711935, -0.001518948630011706, -0.000623607913580581,
    0.000291727467744814,  0.001032493743140772,  0.001466078039230554,
    0.001541598437149897,  0.001289527679116282,  0.000804118320944653,
    0.000214927788687815,  -0.000344938705664714, -0.000766540799920385,
    -0.000983534965413392, -0.000978953969922609, -0.000780751290682747,
    -0.000448959090901751, -0.000058614729046822, 0.000317269738067462,
    0.000621157718914443,  0.000818750000130019,  0.000900611877226272,
    0.000878592697224500,  0.000778858561033731,  0.000633746562372497,
    0.000474396686568771,  0.000325476960438197,  0.000202565299657164,
    0.000112071233638701,  0.000052842049763802,  0.000020553368071006,
    0.000001500540125945};

/*
  Low pass filter, sample rate 8000 Hz, 60dB dB atten, pass 400 Hz, stop 600 Hz
  Used for datac0/datac1
  Generated using Octave:

  octave:170> h = fir1(99, 1000/8000);
  octave:171> save_array_c_header(h,"filtP400S600","t.h")
*/

float filtP400S600[100] = {
    0.0002190442859529,  0.0000253865765807,  -0.0001891607957119,
    -0.0004060215259363, -0.0006000085594001, -0.0007388342366621,
    -0.0007857143550906, -0.0007055101203620, -0.0004737796456378,
    -0.0000870157214033, 0.0004284822493668,  0.0010119603553043,
    0.0015702670713406,  0.0019880170510650,  0.0021456291121880,
    0.0019431076070540,  0.0013256670818267,  0.0003060762051584,
    -0.0010217279135397, -0.0024824214174461, -0.0038352454444032,
    -0.0048061266813482, -0.0051327431531073, -0.0046162222656579,
    -0.0031708262919099, -0.0008619578234589, 0.0020765315052916,
    0.0052523330844492,  0.0081546351293169,  0.0102217640867241,
    0.0109290873716773,  0.0098852729183138,  0.0069220529480671,
    0.0021618869962732,  -0.0039502956265373, -0.0106608379232220,
    -0.0169699130332444, -0.0217388847493965, -0.0238311162893102,
    -0.0222687242579450, -0.0163838891184744, -0.0059424763426467,
    0.0087797880290842,  0.0269827101964810,  0.0473946488239843,
    0.0683898571372469,  0.0881575538806286,  0.1049023332507096,
    0.1170504418131305,  0.1234349185246360,  0.1234349185246360,
    0.1170504418131306,  0.1049023332507097,  0.0881575538806286,
    0.0683898571372469,  0.0473946488239843,  0.0269827101964810,
    0.0087797880290842,  -0.0059424763426467, -0.0163838891184744,
    -0.0222687242579450, -0.0238311162893102, -0.0217388847493965,
    -0.0169699130332444, -0.0106608379232220, -0.0039502956265373,
    0.0021618869962732,  0.0069220529480671,  0.0098852729183138,
    0.0109290873716773,  0.0102217640867241,  0.0081546351293169,
    0.0052523330844492,  0.0020765315052916,  -0.0008619578234589,
    -0.0031708262919099, -0.0046162222656579, -0.0051327431531073,
    -0.0048061266813482, -0.0038352454444032, -0.0024824214174461,
    -0.0010217279135397, 0.0003060762051584,  0.0013256670818267,
    0.0019431076070540,  0.0021456291121880,  0.0019880170510650,
    0.0015702670713406,  0.0010119603553043,  0.0004284822493668,
    -0.0000870157214033, -0.0004737796456378, -0.0007055101203620,
    -0.0007857143550906, -0.0007388342366621, -0.0006000085594001,
    -0.0004060215259363, -0.0001891607957119, 0.0000253865765807,
    0.0002190442859529};

/*
  Low pass filter, sample rate 8000 Hz, 60dB dB atten, pass 650 Hz, stop 900 Hz
  Alternate filter for use with 700D and clipper.  A little extra bandwidth
  helps reduce PAPR.

  Generated using Octave:
  octave:170> h = fir1(100, 1500/8000);
  octave:171> save_array_c_header(h,"filtP650S900","t.h")
*/

float filtP650S900[100] = {
    -0.0003447438107989, -0.0000773443016821, 0.0002396774493908,
    0.0005183973970710,  0.0006638187313266,  0.0005975981831705,
    0.0002897687607439,  -0.0002119524114060, -0.0007715254253800,
    -0.0011873172727259, -0.0012521109061848, -0.0008371281604995,
    0.0000296985029260,  0.0011281958214742,  0.0020819312900066,
    0.0024705948613571,  0.0019912318935963,  0.0006124281900638,
    -0.0013451726955418, -0.0032531555468084, -0.0043549616066416,
    -0.0040377485154437, -0.0021065223027673, 0.0010488136629895,
    0.0044817586852605,  0.0069407381267179,  0.0072892156498907,
    0.0049639277235708,  0.0003023755700798,  -0.0054092967401810,
    -0.0102368927453788, -0.0121970459192933, -0.0099848952803716,
    -0.0035856433622624, 0.0054724953549814,  0.0143763043146873,
    0.0197915861224756,  0.0189508548007168,  0.0107444584473630,
    -0.0035511748160051, -0.0202026606441822, -0.0337226677294633,
    -0.0382279329229346, -0.0291127865967771, -0.0045659298430227,
    0.0335371151119154,  0.0796831473314644,  0.1257715935323888,
    0.1629350232213685,  0.1836638608187552,  0.1836638608187552,
    0.1629350232213685,  0.1257715935323888,  0.0796831473314644,
    0.0335371151119154,  -0.0045659298430227, -0.0291127865967771,
    -0.0382279329229346, -0.0337226677294633, -0.0202026606441822,
    -0.0035511748160051, 0.0107444584473630,  0.0189508548007168,
    0.0197915861224756,  0.0143763043146873,  0.0054724953549814,
    -0.0035856433622624, -0.0099848952803716, -0.0121970459192933,
    -0.0102368927453788, -0.0054092967401810, 0.0003023755700798,
    0.0049639277235708,  0.0072892156498907,  0.0069407381267179,
    0.0044817586852605,  0.0010488136629895,  -0.0021065223027673,
    -0.0040377485154437, -0.0043549616066416, -0.0032531555468084,
    -0.0013451726955418, 0.0006124281900638,  0.0019912318935963,
    0.0024705948613571,  0.0020819312900066,  0.0011281958214742,
    0.0000296985029260,  -0.0008371281604995, -0.0012521109061848,
    -0.0011873172727259, -0.0007715254253800, -0.0002119524114060,
    0.0002897687607439,  0.0005975981831705,  0.0006638187313266,
    0.0005183973970710,  0.0002396774493908,  -0.0000773443016821,
    -0.0003447438107989};

/*
  Low pass filter, sample rate 8000 Hz, 60dB dB atten, pass 900 Hz, stop 1100 Hz
  Initially used to build 700E BPF.

  Generated using Octave:
  octave:170> h = fir1(100, 2000/8000);
  octave:171> save_array_c_header(h,"filtP900S1100","t.h")
*/

float filtP900S1100[] = {
    0.0004418158615696,  0.0001287637146300,  -0.0002887027062308,
    -0.0005878482226797, -0.0005730851022636, -0.0001872428398401,
    0.0004164064769556,  0.0009044243294414,  0.0009214286447099,
    0.0003198823196113,  -0.0006735180958441, -0.0014968764631324,
    -0.0015397255009494, -0.0005518542214485, 0.0010799820573451,
    0.0024224384337026,  0.0024915418423841,  0.0009146857642078,
    -0.0016601832557821, -0.0037544126485350, -0.0038606363852215,
    -0.0014507340945908, 0.0024489243815523,  0.0055987186471211,
    0.0057705307663451,  0.0022226683344412,  -0.0035036863386865,
    -0.0081289422623303, -0.0084269758191975, -0.0033347717101330,
    0.0049319056855186,  0.0116673991980949,  0.0122195177108518,
    0.0049860194363942,  -0.0069600525064408, -0.0169004061958973,
    -0.0180041048574631, -0.0076258897964686, 0.0101458756070637,
    0.0255847362406635,  0.0280993703146360,  0.0125508957876736,
    -0.0162678073198399, -0.0438597596479416, -0.0516282045539403,
    -0.0256831488498926, 0.0353080736910379,  0.1173458947603512,
    0.1953111386765199,  0.2427155307119274,  0.2427155307119275,
    0.1953111386765199,  0.1173458947603512,  0.0353080736910379,
    -0.0256831488498926, -0.0516282045539403, -0.0438597596479416,
    -0.0162678073198399, 0.0125508957876736,  0.0280993703146360,
    0.0255847362406635,  0.0101458756070637,  -0.0076258897964686,
    -0.0180041048574631, -0.0169004061958973, -0.0069600525064408,
    0.0049860194363942,  0.0122195177108518,  0.0116673991980949,
    0.0049319056855186,  -0.0033347717101330, -0.0084269758191975,
    -0.0081289422623303, -0.0035036863386865, 0.0022226683344412,
    0.0057705307663451,  0.0055987186471211,  0.0024489243815523,
    -0.0014507340945908, -0.0038606363852214, -0.0037544126485350,
    -0.0016601832557821, 0.0009146857642078,  0.0024915418423841,
    0.0024224384337026,  0.0010799820573451,  -0.0005518542214485,
    -0.0015397255009494, -0.0014968764631324, -0.0006735180958441,
    0.0003198823196113,  0.0009214286447099,  0.0009044243294414,
    0.0004164064769556,  -0.0001872428398401, -0.0005730851022636,
    -0.0005878482226797, -0.0002887027062308, 0.0001287637146300,
    0.0004418158615696};

/*
  Low pass filter, sample rate 8000 Hz, 60dB dB atten, pass 1100 Hz, stop 1300
  Hz Designed for 2020B.

  Generated using Octave:
  octave:77> h = fir1(99, 2400/8000); f=500:1500; w=f*pi/4000; H=freqz(h,1,w);
  octave:78> clf; plot(f,20*log10(abs(H))); grid; axis([500 1500 -60 10])
  octave:79> save_array_c_header(h,"filtP1100S1300","t.h")
*/

float filtP1100S1300[] = {
    0.0002976192596492,  0.0005268501327879,  0.0003323197705342,
    -0.0001770640927819, -0.0006221531076115, -0.0006005231876771,
    -0.0000195189229256, 0.0007355731515642,  0.0010099584762544,
    0.0004067132502827,  -0.0007585687884437, -0.0015415736366462,
    -0.0010864635373405, 0.0005254729116986,  0.0020855203587287,
    0.0021026629812395,  0.0001529382567188,  -0.0024362700654142,
    -0.0033992733694222, -0.0014410368832294, 0.0023100278520809,
    0.0047915084415380,  0.0034240108979541,  -0.0013824387082528,
    -0.0059564413269030, -0.0060581288076594, -0.0006611518028655,
    0.0064434052119832,  0.0091346892160535,  0.0040759939927406,
    -0.0056953567245917, -0.0122613043769937, -0.0090272691278832,
    0.0030572766146697,  0.0148523753937746,  0.0156061208345573,
    0.0022854541227764,  -0.0160929898905979, -0.0239498761167209,
    -0.0116013322861975, 0.0147513846300672,  0.0346571639712145,
    0.0277787088019838,  -0.0082808984532188, -0.0505010122605824,
    -0.0613407201912362, -0.0130972319259225, 0.0900965824440442,
    0.2087764094817421,  0.2877718571344791,  0.2877718571344791,
    0.2087764094817421,  0.0900965824440442,  -0.0130972319259225,
    -0.0613407201912362, -0.0505010122605824, -0.0082808984532188,
    0.0277787088019838,  0.0346571639712145,  0.0147513846300672,
    -0.0116013322861975, -0.0239498761167209, -0.0160929898905979,
    0.0022854541227764,  0.0156061208345573,  0.0148523753937746,
    0.0030572766146697,  -0.0090272691278832, -0.0122613043769937,
    -0.0056953567245917, 0.0040759939927406,  0.0091346892160535,
    0.0064434052119832,  -0.0006611518028655, -0.0060581288076594,
    -0.0059564413269030, -0.0013824387082528, 0.0034240108979541,
    0.0047915084415380,  0.0023100278520809,  -0.0014410368832294,
    -0.0033992733694222, -0.0024362700654142, 0.0001529382567188,
    0.0021026629812395,  0.0020855203587287,  0.0005254729116986,
    -0.0010864635373405, -0.0015415736366462, -0.0007585687884437,
    0.0004067132502827,  0.0010099584762544,  0.0007355731515642,
    -0.0000195189229256, -0.0006005231876771, -0.0006221531076115,
    -0.0001770640927819, 0.0003323197705342,  0.0005268501327879,
    0.0002976192596492};

/*
  Low pass prototype, sample rate 8000 Hz, 60dB dB atten.

  Used as an input BPF for datac4 and datac13

  Generated using Octave:
  octave:77> h = fir1(99, 400/8000); f=0:500; w=f*pi/4000; H=freqz(h,1,w);
  octave:78> clf; plot(f,20*log10(abs(H))); grid; axis([0 500 -60 10])
  octave:79> save_array_c_header(h,"filtP200S400","t.h")
*/

float filtP200S400[] = {
    0.0004961403001099,  0.0004878954300076,  0.0004773254753068,
    0.0004613755012320,  0.0004356367390736,  0.0003945564225800,
    0.0003317489139155,  0.0002403980632049,  0.0001137356780462,
    -0.0000544235817172, -0.0002691144005802, -0.0005336465184803,
    -0.0008490522002088, -0.0012135843244779, -0.0016222933008125,
    -0.0020667090843560, -0.0025346513768318, -0.0030101867721908,
    -0.0034737462756490, -0.0039024104893224, -0.0042703630503403,
    -0.0045495058923843, -0.0047102228630850, -0.0047222714599590,
    -0.0045557762351127, -0.0041822920363898, -0.0035759009450005,
    -0.0027143037436366, -0.0015798651637566, -0.0001605721201941,
    0.0015491343107337,  0.0035476892962647,  0.0058259285585604,
    0.0083668321698320,  0.0111455063209044,  0.0141294135724972,
    0.0172788535145399,  0.0205476868890766,  0.0238842874108655,
    0.0272326970839423,  0.0305339530892875,  0.0337275476120884,
    0.0367529765550393,  0.0395513291682391,  0.0420668683822783,
    0.0442485511620683,  0.0460514395405405,  0.0474379561100668,
    0.0483789425435863,  0.0488544860205982,  0.0488544860205982,
    0.0483789425435863,  0.0474379561100668,  0.0460514395405405,
    0.0442485511620683,  0.0420668683822783,  0.0395513291682391,
    0.0367529765550394,  0.0337275476120884,  0.0305339530892875,
    0.0272326970839423,  0.0238842874108655,  0.0205476868890766,
    0.0172788535145399,  0.0141294135724972,  0.0111455063209044,
    0.0083668321698320,  0.0058259285585604,  0.0035476892962647,
    0.0015491343107337,  -0.0001605721201941, -0.0015798651637566,
    -0.0027143037436366, -0.0035759009450005, -0.0041822920363898,
    -0.0045557762351127, -0.0047222714599590, -0.0047102228630850,
    -0.0045495058923843, -0.0042703630503403, -0.0039024104893224,
    -0.0034737462756490, -0.0030101867721908, -0.0025346513768318,
    -0.0020667090843560, -0.0016222933008125, -0.0012135843244779,
    -0.0008490522002088, -0.0005336465184803, -0.0002691144005802,
    -0.0000544235817172, 0.0001137356780462,  0.0002403980632049,
    0.0003317489139155,  0.0003945564225800,  0.0004356367390736,
    0.0004613755012320,  0.0004773254753068,  0.0004878954300076,
    0.0004961403001099};

// FIR filter suitable for changing rates 7500 to/from 8000
// Sample 120000 Hz, pass 2700, stop 3730, ripple 0.1dB, atten 100 dB.  Stop
// 0.03108.
float quiskFilt120t480[480] = {
    -0.000005050567303837, -0.000000267011791999, 0.000000197734700398,
    0.000001038946634000,  0.000002322193058869,  0.000004115682735322,
    0.000006499942123311,  0.000009551098482930,  0.000013350669444763,
    0.000017966192635412,  0.000023463361155584,  0.000029885221425020,
    0.000037271082107518,  0.000045630720487935,  0.000054970017069384,
    0.000065233162392019,  0.000076360900545177,  0.000088271373315159,
    0.000100818605854714,  0.000113853476544409,  0.000127174196746337,
    0.000140558396336177,  0.000153744508371709,  0.000166450784469067,
    0.000178368313347299,  0.000189176709991702,  0.000198541881389953,
    0.000206128795372885,  0.000211604878787747,  0.000214655997661182,
    0.000214994859281552,  0.000212358734245594,  0.000206539880117977,
    0.000197379393194548,  0.000184780318878738,  0.000168719942655099,
    0.000149250512353807,  0.000126511346757621,  0.000100726393185629,
    0.000072210925236429,  0.000041365841965015,  0.000008680571408025,
    -0.000025277165852799, -0.000059865389594949, -0.000094384355854646,
    -0.000128080670195777, -0.000160170174848483, -0.000189854272533545,
    -0.000216333899003825, -0.000238836419299503, -0.000256632149501508,
    -0.000269058714331757, -0.000275541485292432, -0.000275614059005332,
    -0.000268937472718753, -0.000255317038867589, -0.000234717772155001,
    -0.000207273956099563, -0.000173297342436372, -0.000133280012107173,
    -0.000087895370243821, -0.000037986085678081, 0.000015440388211825,
    0.000071232572821451,  0.000128114399130489,  0.000184710477990398,
    0.000239577162514028,  0.000291234779803098,  0.000338204791740229,
    0.000379047713684221,  0.000412403761615261,  0.000437031818051652,
    0.000451848709179591,  0.000455966225408344,  0.000448726371643413,
    0.000429729020814434,  0.000398857326863837,  0.000356297600912998,
    0.000302547334727027,  0.000238422248479072,  0.000165048886226905,
    0.000083853091464077,  -0.000003462782744354, -0.000094949813106744,
    -0.000188451833293202, -0.000281651282503015, -0.000372121907291206,
    -0.000457387566635848, -0.000534985542936898, -0.000602532044011899,
    -0.000657788245032425, -0.000698728981427767, -0.000723604675185869,
    -0.000731002305621048, -0.000719899536922384, -0.000689709694056092,
    -0.000640319946685634, -0.000572115873292030, -0.000485996080304965,
    -0.000383371840261246, -0.000266155252511831, -0.000136731311264191,
    0.000002082667095075,  0.000147092077716480,  0.000294790953130229,
    0.000441441918072383,  0.000583164190168290,  0.000716029226064227,
    0.000836164238172957,  0.000939856052624227,  0.001023657909064450,
    0.001084492755093968,  0.001119751426837743,  0.001127383039339373,
    0.001105974243787613,  0.001054815583369999,  0.000973950761085690,
    0.000864209315714227,  0.000727219011746881,  0.000565398080608305,
    0.000381924396468366,  0.000180685902835315,  -0.000033793183292569,
    -0.000256444114966522, -0.000481764526566339, -0.000703946352348464,
    -0.000917016099829735, -0.001114986581270253, -0.001292014799874503,
    -0.001442563411804926, -0.001561559957317790, -0.001644551048567398,
    -0.001687846581475964, -0.001688649703502788, -0.001645167889846890,
    -0.001556702802350076, -0.001423714708648073, -0.001247857669697092,
    -0.001031986722557201, -0.000780131048444402, -0.000497436825078657,
    -0.000190077210351809, 0.000134868279325909,  0.000469563533327739,
    0.000805591531546815,  0.001134152328775355,  0.001446279849797673,
    0.001733071409562941,  0.001985924997799762,  0.002196778054604388,
    0.002358342626407065,  0.002464328098407475,  0.002509648218888532,
    0.002490604086803692,  0.002405037734357425,  0.002252452724297770,
    0.002034094661603120,  0.001752990365583534,  0.001413941154886139,
    0.001023470495638453,  0.000589723521647734,  0.000122320866350319,
    -0.000367832138027160, -0.000868777013398284, -0.001367771151677059,
    -0.001851587344265625, -0.002306838088978190, -0.002720317947026380,
    -0.003079353614002113, -0.003372155891804708, -0.003588162376578369,
    -0.003718362558663737, -0.003755596511143005, -0.003694818131674599,
    -0.003533315298404129, -0.003270878754553819, -0.002909914962857412,
    -0.002455496391464944, -0.001915346645364514, -0.001299757227227888,
    -0.000621437066532776, 0.000104706515738248,  0.000861849931067767,
    0.001631595707499856,  0.002394368911341672,  0.003129858565588139,
    0.003817496679992245,  0.004436963307209760,  0.004968707287606522,
    0.005394469536085115,  0.005697797543539088,  0.005864537618023589,
    0.005883292537600076,  0.005745832319314692,  0.005447447099071761,
    0.004987231255534477,  0.004368289529377007,  0.003597859022418248,
    0.002687338851256991,  0.001652226293162047,  0.000511956075882180,
    -0.000710356149138656, -0.001988263330091648, -0.003292424566049982,
    -0.004591123342747130, -0.005850857852106148, -0.007036991266043732,
    -0.008114450164977267, -0.009048456200082230, -0.009805276478965942,
    -0.010352975302354198, -0.010662152577592631, -0.010706650669328861,
    -0.010464214075017983, -0.009917087295446811, -0.009052534679222271,
    -0.007863270920348924, -0.006347789704693751, -0.004510582323649121,
    -0.002362238055733795, 0.000080576968834213,  0.002795265196543707,
    0.005753566158586979,  0.008921944932552510,  0.012262093950265378,
    0.015731539846483594,  0.019284344624007944,  0.022871886384520687,
    0.026443706729191677,  0.029948406200633094,  0.033334570666910354,
    0.036551709955124537,  0.039551189200810140,  0.042287133974308874,
    0.044717290029466283,  0.046803820535016104,  0.048514022996355009,
    0.049820951883635139,  0.050703932928426454,  0.051148959210315710,
    0.051148959210315710,  0.050703932928426454,  0.049820951883635139,
    0.048514022996355009,  0.046803820535016104,  0.044717290029466283,
    0.042287133974308874,  0.039551189200810140,  0.036551709955124537,
    0.033334570666910354,  0.029948406200633094,  0.026443706729191677,
    0.022871886384520687,  0.019284344624007944,  0.015731539846483594,
    0.012262093950265378,  0.008921944932552510,  0.005753566158586979,
    0.002795265196543707,  0.000080576968834213,  -0.002362238055733795,
    -0.004510582323649121, -0.006347789704693751, -0.007863270920348924,
    -0.009052534679222271, -0.009917087295446811, -0.010464214075017983,
    -0.010706650669328861, -0.010662152577592631, -0.010352975302354198,
    -0.009805276478965942, -0.009048456200082230, -0.008114450164977267,
    -0.007036991266043732, -0.005850857852106148, -0.004591123342747130,
    -0.003292424566049982, -0.001988263330091648, -0.000710356149138656,
    0.000511956075882180,  0.001652226293162047,  0.002687338851256991,
    0.003597859022418248,  0.004368289529377007,  0.004987231255534477,
    0.005447447099071761,  0.005745832319314692,  0.005883292537600076,
    0.005864537618023589,  0.005697797543539088,  0.005394469536085115,
    0.004968707287606522,  0.004436963307209760,  0.003817496679992245,
    0.003129858565588139,  0.002394368911341672,  0.001631595707499856,
    0.000861849931067767,  0.000104706515738248,  -0.000621437066532776,
    -0.001299757227227888, -0.001915346645364514, -0.002455496391464944,
    -0.002909914962857412, -0.003270878754553819, -0.003533315298404129,
    -0.003694818131674599, -0.003755596511143005, -0.003718362558663737,
    -0.003588162376578369, -0.003372155891804708, -0.003079353614002113,
    -0.002720317947026380, -0.002306838088978190, -0.001851587344265625,
    -0.001367771151677059, -0.000868777013398284, -0.000367832138027160,
    0.000122320866350319,  0.000589723521647734,  0.001023470495638453,
    0.001413941154886139,  0.001752990365583534,  0.002034094661603120,
    0.002252452724297770,  0.002405037734357425,  0.002490604086803692,
    0.002509648218888532,  0.002464328098407475,  0.002358342626407065,
    0.002196778054604388,  0.001985924997799762,  0.001733071409562941,
    0.001446279849797673,  0.001134152328775355,  0.000805591531546815,
    0.000469563533327739,  0.000134868279325909,  -0.000190077210351809,
    -0.000497436825078657, -0.000780131048444402, -0.001031986722557201,
    -0.001247857669697092, -0.001423714708648073, -0.001556702802350076,
    -0.001645167889846890, -0.001688649703502788, -0.001687846581475964,
    -0.001644551048567398, -0.001561559957317790, -0.001442563411804926,
    -0.001292014799874503, -0.001114986581270253, -0.000917016099829735,
    -0.000703946352348464, -0.000481764526566339, -0.000256444114966522,
    -0.000033793183292569, 0.000180685902835315,  0.000381924396468366,
    0.000565398080608305,  0.000727219011746881,  0.000864209315714227,
    0.000973950761085690,  0.001054815583369999,  0.001105974243787613,
    0.001127383039339373,  0.001119751426837743,  0.001084492755093968,
    0.001023657909064450,  0.000939856052624227,  0.000836164238172957,
    0.000716029226064227,  0.000583164190168290,  0.000441441918072383,
    0.000294790953130229,  0.000147092077716480,  0.000002082667095075,
    -0.000136731311264191, -0.000266155252511831, -0.000383371840261246,
    -0.000485996080304965, -0.000572115873292030, -0.000640319946685634,
    -0.000689709694056092, -0.000719899536922384, -0.000731002305621048,
    -0.000723604675185869, -0.000698728981427767, -0.000657788245032425,
    -0.000602532044011899, -0.000534985542936898, -0.000457387566635848,
    -0.000372121907291206, -0.000281651282503015, -0.000188451833293202,
    -0.000094949813106744, -0.000003462782744354, 0.000083853091464077,
    0.000165048886226905,  0.000238422248479072,  0.000302547334727027,
    0.000356297600912998,  0.000398857326863837,  0.000429729020814434,
    0.000448726371643413,  0.000455966225408344,  0.000451848709179591,
    0.000437031818051652,  0.000412403761615261,  0.000379047713684221,
    0.000338204791740229,  0.000291234779803098,  0.000239577162514028,
    0.000184710477990398,  0.000128114399130489,  0.000071232572821451,
    0.000015440388211825,  -0.000037986085678081, -0.000087895370243821,
    -0.000133280012107173, -0.000173297342436372, -0.000207273956099563,
    -0.000234717772155001, -0.000255317038867589, -0.000268937472718753,
    -0.000275614059005332, -0.000275541485292432, -0.000269058714331757,
    -0.000256632149501508, -0.000238836419299503, -0.000216333899003825,
    -0.000189854272533545, -0.000160170174848483, -0.000128080670195777,
    -0.000094384355854646, -0.000059865389594949, -0.000025277165852799,
    0.000008680571408025,  0.000041365841965015,  0.000072210925236429,
    0.000100726393185629,  0.000126511346757621,  0.000149250512353807,
    0.000168719942655099,  0.000184780318878738,  0.000197379393194548,
    0.000206539880117977,  0.000212358734245594,  0.000214994859281552,
    0.000214655997661182,  0.000211604878787747,  0.000206128795372885,
    0.000198541881389953,  0.000189176709991702,  0.000178368313347299,
    0.000166450784469067,  0.000153744508371709,  0.000140558396336177,
    0.000127174196746337,  0.000113853476544409,  0.000100818605854714,
    0.000088271373315159,  0.000076360900545177,  0.000065233162392019,
    0.000054970017069384,  0.000045630720487935,  0.000037271082107518,
    0.000029885221425020,  0.000023463361155584,  0.000017966192635412,
    0.000013350669444763,  0.000009551098482930,  0.000006499942123311,
    0.000004115682735322,  0.000002322193058869,  0.000001038946634000,
    0.000000197734700398,  -0.000000267011791999, -0.000005050567303837};

#pragma once

#include "jasonsbullshit.h"

#define LAYOUT_ortho_5x14( \
    k00, k01, k02, k03, k04, k05, k06,   k50, k51, k52, k53, k54, k55, k56, \
    k10, k11, k12, k13, k14, k15, k16,   k60, k61, k62, k63, k64, k65, k66, \
    k20, k21, k22, k23, k24, k25, k26,   k70, k71, k72, k73, k74, k75, k76, \
    k30, k31, k32, k33, k34, k35, k36,   k80, k81, k82, k83, k84, k85, k86, \
    k40, k41, k42, k43, k44, k45, k46,   k90, k91, k92, k93, k94, k95, k96 \
) \
{ \
    { k00, k01, k02, k03, k04, k05, k06 }, \
    { k10, k11, k12, k13, k14, k15, k16 }, \
    { k20, k21, k22, k23, k24, k25, k26 }, \
    { k30, k31, k32, k33, k34, k35, k36 }, \
    { k40, k41, k42, k43, k44, k45, k46 }, \
    { k50, k51, k52, k53, k54, k55, k56 }, \
    { k60, k61, k62, k63, k64, k65, k66 }, \
    { k70, k71, k72, k73, k74, k75, k76 }, \
    { k80, k81, k82, k83, k84, k85, k86 }, \
    { k90, k91, k92, k93, k94, k95, k96 }, \
}


#define LAYOUT LAYOUT_ortho_5x14

#pragma once

#include "layers.h"
#include "layer_names.h"

#define U_MACRO_VA_ARGS(macro, ...) macro(__VA_ARGS__)

#define U_RDO KC_AGIN
#define U_PST S(KC_INS)
#define U_CPY C(KC_INS)
#define U_CUT S(KC_DEL)
#define U_UND KC_UNDO

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

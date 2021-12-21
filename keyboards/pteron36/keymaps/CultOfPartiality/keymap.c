#include QMK_KEYBOARD_H

#include "defines.h"

enum layers { LAYER_NAMES };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE]   = U_MACRO_VA_ARGS(LAYOUT_split_3x5_3_encoder, LAYER_KEYMAP_BASE),
  [NAV]    = U_MACRO_VA_ARGS(LAYOUT_split_3x5_3_encoder, LAYER_KEYMAP_NAV),
  [MOUSE]  = U_MACRO_VA_ARGS(LAYOUT_split_3x5_3_encoder, LAYER_KEYMAP_MOUSE),
  [MEDIA]  = U_MACRO_VA_ARGS(LAYOUT_split_3x5_3_encoder, LAYER_KEYMAP_MEDIA),
  [NUM]    = U_MACRO_VA_ARGS(LAYOUT_split_3x5_3_encoder, LAYER_KEYMAP_NUM),
  [SYM]    = U_MACRO_VA_ARGS(LAYOUT_split_3x5_3_encoder, LAYER_KEYMAP_SYM),
  [FUN]    = U_MACRO_VA_ARGS(LAYOUT_split_3x5_3_encoder, LAYER_KEYMAP_FUN),
  [BUTTON] = U_MACRO_VA_ARGS(LAYOUT_split_3x5_3_encoder, LAYER_KEYMAP_BUTTON)
};

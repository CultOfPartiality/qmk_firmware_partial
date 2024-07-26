#include QMK_KEYBOARD_H

// Userspace
#include "cultofpartiality.h"

// Split sections into different file for clarity
#include "defines.h"

//  The following define allows for multi-key definition macros
#define LAYOUT_wrapper(...)   LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_QWERTY] = LAYOUT(
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                   /**/                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,

    QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                   /**/                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
    KC_TAB,  HM_A,    HM_S,    HM_D,    HM_F,    KC_G,                   /**/                     KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                   /**/                     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,

    KC_LCTL, KC_LGUI, KC_LALT, KC_V,                                     /**/                                       _______, KC_EQL,  KC_RGUI, KC_RCTL,
                                     KC_ESC,  KC_SPC, KC_TAB,   KC_PGUP, /**/ QK_BOOT, KC_BSPC,   KC_ENT,  KC_DEL,
                                                      KC_DEL,   KC_PGDN, /**/ KC_5,    KC_6
    ),
};


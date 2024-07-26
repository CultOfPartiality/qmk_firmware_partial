#include QMK_KEYBOARD_H

// Keymap layouts
//
//  The following define allows for multi-key definition macros
#define LAYOUT_split_3x6_4_wrapper(...)   LAYOUT_split_3x6_4(__VA_ARGS__)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY]   = LAYOUT_split_3x6_4(
    /*  -------, -------, -------, -------, -------, -------, -------, -------, /##/ -------, -------, -------, -------, -------, -------, -------, -------,*/
        QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      /**/                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  HM_A,    HM_S,    HM_D,    HM_F,    KC_G,                      /**/                   KC_H,    HM_J,    HM_K,    HM_L,    HM_SCLN, HM_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      /**/                   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
                                            KC_1,    KC_ESC,  KC_SPC, KC_TAB,   /**/ KC_BSPC, KC_ENT,  KC_DEL,  QK_BOOT
    ),
};

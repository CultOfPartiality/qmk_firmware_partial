#include QMK_KEYBOARD_H

// Userspace
#include "cultofpartiality.h"

// Split sections into different file for clarity
#include "defines.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
   QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           /**/                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           /**/                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
   KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                           /**/                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                           /**/                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
   KC_LCTL, KC_LGUI, KC_LALT, KC_V,                                             /**/                                        KM_CSHT, KC_EQL,  KC_RGUI, KC_RCTL,
                                            SYM_L,   KC_SPC,  KC_ENT,  KC_PGUP, /**/ KC_1,    KC_2,   KC_ENT,  NAV_L,
                                                              KC_DEL,  KC_PGDN, /**/ KC_5,    KC_6
),
[_SYMB] = LAYOUT(
   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          /**/                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
   _______, KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        /**/                       KC_EQL,  KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, KC_F12,
   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,                        /**/                       KC_MINS, KC_LPRN, KC_RPRN, XXXXXXX, KC_PIPE, KC_BSLS,
   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        /**/                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
   _______, _______, _______, _______,                                          /**/                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            _______, _______, _______, _______, /**/ _______, _______, _______, _______,
                                                              _______, _______, /**/ _______, _______
),
[_NAV] = LAYOUT(
   _______, _______, _______, _______, _______, _______,                        /**/                       _______, _______, _______, _______, _______, _______,
   XXXXXXX, NAV_L4T, NAV_L3T, NAV_L2T, NAV_L1T, NAV_L0T,                        /**/                       NAV_R0T, NAV_R1T, NAV_R2T, NAV_R3T, NAV_R4T, _______,
   XXXXXXX, NAV_L4M, NAV_L3M, NAV_L2M, NAV_L1M, NAV_L0M,                        /**/                       NAV_R0M, NAV_R1M, NAV_R2M, NAV_R3M, NAV_R4M, XXXXXXX,
   _______, NAV_L4B, NAV_L3B, NAV_L2B, NAV_L1B, NAV_L0B,                        /**/                       NAV_R0B, NAV_R1B, NAV_R2B, NAV_R3B, NAV_R4B, _______,
   _______, _______, _______, _______,                                          /**/                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            _______, _______, _______, _______, /**/ _______, _______, _______, _______,
                                                              _______, _______, /**/ _______, _______
),
[_ADJUST] = LAYOUT(
   QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        /**/                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        /**/                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        /**/                       XXXXXXX, KC_PWIN, XXXXXXX, KC_NWIN, XXXXXXX, XXXXXXX,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        /**/                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                          /**/                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            _______, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                                              XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    //Activate adjust layer if both symb and nav layers are active at the same time
    state = update_tri_layer_state(state, _SYMB, _NAV, _ADJUST);
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

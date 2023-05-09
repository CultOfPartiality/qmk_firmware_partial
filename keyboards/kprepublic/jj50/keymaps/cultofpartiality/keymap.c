/*
Copyright 2020 Guillaume Gérard

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public LicensezZZ
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Userspace
#include "cultofpartiality.h"

enum jj50_layers {
  _QWERTY,
  _MODTAP,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMPAD,
  _FN
};

enum jj50_keycodes {
  QWERTY = SAFE_RANGE,
  MODTAP,
  LOWER,
  RAISE,
  BACKLIT
};

//Layer defines
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NUMPAD MO(_NUMPAD)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
* ,-----------------------------------------------------------------------------------.
* |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |  FN  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
* `-----------------------------------------------------------------------------------'
*/
[_QWERTY] = LAYOUT(
  QK_GESC, KC_1,    KC_2,    KC_3,  KC_4,  KC_5,   /**/ KC_6,    KC_7,   KC_8,     KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,   /**/ KC_Y,    KC_U,   KC_I,     KC_O,    KC_P,    KC_DEL,
  KC_TAB,  KC_A,    KC_S,    KC_D,  KC_F,  KC_G,   /**/ KC_H,    KC_J,   KC_K,     KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,  KC_V,  KC_B,   /**/ KC_N,    KC_M,   KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT, LOWER, LOWER, KC_SPC, /**/ KC_ENT,  RAISE,  KM_CSHT,  KC_RALT, KC_RGUI, KC_RCTL
),
[_MODTAP] = LAYOUT(
  QK_GESC, KC_1,    KC_2,    KC_3,   KC_4,  KC_5,   /**/ KC_6,    KC_7,   KC_8,     KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,   /**/ KC_Y,    KC_U,   KC_I,     KC_O,    KC_P,    KC_DEL,
  KC_TAB,  HM_A,    HM_S,    HM_D,   HM_F,  KC_G,   /**/ KC_H,    HM_J,   HM_K,     HM_L,    HM_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,  KC_B,   /**/ KC_N,    KC_M,   KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT, NUMPAD, LOWER, KC_SPC, /**/ KC_ENT,  RAISE,  KM_CSHT,  KC_RALT, KC_RGUI, KC_RCTL
),
/* Lower
 * ,-----------------------------------------+-----------------------------------------.
 * |   ~  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   $  |   %  |   =  |   [  |   ]  |   (  |  F11 | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |Print |   -  |   (  |   )  |   {  |  F12 |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   =  |   {  |   }  | Home |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------+-----------------------------------------'
 */
[_LOWER] = LAYOUT(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   /**/ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  XXXXXXX, KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ KC_EQL,  KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, KC_F12,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, /**/ KC_MINS, KC_LPRN, KC_RPRN, XXXXXXX, KC_PIPE, KC_BSLS,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ KC_EQL,  KC_LCBR, KC_RCBR, XXXXXXX, _______, _______,
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______
),
/* Raise
 * ,-----------------------------------------|-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   _  |   0  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | Pg Up|PrvWrd|  Up  |NxtWrd|      | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      | Pg Dw| Left | Down |Right |      |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy | Paste|      |      | Home |      | End  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------|-----------------------------------------'
 */
[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,      KC_6,    KC_7,    KC_8,    KC_UNDS, KC_0,    KC_BSPC,
  _______, NAV_L4T, NAV_L3T, NAV_L2T, NAV_L1T, NAV_L0T, /**/ NAV_R0T, NAV_R1T, NAV_R2T, NAV_R3T, NAV_R4T, KC_DEL,
  _______, NAV_L4M, NAV_L3M, NAV_L2M, NAV_L1M, NAV_L0M, /**/ NAV_R0M, NAV_R1M, NAV_R2M, NAV_R3M, NAV_R4M, KC_BSLS,
  _______, NAV_L4B, NAV_L3B, NAV_L2B, NAV_L1B, NAV_L0B, /**/ NAV_R0B, NAV_R1B, NAV_R2B, NAV_R3B, NAV_R4B, _______,
  _______, _______, _______, _______, _______, _______,      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Debug| Reset|      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |Aud cy|Aud on|AudOff|AGnorm|AGswap|<Desk |      | Desk>|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT(
  QK_BOOT, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  MODTAP,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
  QWERTY,  _______, _______, _______, _______, _______, _______, KC_PWIN, _______, KC_NWIN, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_NUMPAD] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, /**/ XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, /**/ XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, KC_1,    KC_2,    KC_3,    KC_ENT,  XXXXXXX,
    _______, _______, _______, XXXXXXX, XXXXXXX, _______, /**/ _______, KC_0,    KC_0,    KC_DOT,  KC_ENT,  _______
),

/* Fn (rgblight and backlight layout)
    * ,-----------------------------------------------------------------------------------.
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |RGBVA-|RGBVA+|      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |RGBSA-|RGBSA+|      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |RGBTOG|RGBHU-|RGBHU+|RGBMOD|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |BLTOGG|  BL- |  BL+ |BLBRTG|
    * `-----------------------------------------------------------------------------------'
    */
[_FN] = LAYOUT(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_SAI, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, RGB_HUD, RGB_HUI, RGB_MOD,
    _______, _______, _______, _______, _______, _______, _______, _______, BL_TOGG, BL_DOWN, BL_UP,   BL_BRTG
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case MODTAP:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_MODTAP);
          }
          return false;
          break;
    }
    update_tri_layer(_LOWER, _RAISE, _ADJUST);
    return true;
};

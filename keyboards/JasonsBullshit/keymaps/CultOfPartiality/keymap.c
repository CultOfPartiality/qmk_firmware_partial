/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMPAD,
  _MOUSE
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NUMPAD MO(_NUMPAD)
#define MOUSE MO(_MOUSE)


//Defines for windows desktop changine
#define WD_LEFT C(G(KC_LEFT))
#define WG_RGHT C(G(KC_RGHT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * .---------.-----------------------------------------------------------------------------------.---------.
 * |         | `Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |         |
 * |---------|------+------+------+------+------+------+------+------+------+------+------+------|---------|
 * |         | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |         |
 * |---------|------+------+------+------+------+-------------+------+------+------+------+------|---------|
 * |         |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |         |
 * |---------|------+------+------+------+------+------|------+------+------+------+------+------|---------|
 * |         | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |         |
 * |---------|------+------+------+------+------+------+------+------+------+------+------+------|---------|
 * |         | Ctrl | GUI  | Alt  |      |Lower |Space |Enter |Raise |      |  Alt |  GUI | Ctrl |         |
 * `---------'-----------------------------------------------------------------------------------'---------'
 */
[_QWERTY] = LAYOUT_ortho_5x14(
  KC_GESC, KC_GESC, KC_1,    KC_2,    KC_3,     KC_4,     KC_5,               KC_6,    KC_7,     KC_8,     KC_9,    KC_0,    KC_BSPC, KC_BSPC,
  KC_2,    KC_TAB,  KC_Q,    KC_W,    KC_E,     KC_R,     KC_T,               KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,    KC_DEL,  KC_7,
  KC_3,    KC_TAB,  KC_A,    KC_S,    KC_D,     KC_F,     KC_G,               KC_H,    KC_J,     KC_K,     KC_L,    KC_SCLN, KC_QUOT, KC_8,
  KC_4,    KC_LSFT, KC_Z,    KC_X,    KC_C,     KC_V,     KC_B,               KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT, KC_9,
  KC_LCTL, KC_LCTL, KC_LGUI, KC_LALT, NUMPAD,   LOWER,   KC_SPC,              KC_ENT,  RAISE,    MOUSE,    KC_RALT, KC_RGUI, KC_RCTL, KC_0
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_5x14(
  _______,  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,               KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC, KC_BSPC,
  _______,  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,             KC_EQL,  KC_LBRC, KC_RBRC, KC_LPRN, KC_F11,  KC_DEL,  KC_DEL,
  _______,  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_PSCR, KC_F5,               KC_MINS, KC_LPRN, KC_RPRN, KC_LCBR, KC_F12,  KC_BSLS, KC_BSLS,
  _______,  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,              KC_EQL,  KC_LCBR, KC_RCBR, KC_HOME, _______, _______, _______,
  _______,  _______, _______, _______, XXXXXXX, _______, _______,             _______, _______, XXXXXXX, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |Pg Up |LWord |  UP  |RWord |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |Pg Dn |  LF  |  DN  |  RT  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | Home |ISO / | End  |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_5x14(
  _______,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                KC_6,    KC_7,       KC_8,    KC_UNDS,    KC_0,    KC_BSPC,  _______,
  _______,  _______, _______, _______, _______, _______, _______,             KC_PGUP, C(KC_LEFT), KC_UP,   C(KC_RGHT), KC_0,    KC_DEL,   _______,
  _______,  _______, _______, _______, _______, _______, _______,             KC_PGDN, KC_LEFT,    KC_DOWN, KC_RGHT,    KC_RBRC, KC_BSLS,  _______,
  _______,  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), _______,             _______, KC_HOME,    XXXXXXX, KC_END,     KC_PGDN, _______,  _______,
  _______,  _______, _______, _______, XXXXXXX, _______, _______,             _______, _______,    XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,  _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_5x14(
    _______, RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______,
    _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, KC_F12,  _______,
    _______, _______, _______, _______, _______, _______, _______,            _______, WD_LEFT, _______, WG_RGHT, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, XXXXXXX, _______, _______,            _______, _______, XXXXXXX, _______, _______, _______, _______
),

/* Num Pad Layer
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_ortho_5x14(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX,            XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,            XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, KC_1,    KC_2,    KC_3,    KC_ENT,  XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, XXXXXXX, _______,            _______, KC_0,    KC_0,    KC_DOT,  KC_ENT,  _______, _______
),

/* Mouse layer
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_ortho_5x14(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, KC_WH_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,            XXXXXXX, KC_BTN1, KC_BTN3, KC_BTN2, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, C(KC_X), C(KC_C), C(KC_V), XXXXXXX,            XXXXXXX, XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, _______,            _______, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
  }
  return true;
}


bool encoder_update_user(uint8_t index, bool clockwise) {
  {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    return true;
}

void matrix_scan_user(void) {

}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

//Combos: Lets give this a whirl
const uint16_t PROGMEM combo_addDelete[] = {KC_P, KC_BSPC, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_addDelete, KC_DEL)
};

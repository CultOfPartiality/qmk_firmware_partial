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
#include "layerdefines.h"
#include "muse.h"
#include "tapdance.h"


enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  MODTAP,
  LOWER,
  RAISE,
  BACKLIT
};

//Define homerow mod shorthands
#define HM_A    LGUI_T(KC_A)
#define HM_S    LALT_T(KC_S)
#define HM_D    LCTL_T(KC_D)
#define HM_F    LSFT_T(KC_F)
#define HM_SCLN RGUI_T(KC_SCLN)
#define HM_L    RALT_T(KC_L)
#define HM_K    RCTL_T(KC_K)
#define HM_J    RSFT_T(KC_J)

//Defines for windows desktop changine
#define WD_LEFT C(G(KC_LEFT))
#define WG_RGHT C(G(KC_RGHT)),


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | `Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |      |Lower |Space |Enter |Raise |      |  Alt |  GUI | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_5x12(
  KC_GESC, KC_1,    KC_2,    KC_3,         KC_4,         KC_5,    KC_6,    KC_7,         KC_8,         KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,         KC_R,         KC_T,    KC_Y,    KC_U,         KC_I,         KC_O,    KC_P,    KC_DEL,
  KC_TAB,  KC_A,    KC_S,    KC_D,         KC_F,         KC_G,    KC_H,    KC_J,         KC_K,         KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,         KC_V,         KC_B,    KC_N,    KC_M,         KC_COMM,      KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT, TD(TD_LOWER), TD(TD_LOWER), KC_SPC,  KC_ENT,  TD(TD_RAISE), TD(TD_RAISE), KC_RALT, KC_RGUI, KC_RCTL
),

/* Qwerty (with homerow mods)
 * ,-----------------------------------------------------------------------------------.
 * | `Esc |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |      |Lower |Space |Enter |Raise |      |  Alt |  GUI | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_MODTAP] = LAYOUT_ortho_5x12(
  KC_GESC, KC_1,    KC_2,    KC_3,         KC_4,         KC_5,    KC_6,   KC_7,         KC_8,         KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,         KC_R,         KC_T,    KC_Y,   KC_U,         KC_I,         KC_O,    KC_P,    KC_DEL,
  KC_TAB,  HM_A,    HM_S,    HM_D,         HM_F,         KC_G,    KC_H,   HM_J,         HM_K,         HM_L,    HM_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,         KC_V,         KC_B,    KC_N,   KC_M,         KC_COMM,      KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT, TD(TD_LOWER), TD(TD_LOWER), KC_SPC,  KC_ENT, TD(TD_RAISE), TD(TD_RAISE), KC_RALT, KC_RGUI, KC_RCTL
),

/* Lower
 * ,-----------------------------------------+-----------------------------------------.
 * |   ~  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   =  |   [  |   ]  |   (  |  F11 | Del  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Del  |      |      |      |      |      |   -  |   (  |   )  |   {  |  F12 |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   {  |   }  | Home |  \   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------+-----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_5x12(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_EQL,  KC_LBRC, KC_RBRC, KC_LPRN, KC_F11,  KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_MINS, KC_LPRN, KC_RPRN, KC_LCBR, KC_F12,  KC_PIPE,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LCBR, KC_RCBR, KC_HOME, KC_BSLS, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_5x12(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,       KC_8,    KC_UNDS,    KC_0,    KC_BSPC,
  _______, _______, _______, _______, _______, _______, KC_PGUP, C(KC_LEFT), KC_UP,   C(KC_RGHT), KC_0,    KC_DEL,
  _______, _______, _______, _______, _______, _______, KC_PGDN, KC_LEFT,    KC_DOWN, KC_RGHT,    KC_RBRC, KC_BSLS,
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), _______, _______,  KC_HOME,   XXXXXXX, KC_END,     KC_PGDN, _______,
  _______, _______, _______, _______, _______, _______, _______, _______,    XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX
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
[_ADJUST] = LAYOUT_ortho_5x12(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  MODTAP,  _______, DEBUG,   _______, RESET,   _______, _______, _______, _______, _______, _______, KC_DEL,
  QWERTY,  _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, WD_LEFT, _______, WG_RGHT, _______, _______,
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

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
       /*  case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break; */
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef RGBLIGHT_ENABLE
              rgblight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
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

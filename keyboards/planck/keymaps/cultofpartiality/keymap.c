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

#ifndef ZOMBIE_PLANCK
    #include "muse.h"
#endif

// Userspace
#include "cultofpartiality.h"
// Allows for multi-key definition macros for the keymap in userspace
#define LAYOUT_planck_grid_wrapper(...)   LAYOUT_planck_grid(__VA_ARGS__)

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NUMBERS,
  _ADJUST,
  _NUMPAD,
  _MOUSE
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT
};

//Layer defines
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NUMPAD MO(_NUMPAD)
#define RAISE2 LT(_NUMBERS,KC_ENT)
#define LOWER2 LT(_NUMBERS,KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | `ESC |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |Numpad|Lower |Space |Enter |Raise |CtlShf| Alt  | GUI  | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    QK_GESC, KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   /**/ KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   /**/ KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   /**/ KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, NUMPAD,  LOWER,  LOWER2, /**/ RAISE2,  RAISE,    KM_CSHT, KC_RALT, KC_RGUI, KC_RCTL
),

/* Lower - Symbols
 *      Attempting to standardise this layout here, then will move to userspace
 * ,-----------------------------------------------------------------------------------.
 * |   `  |  1/! |  2/@ |  3/# |  4/$ |  5/% |  6/^ |   [  |   ]  |  9/( |  0/) |______|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |______|  F1  |  F2  |  F3  |  F4  |  F5  |   -  |   (  |   )  |      |   |  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |______|  F7  |  F8  |  F9  |  F10 |  F11 |      |   [  |   ]  |______|______|______|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |______|______|______|______| LAYER|______|______|______|______|______|______|______|
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_GRV,  _SPARE_, _SPARE_, _SPARE_, _SPARE_, /**/ KC_EQL,  KC_LBRC, KC_RBRC, _SPARE_, _SPARE_, _______,
    _______, _SPARE_, _SPARE_, _SPARE_, _SPARE_, KC_PSCR, /**/ KC_MINS, KC_LPRN, KC_RPRN, _SPARE_, KC_PIPE, KC_BSLS,
    _______, _SPARE_, _SPARE_, _SPARE_, _SPARE_, _SPARE_, /**/ _SPARE_, _SPARE_, _SPARE_, _SPARE_, _SPARE_, _______,
    _______, _______, _______, XXXXXXX, _______, KC_SPC,  /**/ KC_ENT,  _______, _______, _______, _______, _______
),

/* Raise - Navigation
 *      Standardised easy-access keys from userspace to keep all boards in sync
 * ,-----------------------------------------------------------------------------------.
 * |      |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |  STD |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | LAYER|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, _______________NAV_LEFT_TOP________________, /**/ _______________NAV_RIGHT_TOP_______________, _______,
    XXXXXXX, _______________NAV_LEFT_MID________________, /**/ _______________NAV_RIGHT_MID_______________, _______,
    _______, _______________NAV_LEFT_BOT________________, /**/ _______________NAV_RIGHT_BOT_______________, _______,
    _______, _______, _______, XXXXXXX, _______, _______, /**/ _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |Reset |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |PrvWin|      |NxtWin|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   /**/ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, _______, _______, _______, _______, _______, /**/ _______, KC_PWIN, _______, KC_NWIN, _______, KC_F12,
    _______, _______, _______, _______, _______, _______, /**/ _______, _______, _______, _______, _______, _______,
    _______, _______, _______, XXXXXXX, _______, _______, /**/ _______, _______, _______, _______, _______, _______
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
[_NUMPAD] = LAYOUT_planck_grid(
    XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, /**/ XXXXXXX, KC_7, KC_8, KC_9,   XXXXXXX, KC_BSPC,
    XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, /**/ XXXXXXX, KC_4, KC_5, KC_6,   XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ XXXXXXX, KC_1, KC_2, KC_3,   KC_ENT,  XXXXXXX,
    _______, _______, _______, NUMPAD,  XXXXXXX, _______, /**/ _______, KC_0, KC_0, KC_DOT, KC_ENT,  _______
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case QWERTY:
    //   if (record->event.pressed) {
    //     print("mode just switched to qwerty and this is a huge string\n");
    //     set_single_persistent_default_layer(_QWERTY);
    //   }
    //   return false;
    //   break;
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
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
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

//Combos: Lets give this a whirl
const uint16_t PROGMEM combo_addDelete[] = {KC_P, KC_BSPC, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_addDelete, KC_DEL)
};

#ifndef ZOMBIE_PLANCK
void keyboard_post_init_user(void){
    //Start with LEDs off
    rgblight_setrgb(0,0,0);
}
#endif

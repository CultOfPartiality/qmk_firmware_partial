

#include QMK_KEYBOARD_H

// Userspace
#include "cultofpartiality.h"

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUMPAD
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NUMPAD MO(_NUMPAD)


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
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   /**/ _______, _______, /**/ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   /**/ _______, _______, /**/ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   /**/ _______, _______, /**/ KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   /**/ _______, _______, /**/ KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT, NUMPAD,  LOWER,   KC_SPC, /**/ _______, _______, /**/ KC_ENT,  RAISE,   RAISE,   KC_RALT, KC_RGUI, KC_RCTL
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
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   /**/ _______, _______, /**/ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, /**/ _______, _______, /**/ KC_EQL,  KC_LBRC, KC_RBRC, KC_LPRN, KC_F11,  KC_DEL,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_PSCR, KC_F5,   /**/ _______, _______, /**/ KC_MINS, KC_LPRN, KC_RPRN, KC_LCBR, KC_PIPE, KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  /**/ _______, _______, /**/ KC_EQL,  KC_LCBR, KC_RCBR, KC_HOME, _______, _______,
  _______, _______, _______, XXXXXXX, _______, _______, /**/ _______, _______, /**/ _______, _______, XXXXXXX, _______, _______, _______
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
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    /**/ _______, _______, /**/ KC_6,    KC_7,    KC_8,    KC_UNDS, KC_0,    KC_BSPC,
  _______, NAV_L4T, NAV_L3T, NAV_L2T, NAV_L1T, NAV_L0T, /**/ _______, _______, /**/ NAV_R0T, NAV_R1T, NAV_R2T, NAV_R3T, NAV_R4T, KC_DEL,
  _______, NAV_L4M, NAV_L3M, NAV_L2M, NAV_L1M, NAV_L0M, /**/ _______, _______, /**/ NAV_R0M, NAV_R1M, NAV_R2M, NAV_R3M, NAV_R4M, KC_BSLS,
  _______, NAV_L4B, NAV_L3B, NAV_L2B, NAV_L1B, NAV_L0B, /**/ _______, _______, /**/ NAV_R0B, NAV_R1B, NAV_R2B, NAV_R3B, NAV_R4B, _______,
  _______, _______, _______, XXXXXXX, _______, _______, /**/ _______, _______, /**/ _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
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
  RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   /**/ _______, _______, /**/ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, /**/ _______, _______, _______, _______, _______, KC_F12,
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, /**/ _______, KC_PWIN, _______, KC_NWIN, _______, _______,
  _______, _______, _______, _______, _______, _______, /**/ _______, _______, /**/ _______, _______, _______, _______, _______, _______,
  _______, _______, _______, XXXXXXX, _______, _______, /**/ _______, _______, /**/ _______, _______, XXXXXXX, _______, _______, _______
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
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ _______, _______, /**/ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, /**/ _______, _______, /**/ XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, /**/ _______, _______, /**/ XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, /**/ _______, _______, /**/ XXXXXXX, KC_1,    KC_2,    KC_3,    KC_ENT,  XXXXXXX,
  _______, _______, _______, _______, XXXXXXX, _______, /**/ _______, _______, /**/ _______, KC_0,    KC_0,    KC_DOT,  KC_ENT,  _______
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

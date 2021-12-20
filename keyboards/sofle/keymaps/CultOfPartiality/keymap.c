#include QMK_KEYBOARD_H

#include "defines.h"
#include "tapdance.h"




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * NORMAL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |Space | /Lower  /       \RAISE \  |ENTER | RCTR |  -   |  =   |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_NORMAL] = LAYOUT( \
  KC_GESC,  KC_1,  KC_2,    KC_3,    KC_4,     KC_5,                                   KC_6,   KC_7,     KC_8,    KC_9,   KC_0,    KC_BSPC, \
  KC_TAB,   KC_Q,  KC_W,    KC_E,    KC_R,     KC_T,                                   KC_Y,   KC_U,     KC_I,    KC_O,   KC_P,    KC_DEL,  \
  KC_TAB,   KC_A,  KC_S,    KC_D,    KC_F,     KC_G,                                   KC_H,   KC_J,     KC_K,    KC_L,   KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,  KC_X,    KC_C,    KC_V,     KC_B,   KC_MUTE,          XXXXXXX,      KC_N,   KC_M,     KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, \
                   KC_LGUI, KC_LALT, KC_LCTRL, KC_SPC, TD(TD_LOWER),     TD(TD_RAISE), KC_ENT, KC_RCTRL, KC_MINS, KC_EQL \
),
/*
 * NORMAL with homerow mods
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |Space | /Lower  /       \RAISE \  |ENTER | RCTR |  -   |  =   |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_MODTAP] = LAYOUT( \
  KC_GESC,  KC_1,          KC_2,         KC_3,         KC_4,         KC_5,                                   KC_6,   KC_7,         KC_8,         KC_9,         KC_0,            KC_BSPC, \
  KC_TAB,   KC_Q,          KC_W,         KC_E,         KC_R,         KC_T,                                   KC_Y,   KC_U,         KC_I,         KC_O,         KC_P,            KC_DEL,  \
  KC_TAB,   LGUI_T(KC_A),  LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G,                                   KC_H,   LSFT_T(KC_J), LCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN), KC_QUOT, \
  KC_LSFT,  KC_Z,          KC_X,         KC_C,         KC_V,         KC_B,   KC_MUTE,          XXXXXXX,      KC_N,   KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RSFT, \
                           KC_LGUI,      KC_LALT,      KC_LCTRL,     KC_SPC, TD(TD_LOWER),     TD(TD_RAISE), KC_ENT, KC_RCTRL,     KC_MINS,      KC_EQL \
),

/*
 * Normal with modtap
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |Space | /Lower  /       \RAISE \  |ENTER | RCTR |  -   |  =   |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

/* [_MODTAP] = LAYOUT( \
  KC_GESC,  KC_1,         KC_2,        KC_3,        KC_4,        KC_5,                                        KC_6,        KC_7,        KC_8,        KC_9,        KC_0,        KC_BSPC, \
  KC_TAB,   TD(TD_KC_Q),  TD(TD_KC_W), TD(TD_KC_E), TD(TD_KC_R), TD(TD_KC_T),                                 TD(TD_KC_Y), TD(TD_KC_U), TD(TD_KC_I), TD(TD_KC_O), TD(TD_KC_P), KC_DEL,  \
  KC_TAB,   TD(TD_KC_A),  TD(TD_KC_S), TD(TD_KC_D), TD(TD_KC_F), TD(TD_KC_G),                                 TD(TD_KC_H), TD(TD_KC_J), TD(TD_KC_K), TD(TD_KC_L), KC_SCLN,     KC_QUOT, \
  KC_LSFT,  TD(TD_KC_Z),  TD(TD_KC_X), TD(TD_KC_C), TD(TD_KC_V), TD(TD_KC_B), KC_MUTE,          XXXXXXX,      TD(TD_KC_N), TD(TD_KC_M), KC_COMM,     KC_DOT,      KC_SLSH,     KC_RSFT, \
                          KC_LGUI,     KC_LALT,     KC_LCTRL,    KC_SPC,      TD(TD_LOWER),     TD(TD_RAISE), KC_ENT,      KC_RCTRL,    KC_MINS,     KC_EQL \
), */

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |      |      |      |      |      |                    |      |   [  |   ]  |      |      | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|      |   (  |   )  |      |      |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|      |   {  |   }  |      |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
  KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, KC_F12,  \
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                          XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, KC_PIPE, \
  _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______,        _______, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, KC_BSLS, _______, \
                   _______, _______, TT(_MOUSE), _______, _______,      _______, _______, _______, _______, _______\
),
/* RAISE
 * ,----------------------------------------.                     ,-----------------------------------------.
 * | Esc  |      |      |      |      |      |                    |      |      |      |  _   |      | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| DEL  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                           _______,  _______  , _______,  KC_UNDS ,  _______ ,KC_BSPC, \
  _______, KC_INS,  KC_PSCR, KC_APP,  XXXXXXX, XXXXXXX,                        KC_PGUP, KC_PRVWD,   KC_UP, KC_NXTWD,KC_DLINE, KC_DEL, \
  _______, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, KC_CAPS,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, _______, \
  _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), XXXXXXX,  _______,       _______,  XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,   XXXXXXX, _______, \
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |QWERTY|      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      |desk <|      |desk >|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX , XXXXXXX,  XXXXXXX , XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  KC_MODTAP  ,  XXXXXXX, KC_NORMAL, XXXXXXX,  XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  KC_NORMAL , XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,                     XXXXXXX, C(G(KC_LEFT)), KC_MUTE, C(G(KC_RGHT)), XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______ \
),
/* MOUSE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */
  [_MOUSE] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,                     KC_WH_U, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,                     KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX , XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                    _______, _______, TG(_MOUSE), _______ , _______,   XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX \
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	//As I'm using the in-built macros(?) for changing layers, I've moved this here
	update_tri_layer(_LOWER, _RAISE, _ADJUST);
    /* if (IS_LAYER_ON(_ADJUST)){
		reset_oneshot_layer();
	}; */
	switch (keycode) {
        case KC_NORMAL:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_NORMAL);
            }
            return false;
		case KC_MODTAP:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MODTAP);
            }
            return false;
        /* case KC_LOWER:
            if (record->event.pressed) {
                //layer_on(_LOWER);
				set_oneshot_layer(_LOWER, ONESHOT_START);
            } else {
                //layer_off(_LOWER);
            }
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
            return false; */
		/* case KC_MOUSE:
            if (record->event.pressed) {
                layer_on(_MOUSE);
            } else {
                layer_off(_MOUSE);
            }
            return false; */
        /* case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
            } else {
                layer_off(_RAISE);
            }
			update_tri_layer(_LOWER, _RAISE, _ADJUST);
            return false; */
        /* case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false; */
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        /* case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false; */
    }
    return true;
}



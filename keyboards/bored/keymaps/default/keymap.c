#include QMK_KEYBOARD_H

// Allows for multi-key definition macros for the keymap in userspace
#define LAYOUT_bored_grid_wrapper(...)   LAYOUT_ortho_5x14(__VA_ARGS__)


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
    QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    /**/ _______, _______, /**/ KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    /**/ KC_PSCR, QK_BOOT, /**/ KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    /**/ KC_DEL,  _______, /**/ KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    /**/ KC_F5,   _______, /**/ KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT, _______, _______, NUM_SPC, /**/ KC_ENT,  KC_BSPC, /**/ KC_ENT, _______, _______, KC_RALT, KC_RGUI, KC_RCTL
    ),


};

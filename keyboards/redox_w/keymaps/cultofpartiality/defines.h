#pragma once

// Each layer gets a name for readability, in an enum to ensure unique numbering
enum layer_names{
    _QWERTY,
    _QWERTY_MOD,
    _SYMB,
    _NAV,
    _ADJUST,
    _NUMPAD,
    _SETTINGS

};

// Custom keycodes
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  MOD_ENA,
  MOD_DIS
};

/* Shortcuts to make keymap more readable */

//Layer changes
#define SYM_L   MO(_SYMB)
#define NAV_L   MO(_NAV)
#define SET_L   MO(_SETTINGS)
#define NUM_L   MO(_NUMPAD)

//Homerow mods
#define HM_A    LGUI_T(KC_A)
#define HM_S    LALT_T(KC_S)
#define HM_D    LCTL_T(KC_D)
#define HM_F    LSFT_T(KC_F)
#define HM_SCLN RGUI_T(KC_SCLN)
#define HM_L    RALT_T(KC_L)
#define HM_K    RCTL_T(KC_K)
#define HM_J    RSFT_T(KC_J)

#define KC_ALAS LALT_T(KC_PAST)
#define KC_CTPL LCTL_T(KC_BSLS)

#define KC_NAGR LT(_NAV, KC_GRV)
#define KC_NAMI LT(_NAV, KC_MINS)

#define KC_ADEN LT(_ADJUST, KC_END)
#define KC_ADPU LT(_ADJUST, KC_PGUP)

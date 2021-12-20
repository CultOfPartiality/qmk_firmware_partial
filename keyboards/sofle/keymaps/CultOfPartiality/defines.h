#pragma once

#include "quantum.h"
#include "action.h"
#include "version.h"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _NORMAL,
	_MODTAP,
    _LOWER,
    _RAISE,
    _ADJUST,
	_MOUSE
};

enum custom_keycodes {
    KC_NORMAL = SAFE_RANGE,
	KC_MODTAP,
	KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
	KC_MOUSE, 
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
};
#pragma once

#include "quantum.h"
#include "action.h"
#include "version.h"

// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
	TD_DOUBLE_HOLD,
	TD_TRIPLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
	int layer;
	int keycode;
} td_tap_t;

// Tap dance "keys"
enum td_keycodes {
	TD_LOWER,
	TD_RAISE,
	TD_KC_A,
	TD_KC_B,
	TD_KC_C,
	TD_KC_D,
	TD_KC_E,
	TD_KC_F,
	TD_KC_G,
	TD_KC_H,
	TD_KC_I,
	TD_KC_J,
	TD_KC_K,
	TD_KC_L,
	TD_KC_M,
	TD_KC_N,
	TD_KC_O,
	TD_KC_P,
	TD_KC_Q,
	TD_KC_R,
	TD_KC_S,
	TD_KC_T,
	TD_KC_U,
	TD_KC_V,
	TD_KC_W,
	TD_KC_X,
	TD_KC_Y,
	TD_KC_Z
};

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void td_layer_key_finished(qk_tap_dance_state_t *state, void *user_data);
void td_layer_key_reset(qk_tap_dance_state_t *state, void *user_data);
void td_alpha_key_finished(qk_tap_dance_state_t *state, void *user_data);
void td_alpha_key_reset(qk_tap_dance_state_t *state, void *user_data);
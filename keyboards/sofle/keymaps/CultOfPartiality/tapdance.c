#include "tapdance.h"
#include QMK_KEYBOARD_H
#include "defines.h"

/////////////////////
//tap dance stuff
/////////////////////

// Initialize tap structure associated with tap dance keys
static td_tap_t raise_tap_state = {
    .is_press_action = true,
    .state = TD_NONE,
	.layer = _RAISE
};
static td_tap_t lower_tap_state = {
    .is_press_action = true,
    .state = TD_NONE,
	.layer = _LOWER
};

// static td_tap_t td_tap_TD_KC_A = {.is_press_action = true,.state = TD_NONE,.keycode = KC_A};
// static td_tap_t td_tap_TD_KC_B = {.is_press_action = true,.state = TD_NONE,.keycode = KC_B};
// static td_tap_t td_tap_TD_KC_C = {.is_press_action = true,.state = TD_NONE,.keycode = KC_C};
// static td_tap_t td_tap_TD_KC_D = {.is_press_action = true,.state = TD_NONE,.keycode = KC_D};
// static td_tap_t td_tap_TD_KC_E = {.is_press_action = true,.state = TD_NONE,.keycode = KC_E};
// static td_tap_t td_tap_TD_KC_F = {.is_press_action = true,.state = TD_NONE,.keycode = KC_F};
// static td_tap_t td_tap_TD_KC_G = {.is_press_action = true,.state = TD_NONE,.keycode = KC_G};
// static td_tap_t td_tap_TD_KC_H = {.is_press_action = true,.state = TD_NONE,.keycode = KC_H};
// static td_tap_t td_tap_TD_KC_I = {.is_press_action = true,.state = TD_NONE,.keycode = KC_I};
// static td_tap_t td_tap_TD_KC_J = {.is_press_action = true,.state = TD_NONE,.keycode = KC_J};
// static td_tap_t td_tap_TD_KC_K = {.is_press_action = true,.state = TD_NONE,.keycode = KC_K};
// static td_tap_t td_tap_TD_KC_L = {.is_press_action = true,.state = TD_NONE,.keycode = KC_L};
// static td_tap_t td_tap_TD_KC_M = {.is_press_action = true,.state = TD_NONE,.keycode = KC_M};
// static td_tap_t td_tap_TD_KC_N = {.is_press_action = true,.state = TD_NONE,.keycode = KC_N};
// static td_tap_t td_tap_TD_KC_O = {.is_press_action = true,.state = TD_NONE,.keycode = KC_O};
// static td_tap_t td_tap_TD_KC_P = {.is_press_action = true,.state = TD_NONE,.keycode = KC_P};
// static td_tap_t td_tap_TD_KC_Q = {.is_press_action = true,.state = TD_NONE,.keycode = KC_Q};
// static td_tap_t td_tap_TD_KC_R = {.is_press_action = true,.state = TD_NONE,.keycode = KC_R};
// static td_tap_t td_tap_TD_KC_S = {.is_press_action = true,.state = TD_NONE,.keycode = KC_S};
// static td_tap_t td_tap_TD_KC_T = {.is_press_action = true,.state = TD_NONE,.keycode = KC_T};
// static td_tap_t td_tap_TD_KC_U = {.is_press_action = true,.state = TD_NONE,.keycode = KC_U};
// static td_tap_t td_tap_TD_KC_V = {.is_press_action = true,.state = TD_NONE,.keycode = KC_V};
// static td_tap_t td_tap_TD_KC_W = {.is_press_action = true,.state = TD_NONE,.keycode = KC_W};
// static td_tap_t td_tap_TD_KC_X = {.is_press_action = true,.state = TD_NONE,.keycode = KC_X};
// static td_tap_t td_tap_TD_KC_Y = {.is_press_action = true,.state = TD_NONE,.keycode = KC_Y};
// static td_tap_t td_tap_TD_KC_Z = {.is_press_action = true,.state = TD_NONE,.keycode = KC_Z};



// Determine the current tap dance state
// td_state_t cur_dance(qk_tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
//         else return TD_SINGLE_HOLD;
//     } else if (state->count == 2){
// 		if (state->interrupted || !state->pressed) return TD_DOUBLE_TAP;
//         else return TD_DOUBLE_HOLD;
// 	} else if (state->count == 3)
// 		return TD_TRIPLE_TAP;
//     else return TD_UNKNOWN;
// }

// Determine the current tap dance state
td_state_t cur_dance_layer(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2){
		if (!state->pressed) return TD_DOUBLE_TAP;
		else return TD_UNKNOWN;
	}
    else return TD_UNKNOWN;
}


void td_layer_key_finished(qk_tap_dance_state_t *state, void *user_data){
	//The specific layer is stored in the user data
	td_tap_t* TapDanceData = (td_tap_t *)user_data;
	TapDanceData->state = cur_dance_layer(state);
    switch (TapDanceData->state) {
        case TD_SINGLE_TAP:
            set_oneshot_layer(TapDanceData->layer,ONESHOT_START);
            break;
        case TD_SINGLE_HOLD:
            layer_on(TapDanceData->layer);
            break;
        case TD_DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(TapDanceData->layer)) {
                // If already set, then switch it off
                layer_off(TapDanceData->layer);
            } else {
                // If not already set, then switch the layer on
                layer_on(TapDanceData->layer);
            }
            break;
        default:
            break;
    }
	update_tri_layer(_LOWER, _RAISE, _ADJUST);
}

void td_layer_key_reset(qk_tap_dance_state_t *state, void *user_data) {
	//The specific layer is stored in the user data
	td_tap_t* TapDanceData = (td_tap_t *)user_data;
    // If the key was held down and now is released then switch off the layer
    switch(TapDanceData->state){
		case TD_SINGLE_TAP:
			clear_oneshot_layer_state(ONESHOT_PRESSED);
			break;
		case TD_SINGLE_HOLD:
			layer_off(TapDanceData->layer);
			break;
		default:
            break;
    }
    TapDanceData->state = TD_NONE;
	update_tri_layer(_LOWER, _RAISE, _ADJUST);
}

// void td_alpha_key_finished(qk_tap_dance_state_t *state, void *user_data){
// 	td_tap_t* TapDanceData = (td_tap_t *)user_data;
// 	TapDanceData->state = cur_dance(state);
//     switch (TapDanceData->state) {
//         case TD_SINGLE_TAP:
//             register_code(TapDanceData->keycode);
//             break;
//         case TD_SINGLE_HOLD:
// 			register_code(TapDanceData->keycode);
//             break;
//         case TD_DOUBLE_TAP:
// 			//fire a single ctrl-<keycode>
//             tap_code16(TapDanceData->keycode);
// 			register_code(TapDanceData->keycode);
// 			break;
// 		case TD_DOUBLE_HOLD:
// 			//fire a single ctrl-<keycode>
//             tap_code16(C(TapDanceData->keycode));
// 			break;
// 		case TD_TRIPLE_TAP:
//             tap_code16(TapDanceData->keycode);
// 			tap_code16(TapDanceData->keycode);
// 			register_code(TapDanceData->keycode);
// 			break;
//         default:
//             break;
//     }
// }

// void td_alpha_key_reset(qk_tap_dance_state_t *state, void *user_data) {
// 	td_tap_t* TapDanceData = (td_tap_t *)user_data;
//     switch(TapDanceData->state){
// 		case TD_SINGLE_TAP:
// 			unregister_code(TapDanceData->keycode);
// 			break;
// 		case TD_SINGLE_HOLD:
// 			unregister_code(TapDanceData->keycode);
// 			break;
// 		case TD_DOUBLE_TAP:
// 			unregister_code(TapDanceData->keycode);
// 			break;
// 		case TD_DOUBLE_HOLD:
// 			break;
// 		case TD_TRIPLE_TAP:
// 			unregister_code(TapDanceData->keycode);
// 			break;
// 		default:
//             break;
//     }
//     TapDanceData->state = TD_NONE;
// }


#define ACTION_TAP_DANCE_LAYER_CONTROL(td_tap_t_layer){ \
			.fn = {NULL, td_layer_key_finished, td_layer_key_reset},\
			.user_data = (void *)&(td_tap_t_layer),\
			.custom_tapping_term = 150\
		}

#define ACTION_TAP_DANCE_ALPHA(td_tap_t_alpha){ \
			.fn = {NULL, td_alpha_key_finished, td_alpha_key_reset},\
			.user_data = (void *)&(td_tap_t_alpha),\
			.custom_tapping_term = 185\
		}

// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
	//Layer control
	[TD_RAISE] = ACTION_TAP_DANCE_LAYER_CONTROL(raise_tap_state),
	[TD_LOWER] = ACTION_TAP_DANCE_LAYER_CONTROL(lower_tap_state),
	//Alpha keys with control
	// [TD_KC_A] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_A),
	// [TD_KC_B] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_B),
	// [TD_KC_C] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_C),
	// [TD_KC_D] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_D),
	// [TD_KC_E] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_E),
	// [TD_KC_F] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_F),
	// [TD_KC_G] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_G),
	// [TD_KC_H] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_H),
	// [TD_KC_I] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_I),
	// [TD_KC_J] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_J),
	// [TD_KC_K] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_K),
	// [TD_KC_L] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_L),
	// [TD_KC_M] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_M),
	// [TD_KC_N] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_N),
	// [TD_KC_O] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_O),
	// [TD_KC_P] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_P),
	// [TD_KC_Q] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_Q),
	// [TD_KC_R] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_R),
	// [TD_KC_S] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_S),
	// [TD_KC_T] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_T),
	// [TD_KC_U] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_U),
	// [TD_KC_V] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_V),
	// [TD_KC_W] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_W),
	// [TD_KC_X] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_X),
	// [TD_KC_Y] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_Y),
	// [TD_KC_Z] = ACTION_TAP_DANCE_ALPHA(td_tap_TD_KC_Z),
};

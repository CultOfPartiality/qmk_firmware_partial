#pragma once


#define GRAVE_ESC_CTRL_OVERRIDE

#undef  TAPPING_TERM // Remove the default vaule set in the sofle keymap
#define TAPPING_TERM 200

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

#define MK_KINETIC_SPEED
#define MOUSEKEY_INTERVAL 16            //ms between cursor movements
#define MOUSEKEY_INITIAL_SPEED 105
#define MOUSEKEY_MOVE_DELTA 9          //Speed step size
#define MOUSEKEY_ACCELERATED_SPEED 1600 //?
#define MOUSEKEY_BASE_SPEED 1800        //Max speed at which acceleration stops

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

#define COMBO_TERM 20
#define COMBO_STRICT_TIMER

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
#define MOUSEKEY_INITIAL_SPEED 0
#define MOUSEKEY_MOVE_DELTA 0.4         //Speed step size
#define MOUSEKEY_ACCELERATED_SPEED 3000 //?
#define MOUSEKEY_BASE_SPEED 12000       //Max speed at which acceleration stops

#define MOUSEKEY_MAX_SPEED 30

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

#define COMBO_TERM 20
#define COMBO_STRICT_TIMER

#pragma once

//Allow Control Escape to work
#define GRAVE_ESC_CTRL_OVERRIDE

//Mouse Keys Configuration
#define MK_KINETIC_SPEED
#define MOUSEKEY_INTERVAL           16      //ms between cursor movements
#define MOUSEKEY_INITIAL_SPEED      100
#define MOUSEKEY_MOVE_DELTA         7       //Speed step size
#define MOUSEKEY_ACCELERATED_SPEED  1400    //?
#define MOUSEKEY_BASE_SPEED         1600    //Max speed at which acceleration stops


// Prevent normal rollover on alphas from accidentally triggering mods.
//#define IGNORE_MOD_TAP_INTERRUPT //No longer required (default behaviour)
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

//Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP


//Caps Word - Single word capslock.
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

//#define COMBO_COUNT 1
#define COMBO_TERM 20
#define COMBO_STRICT_TIMER

// Remove the default tapping term
#undef  TAPPING_TERM
#define TAPPING_TERM 170




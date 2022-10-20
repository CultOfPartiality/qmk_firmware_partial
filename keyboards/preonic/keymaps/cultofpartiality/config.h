/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#ifdef AUDIO_ENABLE
#    define STARTUP_SONG SONG(PREONIC_SOUND)
// #define STARTUP_SONG SONG(NO_SOUND)

#    define DEFAULT_LAYER_SONGS \
        { SONG(QWERTY_SOUND), SONG(COLEMAK_SOUND), SONG(DVORAK_SOUND) }
#endif

#define MUSIC_MASK (keycode != KC_NO)

#define MIDI_BASIC

#define GRAVE_ESC_CTRL_OVERRIDE

#define TAPPING_TOGGLE 1
#undef  TAPPING_TERM // Remove the default vaule set in the sofle keymap
#define TAPPING_TERM 200

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

//Caps Word - Single word capslock.
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define MK_KINETIC_SPEED
#define MOUSEKEY_INTERVAL 16            //ms between cursor movements
#define MOUSEKEY_INITIAL_SPEED 105
#define MOUSEKEY_MOVE_DELTA 9          //Speed step size
#define MOUSEKEY_ACCELERATED_SPEED 1600 //?
#define MOUSEKEY_BASE_SPEED 1800        //Max speed at which acceleration stops

#define ONESHOT_TAP_TOGGLE 5
#define ONESHOT_TIMEOUT 3000

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

//#define COMBO_TERM 20
//#define COMBO_STRICT_TIMER

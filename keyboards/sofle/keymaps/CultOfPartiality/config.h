#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

#define MASTER_RIGHT

#define GRAVE_ESC_CTRL_OVERRIDE

#define TAPPING_TOGGLE 1
#undef TAPPING_TERM // Remove the default vaule set in the sofle keymap
#define TAPPING_TERM 150

#define ONESHOT_TAP_TOGGLE 5
#define ONESHOT_TIMEOUT 3000

#define MK_KINETIC_SPEED
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_INITIAL_SPEED 3
#define MOUSEKEY_MOVE_DELTA 2
#define MOUSEKEY_ACCELERATED_SPEED 80

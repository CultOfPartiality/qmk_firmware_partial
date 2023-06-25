#pragma once

#include "quantum.h"


/*  Keycode Defines - For Simplifing Layout  */

//Keys with modifier: Control
#define KC_CLFT C(KC_LEFT)
#define KC_CRHT C(KC_RIGHT)
#define KM_CSHT C(KC_LSFT)
#define KM_CUT  C(KC_X)
#define KM_COPY C(KC_C)
#define KM_PAST C(KC_V)

//Keys with modifiers: GUI and Control
#define KC_PWIN C(G(KC_LEFT))
#define KC_NWIN C(G(KC_RIGHT))

//Homerow mods
#define HM_A    LGUI_T(KC_A)
#define HM_S    LALT_T(KC_S)
#define HM_D    LCTL_T(KC_D)
#define HM_F    LSFT_T(KC_F)
#define HM_SCLN RGUI_T(KC_SCLN)
#define HM_L    RALT_T(KC_L)
#define HM_K    RCTL_T(KC_K)
#define HM_J    RSFT_T(KC_J)



/*  Standard layer layouts  */

/*
       |  Pinky Ring  Mid   Index Inner    Inner Index Mid   Ring  Pinky |
-------+-----------------------------------------------------------------+
Top    |  L4T,  L3T,  L2T,  L1T,  L0T   || R0T,  R1T,  R2T,  R3T,  R4T   |
Middle |  L4M,  L3M,  L2M,  L1M,  L0M   || R0T,  R1T,  R2T,  R3T,  R4T   |
Bottom |  L4B,  L3B,  L2B,  L1B,  L0B   || R0B,  R1B,  R2B,  R3B,  R4B   |
-------+-----------------------------------------------------------------+
*/


/* Navigation Layer

       |  Pinky    Ring     Mid      Index    Inner   |        | Inner    Index    Mid      Ring      Pinky   |
-------+-----------------------------------------------        -----------------------------------------------+
Top    |  XXXXXXX, XXXXXXX, Mouse U, XXXXXXX, M-Whl U |        | MMBtn,   Ctrl-L,  Up,      Ctrl-R,   XXXXXXX |
Middle |  XXXXXXX, Mouse L, Mouse D, Mouse R, M-Whl D |        | LMBtn,   Left,    Down,    Right,    XXXXXXX |
Bottom |  _______, Ctrl-X,  Ctrl-C,  Ctrl-V,  XXXXXXX |        | RMBtn,   Home,    XXXXXXX, End,      XXXXXXX |
-------+-----------------------------------------------        -----------------------------------------------+
*/

#define NAV_L4T XXXXXXX
#define NAV_L4M XXXXXXX
#define NAV_L4B _______
#define NAV_L3T XXXXXXX
#define NAV_L3M KC_MS_L
#define NAV_L3B KM_CUT
#define NAV_L2T KC_MS_U
#define NAV_L2M KC_MS_D
#define NAV_L2B KM_COPY
#define NAV_L1T XXXXXXX
#define NAV_L1M KC_MS_R
#define NAV_L1B KM_PAST
#define NAV_L0T KC_WH_U
#define NAV_L0M KC_WH_D
#define NAV_L0B XXXXXXX

#define NAV_R0T KC_BTN3
#define NAV_R0M KC_BTN1
#define NAV_R0B KC_BTN2
#define NAV_R1T KC_CLFT
#define NAV_R1M KC_LEFT
#define NAV_R1B KC_HOME
#define NAV_R2T KC_UP
#define NAV_R2M KC_DOWN
#define NAV_R2B XXXXXXX
#define NAV_R3T KC_CRHT
#define NAV_R3M KC_RIGHT
#define NAV_R3B KC_END
#define NAV_R4T XXXXXXX
#define NAV_R4M XXXXXXX
#define NAV_R4B XXXXXXX

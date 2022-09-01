#pragma once

#include "defines.h"


//define combo names and number of combos
enum combo_list {
    QP_ESC,
    CAPS_COMBO,
    EM_EMAIL,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

//define combos
const uint16_t PROGMEM qp_combo[] = {KC_Q, KC_P, COMBO_END};
//const uint16_t PROGMEM email_combo[] = {KC_E, KC_M, COMBO_END};

//create array of combos and their actions
combo_t key_combos[] = {
  [QP_ESC] = COMBO(qp_combo, KC_ESC),
  //[EM_EMAIL] = COMBO_ACTION(email_combo)
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

//process more complex combo actions
// void process_combo_event(uint16_t combo_index, bool pressed) {
//    switch(combo_index) {
//     case EM_EMAIL:
//       if (pressed) {
//         SEND_STRING("jason.wridgway@safegroup.com.au");
//       }
//       break;
//   }
// }

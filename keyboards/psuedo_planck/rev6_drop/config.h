#pragma once

#define PRODUCT_ID 0xAE01
#define DEVICE_VER 0x0005

#undef MATRIX_ROWS
#undef MATRIX_COLS
/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 6

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
/* Note: These are not used for arm boards. They're here purely as documentation. */
#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS

#define MATRIX_ROW_PINS \
    { D1, D0, D4, C6, B5, B4, E6, D7 }
#define MATRIX_COL_PINS \
    { B1, F7, F6, B3, B2, B6 }

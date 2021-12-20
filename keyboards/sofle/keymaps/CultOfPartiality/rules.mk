
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
ENCODER_ENABLE = yes
CONSOLE_ENABLE = no
EXTRAKEY_ENABLE = yes
AUTO_SHIFT_ENABLE = yes # Auto Shift, adding in after seeing miryoku

LTO_ENABLE = yes

MOUSEKEY_ENABLE = yes # This is still buggered....

TAP_DANCE_ENABLE = yes

SRC += oled.c encoder.c tapdance.c

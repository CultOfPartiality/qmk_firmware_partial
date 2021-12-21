
OLED_ENABLE = yes
OLED_DRIVER = SSD1306
ENCODER_ENABLE = yes
CONSOLE_ENABLE = no
EXTRAKEY_ENABLE = yes
AUTO_SHIFT_ENABLE = yes # Auto Shift, adding in after seeing miryoku

# Chasing space gains
LTO_ENABLE = yes
MUSIC_ENABLE = no
SPACE_CADET_ENABLE = no

MOUSEKEY_ENABLE = yes # This is still buggered....

TAP_DANCE_ENABLE = yes

# To clean up development split operations into multiple files
SRC += oled.c encoder.c tapdance.c

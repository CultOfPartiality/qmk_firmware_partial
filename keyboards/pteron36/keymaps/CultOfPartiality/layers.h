#define LAYER_KEYMAP_BASE \
KC_Q,				KC_W,				KC_E,				KC_R,				KC_T,				/**/	KC_Y,				KC_U,				KC_I,				KC_O,				KC_P,				\
LGUI_T(KC_A),		LALT_T(KC_S),		LCTL_T(KC_D),		LSFT_T(KC_F),		KC_G,				/**/	KC_H,				LSFT_T(KC_J),		LCTL_T(KC_K),		LALT_T(KC_L),		LGUI_T(KC_QUOT),	\
LT(BUTTON, KC_Z),	ALGR_T(KC_X),		KC_C,				KC_V,				KC_B,				/**/	KC_N,				KC_M,				KC_COMM,			ALGR_T(KC_DOT),	 LT(BUTTON, KC_SLSH),	\
										LT(MEDIA, KC_ESC),	LT(NAV, KC_SPC),	LT(MOUSE, KC_TAB),	/**/	LT(SYM, KC_ENT),	LT(NUM, KC_BSPC),	LT(FUN, KC_DEL)

#define LAYER_KEYMAP_NAV \
RESET,				U_NA,				U_NA,				U_NA,				U_NA,				/**/	KC_INS,				KC_HOME,			KC_UP,				KC_END,				KC_PGUP,			\
KC_LGUI,			KC_LALT,			KC_LCTL,			KC_LSFT,			U_NA,				/**/	KC_CAPS,			KC_LEFT,			KC_DOWN,			KC_RGHT,			KC_PGDN,			\
U_NA,				KC_ALGR,			U_NA,				U_NA,				U_NA,				/**/	U_RDO,				U_PST,				U_CPY,				U_CUT,				U_UND,				\
										U_NA,				U_NA,				U_NA,				/**/	KC_ENT,				KC_BSPC,			KC_DEL

#define LAYER_KEYMAP_MOUSE \
RESET,				U_NA,				U_NA,				U_NA,				U_NA,				/**/	U_NU,				KC_WH_L,			KC_MS_U,			KC_WH_R,			KC_WH_U,			\
KC_LGUI,			KC_LALT,			KC_LCTL,			KC_LSFT,			U_NA,				/**/	U_NU,				KC_MS_L,			KC_MS_D,			KC_MS_R,			KC_WH_D,			\
U_NA,				KC_ALGR,			U_NA,				U_NA,				U_NA,				/**/	U_RDO,				U_PST,				U_CPY,				U_CUT,				U_UND,				\
										U_NA,				U_NA,				U_NA,				/**/	KC_BTN1,			KC_BTN3,			KC_BTN2

#define LAYER_KEYMAP_MEDIA \
RESET,				U_NA,				U_NA,				U_NA,				U_NA,				/**/	RGB_TOG,			RGB_MOD,			KC_VOLU,			RGB_HUI,			RGB_SAI,			\
KC_LGUI,			KC_LALT,			KC_LCTL,			KC_LSFT,			U_NA,				/**/	OUT_AUTO,			KC_MPRV,			KC_VOLD,			KC_MNXT,			RGB_VAI,			\
U_NA,				KC_ALGR,			U_NA,				U_NA,				U_NA,				/**/	U_NU,				U_NU,				U_NU,				U_NU,				U_NU,				\
										U_NA,				U_NA,				U_NA,				/**/	KC_MSTP,			KC_MPLY,			KC_MUTE

#define LAYER_KEYMAP_NUM \
KC_1,				KC_2,				KC_3,				KC_4,				KC_5,				/**/	KC_6,				KC_7,				KC_8,				KC_9,				KC_0,				\
KC_SCLN,			KC_4,				KC_5,				KC_6,				KC_EQL,				/**/	U_NA,				KC_LSFT,			KC_LCTL,			KC_LALT,			KC_LGUI,			\
KC_GRV,				KC_1,				KC_2,				KC_3,				KC_BSLS,			/**/	U_NA,				U_NA,				U_NA,				KC_ALGR,			U_NA,				\
										KC_DOT,				KC_0,				KC_MINS,			/**/	U_NA,				U_NA,				U_NA

#define LAYER_KEYMAP_SYM \
KC_LCBR,			KC_AMPR,			KC_ASTR,			KC_LPRN,			KC_RCBR,			/**/	U_NA,				U_NA,				U_NA,				U_NA,				RESET,				\
KC_COLN,			KC_DLR,				KC_PERC,			KC_CIRC,			KC_PLUS,			/**/	U_NA,				KC_LSFT,			KC_LCTL,			KC_LALT,			KC_LGUI,			\
KC_TILD,			KC_EXLM,			KC_AT,				KC_HASH,			KC_PIPE,			/**/	U_NA,				U_NA,				U_NA,				KC_ALGR,			U_NA,				\
										KC_LPRN,			KC_RPRN,			KC_UNDS,			/**/	U_NA,				U_NA,				U_NA

#define LAYER_KEYMAP_FUN \
KC_F1,				KC_F2,				KC_F3,				KC_F4,				KC_F5,		    	/**/	KC_F6,				KC_F7,				KC_F8,				KC_F9,				KC_F10,				\
KC_F6,				KC_F7,				KC_F8,				KC_F9,				KC_F10,		    	/**/	U_NA,				KC_LSFT,			KC_LCTL,			KC_LALT,			LGUI_T(KC_F11),		\
KC_F11,				KC_F12,				U_NA,				U_NA,				U_NA,		    	/**/	U_NA,				U_NA,				U_NA,				KC_ALGR,			KC_F12,				\
										KC_APP,				KC_SPC,				KC_TAB,				/**/	U_NA,				U_NA,				U_NA

#define LAYER_KEYMAP_BUTTON \
U_UND,				U_CUT,				U_CPY,				U_PST,				U_RDO,				/**/	U_RDO,				U_PST,				U_CPY,				U_CUT,				U_UND,				\
KC_LGUI,			KC_LALT,			KC_LCTL,			KC_LSFT,			KC_NO,				/**/	KC_NO,				KC_LSFT,			KC_LCTL,			KC_LALT,			KC_LGUI,			\
U_UND,				U_CUT,				U_CPY,				U_PST,				U_RDO,				/**/	U_RDO,				U_PST,				U_CPY,				U_CUT,				U_UND,				\
										KC_BTN2,			KC_BTN3,			KC_BTN1,			/**/	KC_BTN1,			KC_BTN3,			KC_BTN2

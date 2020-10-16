// M60-A layout
#include QMK_KEYBOARD_H

enum combos {
	// ( )
	CBOLPRN,
	CBORPRN,
	// [ ]
  CBOLBRC,
  CBORBRC,
  // { }
  CBOLCBR,
  CBORCBR,
	// < >
  CBOLTAG,
  CBORTAG,
	// = -
  CBO_EQL,
  CBO_MIN
};

const uint16_t PROGMEM lparen_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM rparen_combo[] = {KC_J, KC_K, COMBO_END};

const uint16_t PROGMEM lbracket_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM rbracket_combo[] = {KC_K, KC_L, COMBO_END};

const uint16_t PROGMEM lcurly_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM rcurly_combo[] = {KC_L, KC_SCOLON, COMBO_END};

const uint16_t PROGMEM langle_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM rangle_combo[] = {KC_J, KC_L, COMBO_END};

const uint16_t PROGMEM equals_combo[] = {KC_A, KC_F, COMBO_END};
const uint16_t PROGMEM minus_combo[] = {KC_J, KC_SCOLON, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CBOLPRN] = COMBO(lparen_combo, KC_LPRN),
  [CBORPRN] = COMBO(rparen_combo, KC_RPRN),

	[CBOLBRC] = COMBO(lbracket_combo, KC_LBRACKET),
  [CBORBRC] = COMBO(rbracket_combo, KC_RBRACKET),

	[CBOLCBR] = COMBO(lcurly_combo, KC_LEFT_CURLY_BRACE),
  [CBORCBR] = COMBO(rcurly_combo, KC_RIGHT_CURLY_BRACE),

	[CBOLTAG] = COMBO(langle_combo, KC_LEFT_ANGLE_BRACKET),
  [CBORTAG] = COMBO(rangle_combo, KC_RIGHT_ANGLE_BRACKET),

	[CBO_EQL] = COMBO(equals_combo, KC_EQUAL),
	[CBO_MIN] = COMBO(minus_combo, KC_MINUS),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// Default layer
[0] = LAYOUT_60_hhkb(
	KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_DEL,
	KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
	KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
	KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(3),
	         KC_LALT, KC_LGUI,                            LT(1, KC_SPC),                      KC_RALT, MO(2)),

// Fn1 Layer
[1] = LAYOUT_60_hhkb(
	KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_GRV,  KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	         KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS),

// Fn2 Layer (media)
[2] = LAYOUT_60_hhkb(
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	         KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS),

// Fn3 Layer (LED effects)
[3] = LAYOUT_60_hhkb(
	KC_TRNS, EF_DEC,  EF_INC,  H1_DEC,  H1_INC,  H2_DEC,  H2_INC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, BR_DEC,  BR_INC,  KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, S1_DEC,  S1_INC,  S2_DEC,  S2_INC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ES_DEC,  ES_INC,  KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	         KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS),

};



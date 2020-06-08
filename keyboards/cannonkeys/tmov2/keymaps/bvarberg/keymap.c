/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK
};

enum combo_events {
  DF_LPRN,
  JK_RPRN,
  SD_LBRC,
  KL_RBRC,
  AS_LCBR,
  LSEMI_RCBR,
  SF_LTAG,
  JL_RTAG,
  AF_EQL,
  JSEMI_MINUS
};

#define SPC_LOWER LT(_LOWER, KC_SPC)
#define RAISE MO(_RAISE)

enum layer_names {
  _QWERTY,
  _COLEMAK,
  _LOWER,
  _RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_default(
    QWERTY,		KC_TAB, 	KC_Q, 		KC_W, 		KC_E, 		KC_R, 		KC_T, 		KC_Y, 		KC_U, 		KC_I, 		KC_O, 		KC_P, 		KC_LBRC, 	KC_RBRC, 	KC_BSLASH,
    COLEMAK,  KC_LCTL,  KC_A,			KC_S, 		KC_D, 		KC_F, 		KC_G, 		KC_H, 		KC_J, 		KC_K, 		KC_L, 		KC_SCLN, 	KC_QUOT, 	      KC_ENT,
    KC_F13,   KC_LSFT, 	KC_NO,   	KC_Z, 		KC_X, 		KC_C, 		KC_V, 		KC_B, 		KC_N, 		KC_M, 		KC_COMM, 	KC_DOT, 	KC_SLSH, 	KC_RSFT, 	KC_NO,
    KC_F14,                      KC_LALT,  KC_LGUI, 	        KC_BSPC,            SPC_LOWER,          KC_RALT,  RAISE
  ),

  [_COLEMAK] = LAYOUT_default(
    QWERTY,		KC_TAB, 	KC_Q, 		KC_W, 		KC_F, 		KC_P,     KC_G, 		KC_J, 		KC_L, 		KC_U, 		KC_Y, 		KC_SCLN,	KC_LBRC, 	KC_RBRC, 	KC_BSLASH,
    COLEMAK,	KC_LCTL,  KC_A,			KC_R, 		KC_S, 		KC_T, 		KC_D, 		KC_H, 		KC_N, 		KC_E, 		KC_I, 		KC_O, 	  KC_QUOT, 	      KC_ENT,
    KC_F13,   KC_LSFT, 	KC_NO,   	KC_Z, 		KC_X, 		KC_C, 		KC_V, 		KC_B, 		KC_K, 		KC_M, 		KC_COMM, 	KC_DOT, 	KC_SLSH, 	KC_RSFT, 	KC_NO,
    KC_F14,                      KC_LALT,  KC_LGUI,           KC_BSPC,            SPC_LOWER,          KC_RALT,  RAISE
  ),

  [_LOWER] = LAYOUT_default(
    KC_TRNS,  KC_ESC,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MINUS, KC_EQUAL,  KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_LEFT,  KC_DOWN,  KC_UP,    KC_RIGHT, KC_TRNS,  KC_GRAVE,         KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_NO,    KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINUS, KC_EQUAL, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,
    KC_TRNS,                      KC_TRNS,  KC_TRNS,          KC_TRNS,            KC_TRNS,              KC_TRNS,  KC_TRNS
  ),

  [_RAISE] = LAYOUT_default(
    KC_TRNS,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_F13,
    KC_TRNS,  KC_TRNS,  KC_VOLD,  KC_VOLU,  KC_MUTE,  KC_MPLY,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,        KC_TRNS,
    KC_SLEP,  KC_TRNS,  KC_NO,    KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_MNXT,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NO,
    KC_WAKE,                      KC_TRNS,  KC_TRNS,          KC_TRNS,            KC_TRNS,              KC_TRNS,  KC_TRNS
  )
};

const uint16_t PROGMEM lparen_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM rparen_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM lbracket_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM rbracket_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM lcbrace_combo[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM rcbrace_combo[] = {KC_L, KC_SCOLON, COMBO_END};
const uint16_t PROGMEM langle_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM rangle_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM equals_combo[] = {KC_A, KC_F, COMBO_END};
const uint16_t PROGMEM minus_combo[] = {KC_J, KC_SCOLON, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [DF_LPRN] = COMBO_ACTION(lparen_combo),
  [JK_RPRN] = COMBO_ACTION(rparen_combo),
  [SD_LBRC] = COMBO_ACTION(lbracket_combo),
  [KL_RBRC] = COMBO_ACTION(rbracket_combo),
  [AS_LCBR] = COMBO_ACTION(lcbrace_combo),
  [LSEMI_RCBR] = COMBO_ACTION(rcbrace_combo),
  [SF_LTAG] = COMBO_ACTION(langle_combo),
  [JL_RTAG] = COMBO_ACTION(rangle_combo),
  [AF_EQL] = COMBO_ACTION(equals_combo),
  [JSEMI_MINUS] = COMBO_ACTION(minus_combo)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
  }
  return true;
}

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case DF_LPRN:
      if (pressed) {
        tap_code16(KC_LEFT_PAREN);
      }
      break;
    case JK_RPRN:
      if (pressed) {
        tap_code16(KC_RIGHT_PAREN);
      }
      break;
    case SD_LBRC:
      if (pressed) {
        tap_code16(KC_LBRACKET);
      }
      break;
    case KL_RBRC:
      if (pressed) {
        tap_code16(KC_RBRACKET);
      }
      break;
    case AS_LCBR:
      if (pressed) {
        tap_code16(KC_LEFT_CURLY_BRACE);
      }
      break;
    case LSEMI_RCBR:
      if (pressed) {
        tap_code16(KC_RIGHT_CURLY_BRACE);
      }
      break;
    case SF_LTAG:
      if (pressed) {
        tap_code16(KC_LT);
      }
      break;
    case JL_RTAG:
      if (pressed) {
        tap_code16(KC_GT);
      }
      break;
    case AF_EQL:
      if (pressed) {
        tap_code16(KC_EQUAL);
      }
      break;
    case JSEMI_MINUS:
      if (pressed) {
        tap_code16(KC_MINUS);
      }
      break;
  }
}

/* Copyright 2017 Mathias Andersson <wraul@dbox.se>
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
 
#include QMK_KEYBOARD_H

//Layers and Tap Dance

enum {
  BASE = 0,
  FUNCTION,
  ARROWS,
};

// Tap dance definition
/* qk_tap_dance_action_t tap_dance_actions[] = {
	// Tap once for esc, twice for tilde
	[SLASHANDDEL]=ACTION_TAP_DANCE_DOUBLE(KC_DEL,KC_BSLS),
}; */

#define CUT LCTL(KC_X)
#define COPY LCTL(KC_C) 
#define PASTE LCTL(KC_V)
#define ALL LCTL(KC_A)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap BASE: (Base Layer) Default Layer
   * 
   * ,-----------------------------------------------------------. .-------------------.
   * |ESC| 1 |  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp | |NumL| /  | *  | -  |
   * |-----------------------------------------------------------| |-------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|SLDEL| | 7  | 8  | 9  |    |
   * |-----------------------------------------------------------| |--------------| +  |
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return | | 4  | 5  | 6  |    |
   * |-----------------------------------------------------------| |-------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     | | 1  | 2  | 3  | Ent|
   * |-----------------------------------------------------------| |--------------|    |
   * |Ctrl|Gui |Alt |      Space           | Alt | Alt |FN  |Ctr | |   0     | .  |    |
   * `-----------------------------------------------------------' '-------------------'
   */
  [BASE] = LAYOUT_all(
    KC_GESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, KC_BSPC, XXXXXXX, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_DEL,  		   KC_P7,   KC_P8,   KC_P9,   XXXXXXX, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, XXXXXXX, KC_ENT,           KC_P4,   KC_P5,   KC_P6,   LT(ARROWS,KC_PPLS), \
    KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, XXXXXXX,          KC_P1,   KC_P2,   KC_P3,   XXXXXXX, \
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                      KC_RALT, KC_RALT, LT(FUNCTION, XXXXXXX), KC_RCTL,            KC_P0,   XXXXXXX, KC_PDOT, KC_PENT  \
  ),
  
  /* Keymap FUNCTION: (Function layer)
   * 
   * ,-----------------------------------------------------------. .-------------------.
   * | ~ | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|       | |    |    |    |    |
   * |-----------------------------------------------------------| |-------------------|
   ** |RMODE|HUP|SUP|VUP|   |   |   |   |   |   |   |   |   |  \  | |    |    |    |    |
   * |-----------------------------------------------------------| |-------------------|
   * |RMODERV|HDN|SDN|VDN|   |   |   |   |   |   |   |   |       | |    |    |    |    |
   * |-----------------------------------------------------------| |-------------------|
   * |RGBPLAIN|X|RAIN|KNIGHT|GRAD| |RESET| | |BLDN|BLUP|BLTOG|   | |    |    |    |    |
   * |-----------------------------------------------------------| |--------------|    |
   * |RTOG|    |    |                      |     |     |    |    | |         |    |    |
   * `-----------------------------------------------------------' '-------------------'
   */
  [FUNCTION] = LAYOUT_all(
    KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12, KC_PAUS, XXXXXXX, KC_SLCK,   CUT  ,  COPY  , PASTE  , \
    RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, KC_PSCR,  KC_INS, KC_BSLS,          _______, _______, _______, XXXXXXX, \
    RGB_RMOD,RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, KC_APP , XXXXXXX, _______,          _______, _______, _______, _______, \
    RGB_M_P, XXXXXXX, RGB_M_R, RGB_M_K, RGB_M_G, _______,  RESET , _______, _______,  BL_DEC,  BL_INC, BL_TOGG, KC_CALC, XXXXXXX,          _______, _______, _______, XXXXXXX, \
    RGB_TOG, _______, _______,                   _______,                          _______, _______, _______, _______,                     _______, XXXXXXX, _______, _______  \
  ),
  
  /* Keymap ARROWS: (Arrows and FN only layer)
   * 
   * ,-----------------------------------------------------------. .-------------------.
   * | ~ | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|       | |    |    |    |    |
   * |-----------------------------------------------------------| |-------------------|
   * |     |   | UP|   |   |   |   |   |   |   |   |   |   |  \  | |    |    |    |    |
   * |-----------------------------------------------------------| |-------------------|
   * |     |LEFT|DOWN|RIGHT|   |   |   |   |   |   |   |   |     | |    |    |    |    |
   * |-----------------------------------------------------------| |-------------------|
   * |        |X|   |   |   |   |   |   |   |   |   |   |        | |    |    |    |    |
   * |-----------------------------------------------------------| |--------------|    |
   * |    |    |    |                      |     |     |    |    | |         |    |    |
   * `-----------------------------------------------------------' '-------------------'
   */
  [ARROWS] = LAYOUT_all(
    KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12, KC_TRNS, XXXXXXX,     ALL,   CUT  ,  COPY  , PASTE  , \
    _______, _______, KC_UP  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,           KC_HOME,  KC_UP , KC_PGUP, XXXXXXX, \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______,          KC_LEFT, KC_DOWN, KC_RGHT, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,           KC_END, KC_DOWN, KC_PGDN, XXXXXXX, \
    _______, _______, _______,                   _______,                          _______, _______, _______, _______,                     _______, XXXXXXX, _______, _______  \
  ),
};

#ifdef OLED_DRIVER_ENABLE
void oled_task_user(void) {
    oled_write_P(PSTR("M0lly\n"),false);
	// Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case FUNCTION:
            oled_write_P(PSTR("Function\n"), false);
            break;
		case ARROWS:
            oled_write_P(PSTR("Arrows\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }
	// Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
}
#endif
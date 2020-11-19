#include QMK_KEYBOARD_H

// Tap dance declarations
enum{
	SLASHANDDEL = 0,
};

// Tap dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
	// Tap once for esc, twice for tilde
	[SLASHANDDEL]=ACTION_TAP_DANCE_DOUBLE(KC_DEL,KC_BSLS),
};

#define CUT LCTL(KC_X)
#define COPY LCTL(KC_V) //These are reversed for some reason
#define PASTE LCTL(KC_C)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_96_ansi(\
      KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME, KC_END,  KC_NLCK, CUT,     COPY,    PASTE,  \
      KC_GRV,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,     KC_9,    KC_0,    KC_MINS, KC_EQL,      KC_BSPC,      KC_CALC, KC_PSLS, KC_PAST, KC_PMNS,  \
      KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,     KC_O,    KC_P,    KC_LBRC, KC_RBRC,     KC_DEL,       KC_P7,   KC_P8,   KC_P9,   KC_PPLS,  \
      KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_P4,   KC_P5,   KC_P6,   KC_PPLS,  \
      KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,                     KC_P1,   KC_P2,   KC_P3,             \
      KC_LCTL,  KC_LGUI, KC_LALT, KC_SPC,  TT(1),   KC_RCTL,                                               KC_LEFT, KC_DOWN, KC_RIGHT,         KC_P0,   KC_PDOT, KC_PENT),          \

[1] = LAYOUT_96_ansi(\
      EEP_RST, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_INS,  KC_PGUP, KC_PGDN, KC_SLCK, KC_TRNS, KC_TRNS, KC_TRNS,  \
      KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_APP,  KC_PAUS,      KC_WSCH,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  \
      KC_TRNS, RGB_HUI,  RGB_SAI, RGB_VAI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,      KC_BSLS,     KC_WH_U, KC_TRNS, KC_TRNS, KC_TRNS,  \
      KC_TRNS, RGB_HUD,  RGB_SAD, RGB_VAD, KC_TRNS, KC_TRNS, KC_UP  , KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_MS_BTN1,                KC_MS_BTN2, KC_TRNS, KC_TRNS, KC_TRNS,  \
      RGB_M_P, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U,                     KC_WH_D, KC_TRNS, KC_TRNS,           \
      RGB_TOG, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                            KC_MS_L, KC_MS_D, KC_MS_R,            KC_TRNS, KC_TRNS, KC_TRNS),          \
};

void keyboard_post_init_user(void){
	rgblight_enable();
	rgblight_mode(1);
	//rgblight_sethsv(11,255,255);
}
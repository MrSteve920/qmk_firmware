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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
      KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,KC_BSPC, KC_HOME,
      KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, TD(SLASHANDDEL), KC_END,
      KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_PGUP,
      KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_PGDN,
      KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, TT(1), KC_RGUI, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
      ),
  // Fn Layer
  [1] = LAYOUT(
      KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12 ,KC_TRNS,KC_WSCH,KC_SLCK,
      RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_APP,KC_PAUS,KC_BSLS,KC_WH_U,
      RGB_RMOD, RGB_HUD ,RGB_SAD, RGB_VAD,KC_TRNS,KC_TRNS,KC_TRNS,KC_UP,KC_LEFT,KC_DOWN,KC_RGHT,KC_TRNS,KC_MS_BTN1,KC_MS_BTN2,
      RGB_M_P,KC_NO, RGB_M_R, RGB_M_K, RGB_M_G,KC_TRNS, RESET,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_MS_U, KC_WH_D,
      RGB_TOG,KC_TRNS,KC_TRNS,				  KC_TRNS,KC_TRNS,KC_TRNS,		  KC_TRNS,KC_TRNS,KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R
	  ),
};

//void matrix_init_user (void){
void keyboard_post_init_user(void){
	//rgblight_mode(1);
	//rgblight_enable();
	//rgblight_sethsv(11,255,255);
}
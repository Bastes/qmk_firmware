#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 |------|------|------|       |------|--------|------|
 *                                 | Space|Bckspc| End  |       | PgDn |  Tab   |Enter |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_80(
  // left hand
  KC_PLUS,         KC_1,  KC_2,    KC_3,         KC_4,    KC_5,       KC_ESC,
   KC_EQL,         KC_Q,  KC_W,    KC_E,         KC_R,    KC_T,   LCA(KC_UP),
  KC_COLN,         KC_A,  KC_S,    KC_D,         KC_F,    KC_G,
  KC_LSPO, LCTL_T(KC_Z),  KC_X,    KC_C,         KC_V,    KC_B, LCA(KC_DOWN),
   KC_GRV,      KC_QUOT, KC_NO, KC_LEFT,      KC_RGHT,
                                                       KC_PSCR,      KC_LGUI,
                                         LGUI(KC_SPC),  KC_DEL,      KC_LCTL,
                                               KC_SPC, KC_BSPC,      KC_LALT,
  // right hand
   KC_ESC,         KC_6,   KC_7,    KC_8,    KC_9,            KC_0, KC_MINS,
  KC_PGUP,         KC_Y,   KC_U,    KC_I,    KC_O,            KC_P, KC_BSLS,
                   KC_H,   KC_J,    KC_K,    KC_L,   LT(2,KC_SCLN), KC_QUOT,
  KC_PGDN,         KC_N,   KC_M, KC_COMM,  KC_DOT, RCTL_T(KC_SLSH), KC_RSPC,
                          KC_UP, KC_DOWN, KC_LBRC,         KC_RBRC,   TT(1),
  KC_RGUI,       KC_ESC,
  KC_RCTL, LSFT(KC_TAB),  KC_NO,
  KC_RALT,       KC_TAB, KC_ENT
),

/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |------|------|------|       |------|------|------|
 *                                 |Brigh-|Brigh+|      |       |      | Hue- | Hue+ |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_80(
  // left hand
  KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_NO,
  KC_NO, KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR, KC_QUES, KC_NO,
  KC_NO, KC_HASH,  KC_DLR, KC_LPRN, KC_RPRN,  KC_GRV,
  KC_NO, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                               KC_NO, KC_NO,
                                      KC_NO,   KC_NO, KC_NO,
                                      KC_NO,   KC_NO, KC_NO,
  // right hand
  KC_NO,   KC_F6,   KC_F7,  KC_F8, KC_F9,  KC_F10,  KC_F11,
  KC_NO,   KC_UP,   KC_P7,  KC_P8, KC_P9, KC_PAST,  KC_F12,
         KC_DOWN,   KC_P4,  KC_P5, KC_P6, KC_PPLS,   KC_NO,
  KC_NO,   KC_NO,   KC_P1,  KC_P2, KC_P3, KC_PSLS,   KC_NO,
                  KC_COMM, KC_DOT, KC_P0,   KC_NO, KC_TRNS,
  KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO
),

/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |------|------|------|       |------|------|------|
 *                                 |      |      |      |       |      |      |BBack |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox_80(
  // left hand
  KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_NO,   KC_NO, KC_MS_U,   KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_NO, KC_MS_L, KC_MS_D, KC_MS_R,   KC_NO,
  KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                             KC_NO,   KC_NO,
                                    KC_NO,   KC_NO,   KC_NO,
                                  KC_BTN1, KC_BTN2, KC_BTN3,
  // right hand
  KC_NO,   KC_NO,   KC_NO,       KC_NO,     KC_NO, KC_NO, KC_NO,
  KC_NO,   KC_NO,   KC_NO,       KC_NO,     KC_NO, KC_NO, KC_NO,
           KC_NO,   KC_NO,     KC_MPLY,     KC_NO, KC_NO, KC_NO,
  KC_NO,   KC_NO,   KC_NO,     KC_MPRV,   KC_MNXT, KC_NO, KC_NO,
                  KC_MUTE, KC__VOLDOWN, KC__VOLUP, KC_NO, KC_NO,
  KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_WBAK, KC_WFWD
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};

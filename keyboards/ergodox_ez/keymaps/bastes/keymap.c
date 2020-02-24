#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define FACC 3 // fucking french accented chars

// shortcuts
# define KC_LS KC_LSFT
# define KC_RS KC_RSFT
# define XP_AC XP(ACIRCL, ACIRCU)
# define XP_AE XP(AELIGL, AELIGU)
# define XP_AG XP(AGRAVL, AGRAVU)
# define XP_AU XP(AUMLL, AUMLU)
# define XP_CC XP(CCEDL, CCEDU)
# define XP_EA XP(EACUTEL, EACUTEU)
# define XP_EC XP(ECIRCL, ECIRCU)
# define XP_EG XP(EGRAVL, EGRAVU)
# define XP_EU XP(EUMLL, EUMLU)
# define XP_IC XP(ICIRCL, ICIRCU)
# define XP_IU XP(IUMLL, IUMLU)
# define XP_OC XP(OCIRCL,OCIRCU)
# define XP_OE XP(OELIGL,OELIGU)
# define XP_OU XP(OUMLL, OUMLU)
# define XP_UC XP(UCIRCL, UCIRCU)
# define XP_UG XP(UGRAVL, UGRAVU)
# define XP_UU XP(UUMLL, UUMLU)


enum tapdance_keys {
  TD_SCREEN_UP = 0,
  TD_SCREEN_DOWN,
  TD_PREV_TAB,
  TD_NEXT_TAB,
  TD_UP_PGUP,
  TD_DOWN_PGDOWN
};


enum unicode_names {
  AGRAVL,
  AGRAVU,
  ACIRCL,
  ACIRCU,
  AUMLL,
  AUMLU,
  EACUTEL,
  EACUTEU,
  EGRAVL,
  EGRAVU,
  ECIRCL,
  ECIRCU,
  EUMLL,
  EUMLU,
  ICIRCL,
  ICIRCU,
  IUMLL,
  IUMLU,
  OCIRCL,
  OCIRCU,
  OUMLL,
  OUMLU,
  UGRAVL,
  UGRAVU,
  UCIRCL,
  UCIRCU,
  UUMLL,
  UUMLU,
  AELIGL,
  AELIGU,
  OELIGL,
  OELIGU,
  CCEDL,
  CCEDU,
  THINK
};

const uint32_t PROGMEM unicode_map[] = {
  [ACIRCL]  = 0x00E2,
  [ACIRCU]  = 0x00C2,
  [AELIGL]  = 0x00E6,
  [AELIGU]  = 0x00C6,
  [AGRAVL]  = 0x00E0,
  [AGRAVU]  = 0x00C0,
  [AUMLL]   = 0x00E4,
  [AUMLU]   = 0x00C4,
  [CCEDL]   = 0x00E7,
  [CCEDU]   = 0x00C7,
  [EACUTEL] = 0x00E9,
  [EACUTEU] = 0x00C9,
  [ECIRCL]  = 0x00EA,
  [ECIRCU]  = 0x00CA,
  [EGRAVL]  = 0x00E8,
  [EGRAVU]  = 0x00C8,
  [EUMLL]   = 0x00EB,
  [EUMLU]   = 0x00CB,
  [ICIRCL]  = 0x00EE,
  [ICIRCU]  = 0x00CE,
  [IUMLL]   = 0x00EF,
  [IUMLU]   = 0x00CF,
  [OCIRCL]  = 0x00F4,
  [OCIRCU]  = 0x00D4,
  [OELIGL]  = 0x0153,
  [OELIGU]  = 0x0152,
  [OUMLL]   = 0x00F6,
  [OUMLU]   = 0x00D6,
  [UCIRCL]  = 0x00FB,
  [UCIRCU]  = 0x00DB,
  [UGRAVL]  = 0x00F9,
  [UGRAVU]  = 0x00D9,
  [UUMLL]   = 0x00FC,
  [UUMLU]   = 0x00DC,
  [THINK]   = 0x1F914
};

enum custom_keycodes {
  EPRM = SAFE_RANGE,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  `   ~ |   1  |   2  |   3  |   4  |   5  |  Esc |           |  Esc |   6  |   7  |   8  |   9  |   0  |  - _   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  =   + |   Q  |   W  |   E  |   R  |   T  |  TD  |           |  TD  |   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------| ScUp |           | NTab |------+------+------+------+------+--------|
 * |    :   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|  ' "   |
 * |--------+------+------+------+------+------|  TD  |           |  TD  |------+------+------+------+------+--------|
 * | ( / LS |Z/LCtl| X/Alt|   C  |   V  |   B  | ScDn |           | PTab |   N  |   M  |   ,  | ./Alt|//RCtl| ) / RS |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ~L1  | :L3  |      | Left | Right|                                       |  Up  | Down |      | :L3  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  Up  | LGui |       | Home | PgUp |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Left | Down | Right|       | End  |PgDown| PScr |
 *                                 |------|------|------|       |------|------|------|
 *                                 | Space|Bckspc| Del  |       | ~L1  | Tab  |Enter |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox_80(
  // left hand
        KC_GRV,         KC_1,         KC_2,    KC_3,    KC_4,    KC_5,             KC_ESC,
        KC_EQL,         KC_Q,         KC_W,    KC_E,    KC_R,    KC_T,   TD(TD_SCREEN_UP),
       KC_COLN,         KC_A,         KC_S,    KC_D,    KC_F,    KC_G,
       KC_LSPO, LCTL_T(KC_Z), LALT_T(KC_X),    KC_C,    KC_V,    KC_B, TD(TD_SCREEN_DOWN),
         TT(1),       OSL(3),        KC_NO, KC_LEFT, KC_RGHT,
                                                                KC_UP,            KC_LGUI,
                                                     KC_LEFT, KC_DOWN,           KC_RIGHT,
                                                      KC_SPC, KC_BSPC,             KC_DEL,
  // right hand
           KC_ESC,      KC_6,           KC_7,               KC_8,           KC_9,            KC_0, KC_MINS,
  TD(TD_NEXT_TAB),      KC_Y,           KC_U,               KC_I,           KC_O,            KC_P, KC_BSLS,
                        KC_H,           KC_J,               KC_K,           KC_L,   LT(2,KC_SCLN), KC_QUOT,
  TD(TD_PREV_TAB),      KC_N,           KC_M,            KC_COMM, LALT_T(KC_DOT), RCTL_T(KC_SLSH), KC_RSPC,
                              TD(TD_UP_PGUP), TD(TD_DOWN_PGDOWN),          KC_NO,          OSL(3),   TT(1),
          KC_HOME,   KC_PGUP,
           KC_END, KC_PGDOWN,        KC_PSCR,
            TT(1),    KC_TAB,         KC_ENT
),

/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   ?  |   |  |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|   &  |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   /  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |  vv  |   <  |   >  |                                       |   0  |   ,  |   .  |   =  |  vv  |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.       ,-------------.
 *                                         |      |      |       |      |  vv  |
 *                                  ,------|------|------|       |------+------+------.
 *                                  |  vv  |  vv  |  vv  |       |  vv  |  vv  |      |
 *                                  |------|------|------|       |------|------|------|
 *                                  |  vv  |  vv  |  vv  |       |  vv  |  vv  |  vv  |
 *                                  `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_80(
  // left hand
   KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_TRNS,
X(THINK), KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR, KC_QUES, KC_PIPE,
   KC_NO, KC_HASH,  KC_DLR, KC_LPRN, KC_RPRN,  KC_GRV,
   KC_NO, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_AMPR,
   KC_NO,   KC_NO, KC_TRNS,   KC_LT,   KC_GT,
                                               KC_NO,   KC_NO,
                                    KC_TRNS, KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_NLCK,   KC_F6,   KC_F7,   KC_F8,  KC_F9,  KC_F10,  KC_F11,
  KC_PGUP,   KC_UP,   KC_P7,   KC_P8,  KC_P9, KC_PAST,  KC_F12,
           KC_DOWN,   KC_P4,   KC_P5,  KC_P6, KC_PPLS,   KC_NO,
  KC_PGDN,   KC_NO,   KC_P1,   KC_P2,  KC_P3, KC_PSLS,   KC_NO,
                      KC_P0, KC_COMM, KC_DOT,  KC_EQL, KC_TRNS,
    KC_NO, KC_TRNS,
  KC_TRNS, KC_TRNS,   KC_NO,
  KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | MsWhL| MsUp |MsWhR |MsWhUp|      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|MsWhDn|------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift | LCtl |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       | Mute |VolDn |VolUp |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |  vv  |      |      |       |      |      |      |
 *                                 |------|------|------|       |------|------|------|
 *                                 | LClk | RClk | MClk |       |      |BBack | BFwd |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox_80(
  // left hand
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_NO,   KC_NO, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,   KC_NO,
  KC_NO,   KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
  KC_LCTL, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  KC_LSFT, KC_NO, KC_TRNS,   KC_NO,   KC_NO,
                                             KC_NO,   KC_NO,
                                  KC_TRNS,   KC_NO,   KC_NO,
                                  KC_BTN1, KC_BTN2, KC_BTN3,
  // right hand
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
           KC_NO,   KC_NO, KC_MPLY,   KC_NO,   KC_NO, KC_NO,
  KC_NO,   KC_NO,   KC_NO, KC_MPRV, KC_MNXT,   KC_NO, KC_NO,
                  KC_MUTE, KC_VOLD, KC_VOLU,   KC_NO, KC_NO,
  KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_WBAK, KC_WFWD
),

/* Keymap 3: Fucking french accented chars
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | Æ  æ | É  é | Ê  ê | È  è |      |      |           |      | Ù  ù | Û  û | Î  î | Ô  ô | Œ  œ |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Â  â | À  à | Ë  ë |      |      |------|           |------|      | Ü  ü | Ï  ï | Ö  ö |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift | Ä  ä |      | Ç  ç |      |      |      |           |      |      |      |      |      |      | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |  L0  |      |      |      |                                       |      |      |      |  L0  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |------|------|------|       |------|------|------|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[FACC] = LAYOUT_ergodox_80(
  // left hand
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, XP_AE, XP_EA, XP_EC, XP_EG, KC_NO, KC_NO,
  KC_NO, XP_AC, XP_AG, XP_EU, KC_NO, KC_NO,
  KC_LS, XP_AU, KC_NO, XP_CC, KC_NO, KC_NO, KC_NO,
  KC_NO, TO(0), KC_NO, KC_NO, KC_NO,
                                     KC_NO, KC_NO,
                              KC_NO, KC_NO, KC_NO,
                              KC_NO, KC_NO, KC_NO,
  // right hand
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, XP_UG, XP_UC, XP_IC, XP_OC, XP_OE, KC_NO,
         KC_NO, XP_UU, XP_IU, XP_OU, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RS,
                KC_NO, KC_NO, KC_NO, TO(0), KC_NO,
  KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO
)
};

qk_tap_dance_action_t tap_dance_actions[] = {
  // one screen up
  [TD_SCREEN_UP] = ACTION_TAP_DANCE_DOUBLE(KC_NO, LCA(KC_UP)),

  // one screen down
  [TD_SCREEN_DOWN] = ACTION_TAP_DANCE_DOUBLE(KC_NO, LCA(KC_DOWN)),

  // previous tab
  [TD_PREV_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_NO, LCTL(KC_PGUP)),

  // next tab
  [TD_NEXT_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_NO, LCTL(KC_PGDOWN)),

  // up / pgup
  [TD_UP_PGUP] = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_PGUP),

  // down / pgdown
  [TD_DOWN_PGDOWN] = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_PGDOWN)
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

  set_unicode_input_mode(UC_LNX);
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

#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define FACC 3 // fucking french accented chars
#define FPSK 4 // fps-oriented layout

// shortcuts
# define KC_LS KC_LSFT
# define KC_RS KC_RSFT
# define NBSPC X(NBSP)
# define XP_AC XP(ACIRCL, ACIRCU)
# define XP_AE XP(AELIGL, AELIGU)
# define XP_AG XP(AGRAVL, AGRAVU)
# define XP_AU XP(AUMLL, AUMLU)
# define XP_CC XP(CCEDL, CCEDU)
# define XP_EA XP(EACUTEL, EACUTEU)
# define XP_EC XP(ECIRCL, ECIRCU)
# define XP_EG XP(EGRAVL, EGRAVU)
# define XP_EU XP(EUMLL, EUMLU)
# define X_EUR X(EURO)
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
  TD_NEXT_TAB
};


enum unicode_names {
  ACIRCL,
  ACIRCU,
  AELIGL,
  AELIGU,
  AGRAVL,
  AGRAVU,
  AUMLL,
  AUMLU,
  CCEDL,
  CCEDU,
  EACUTEL,
  EACUTEU,
  ECIRCL,
  ECIRCU,
  EGRAVL,
  EGRAVU,
  EUMLL,
  EUMLU,
  EURO,
  ICIRCL,
  ICIRCU,
  IUMLL,
  IUMLU,
  NBSP,
  OCIRCL,
  OCIRCU,
  OELIGL,
  OELIGU,
  OUMLL,
  OUMLU,
  THINK,
  UCIRCL,
  UCIRCU,
  UGRAVL,
  UGRAVU,
  UUMLL,
  UUMLU
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
  [EURO]    = 0x20AC,
  [ICIRCL]  = 0x00EE,
  [ICIRCU]  = 0x00CE,
  [IUMLL]   = 0x00EF,
  [IUMLU]   = 0x00CF,
  [NBSP]    = 0x00A0,
  [OCIRCL]  = 0x00F4,
  [OCIRCU]  = 0x00D4,
  [OELIGL]  = 0x0153,
  [OELIGU]  = 0x0152,
  [OUMLL]   = 0x00F6,
  [OUMLU]   = 0x00D6,
  [THINK]   = 0x1F914,
  [UCIRCL]  = 0x00FB,
  [UCIRCU]  = 0x00DB,
  [UGRAVL]  = 0x00F9,
  [UGRAVU]  = 0x00D9,
  [UUMLL]   = 0x00FC,
  [UUMLU]   = 0x00DC
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
 * | ( / LS |Z/LCtl| X/Alt| C/L1 | V/L3 |   B  | ScDn |           | PTab |   N  | M/L3 | ,/L1 | ./Alt|//RCtl| ) / RS |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | :L1  | :L3  |  TL5 | Left | Right|                                       |  Up  | Down |      | :L3  | :L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | PgUp | Home |       | LGui |  Up  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Esc  |PgDown| End  |       | Right| Down | Left |
 *                                 |------|------|------|       |------|------|------|
 *                                 | Space|Bckspc| Del  |       | :L1  | Tab  |Return|
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox_80(
  // left hand
        KC_GRV,         KC_1,         KC_2,        KC_3,        KC_4,      KC_5,             KC_ESC,
        KC_EQL,         KC_Q,         KC_W,        KC_E,        KC_R,      KC_T,   TD(TD_SCREEN_UP),
       KC_COLN,         KC_A,         KC_S,        KC_D,        KC_F,      KC_G,
       KC_LSPO, LCTL_T(KC_Z), LALT_T(KC_X), LT(1, KC_C), LT(3, KC_V),      KC_B, TD(TD_SCREEN_DOWN),
        OSL(1),       OSL(3),        TG(4),     KC_LEFT,     KC_RGHT,
                                                                        KC_PGUP,            KC_HOME,
                                                              KC_ESC, KC_PGDOWN,             KC_END,
                                                              KC_SPC,   KC_BSPC,             KC_DEL,
  // right hand
           KC_ESC,    KC_6,        KC_7,           KC_8,           KC_9,            KC_0, KC_MINS,
  TD(TD_NEXT_TAB),    KC_Y,        KC_U,           KC_I,           KC_O,            KC_P, KC_BSLS,
                      KC_H,        KC_J,           KC_K,           KC_L,   LT(2,KC_SCLN), KC_QUOT,
  TD(TD_PREV_TAB),    KC_N, LT(3, KC_M), LT(1, KC_COMM), LALT_T(KC_DOT), RCTL_T(KC_SLSH), KC_RSPC,
                                  KC_UP,        KC_DOWN,          KC_NO,          OSL(3),  OSL(1),
          KC_LGUI,   KC_UP,
          KC_LEFT, KC_DOWN,    KC_RIGHT,
           OSL(1),  KC_TAB,      KC_ENT
),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | PrtScr |  F1  |  F2  |  F3  |  F4  |  F5  | CLck |           | NLck |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   ?  |      |           |      |   |  |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------|   &  |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |      |   1  |   2  |   3  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  vv  |      |      |   <  |   >  |                                       |   0  |   ,  |   .  |   =  |  vv  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  vv  |  vv  |       |  vv  |  vv  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |  vv  |  vv  |  vv  |       |  vv  |  vv  |      |
 *                                 |------|------|------|       |------|------|------|
 *                                 |  vv  |  vv  |  vv  |       |  vv  |  vv  |  vv  |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_80(
  // left hand
 KC_PSCR,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_CLCK,
X(THINK), KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR, KC_QUES,   KC_NO,
   KC_NO, KC_HASH,  KC_DLR, KC_LPRN, KC_RPRN,  KC_GRV,
   KC_NO, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,   KC_NO,
 KC_TRNS,   KC_NO, KC_TRNS,   KC_LT,   KC_GT,
                                              KC_TRNS, KC_TRNS,
                                     KC_TRNS, KC_TRNS, KC_TRNS,
                                     KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_NLCK,   KC_F6,   KC_F7,   KC_F8,  KC_F9,  KC_F10,  KC_F11,
    KC_NO, KC_PIPE,   KC_P7,   KC_P8,  KC_P9, KC_PAST,  KC_F12,
           KC_AMPR,   KC_P4,   KC_P5,  KC_P6, KC_PPLS,   KC_NO,
    KC_NO,   KC_NO,   KC_P1,   KC_P2,  KC_P3, KC_PSLS,   KC_NO,
                      KC_P0, KC_COMM, KC_DOT,  KC_EQL, KC_TRNS,
  KC_TRNS, KC_TRNS,
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
 * |        |      |MsLeft|MsDown|MsRght|MsWhDn|------|           |------|      | Prev | Play | Next |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift | LCtl |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Mute |VolDn |VolUp |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |------|------|------|       |------|------|------|
 *                                 | LClk | RClk | MClk |       |      |BBack | BFwd |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox_80(
  // left hand
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,   KC_NO,
    KC_NO,   KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
  KC_LSFT, KC_LCTL,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO, KC_TRNS,   KC_NO,   KC_NO,
                                                 KC_NO,   KC_NO,
                                        KC_NO,   KC_NO,   KC_NO,
                                      KC_BTN1, KC_BTN2, KC_BTN3,
  // right hand
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,
           KC_NO, KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,
                  KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO,
  KC_NO,   KC_NO,
  KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_WBAK, KC_WFWD
),

/* Keymap 3: Fucking french accented chars
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | Æ  æ | Ê  ê | É  é | È  è |      |      |           |      | Û  û | Ù  ù | Î  î | Ô  ô | Œ  œ |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | À  à | Â  â | Ë  ë |    € |      |------|           |------|      | Ü  ü | Ï  ï | Ö  ö |      |        |
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
 *                                 | NbSp |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[FACC] = LAYOUT_ergodox_80(
  // left hand
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, XP_AE, XP_EC, XP_EA, XP_EG, KC_NO, KC_NO,
  KC_NO, XP_AG, XP_AC, XP_EU, X_EUR, KC_NO,
  KC_LS, XP_AU, KC_NO, XP_CC, KC_NO, KC_NO, KC_NO,
  KC_NO, TO(0), KC_NO, KC_NO, KC_NO,
                                     KC_NO, KC_NO,
                              KC_NO, KC_NO, KC_NO,
                              NBSPC, KC_NO, KC_NO,
  // right hand
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, XP_UC, XP_UG, XP_IC, XP_OC, XP_OE, KC_NO,
         KC_NO, XP_UU, XP_IU, XP_OU, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RS,
                KC_NO, KC_NO, KC_NO, TO(0), KC_NO,
  KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO
),

/* Keymap 4: FPS Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  `   ~ |   1  |   2  |   3  |   4  |   5  |  Esc |           |      |   6  |   7  |   8  |   9  |   0  |  - _   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CapsLk |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ; : |  ' "   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  , < |  . > |  / ? | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |  TL4 | Left | Right|                                       |  Up  | Down |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | PgUp | Home |       | LGui |  Up  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Esc  |PgDown| End  |       | Right| Down | Left |
 *                                 |------|------|------|       |------|------|------|
 *                                 | Space|Bckspc|Return|       |      | Tab  |Return|
 *                                 `--------------------'       `--------------------'
 */
[FPSK] = LAYOUT_ergodox_80(
  // left hand
   KC_GRV,  KC_1,  KC_2,    KC_3,    KC_4,    KC_5,   KC_ESC,
   KC_TAB,  KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,    KC_NO,
  KC_CLCK,  KC_A,  KC_S,    KC_D,    KC_F,    KC_G,
  KC_SLSH,  KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,
    KC_NO, KC_NO, TG(4), KC_LEFT, KC_RGHT,
                                             KC_UP,  KC_LGUI,
                                  KC_LEFT, KC_DOWN, KC_RIGHT,
                                   KC_SPC, KC_BSPC,   KC_DEL,
  // right hand
   KC_ESC,    KC_6,     KC_7,    KC_8,   KC_9,    KC_0, KC_MINS,
    KC_NO,    KC_Y,     KC_U,    KC_I,   KC_O,    KC_P, KC_BSLS,
              KC_H,     KC_J,    KC_K,   KC_L, KC_SCLN, KC_QUOT,
    KC_NO,    KC_N,     KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC,
                       KC_UP, KC_DOWN,  KC_NO,   KC_NO,   KC_NO,
  KC_LGUI,   KC_UP,
  KC_LEFT, KC_DOWN, KC_RIGHT,
    KC_NO,  KC_TAB,   KC_ENT
)
};

void td_screen_up_finished(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 2:
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_UP);
      break;
    case 3:
      register_code(KC_LSFT);
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_UP);
      break;
  }
};

void td_screen_down_finished(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 2:
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_DOWN);
      break;
    case 3:
      register_code(KC_LSFT);
      register_code(KC_LCTL);
      register_code(KC_LALT);
      register_code(KC_DOWN);
      break;
  }
};

void td_screen_up_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 2:
      unregister_code(KC_LCTL);
      unregister_code(KC_LALT);
      unregister_code(KC_UP);
      break;
    case 3:
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTL);
      unregister_code(KC_LALT);
      unregister_code(KC_UP);
      break;
  }
};

void td_screen_down_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 2:
      unregister_code(KC_LCTL);
      unregister_code(KC_LALT);
      unregister_code(KC_DOWN);
      break;
    case 3:
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTL);
      unregister_code(KC_LALT);
      unregister_code(KC_DOWN);
      break;
  }
};

void td_next_tab_finished(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 2:
      register_code(KC_LCTL);
      register_code(KC_PGDOWN);
      break;
    case 3:
      register_code(KC_LSFT);
      register_code(KC_LCTL);
      register_code(KC_PGDOWN);
      break;
  }
};

void td_prev_tab_finished(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 2:
      register_code(KC_LCTL);
      register_code(KC_PGUP);
      break;
    case 3:
      register_code(KC_LSFT);
      register_code(KC_LCTL);
      register_code(KC_PGUP);
      break;
  }
};

void td_next_tab_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 2:
      unregister_code(KC_LCTL);
      unregister_code(KC_PGDOWN);
      break;
    case 3:
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTL);
      unregister_code(KC_PGDOWN);
      break;
  }
};

void td_prev_tab_reset(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 2:
      unregister_code(KC_LCTL);
      unregister_code(KC_PGUP);
      break;
    case 3:
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTL);
      unregister_code(KC_PGUP);
      break;
  }
};

qk_tap_dance_action_t tap_dance_actions[] = {
  // one screen up
  [TD_SCREEN_UP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_screen_up_finished, td_screen_up_reset),

  // one screen down
  [TD_SCREEN_DOWN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_screen_down_finished, td_screen_down_reset),

  // previous tab
  [TD_PREV_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_prev_tab_finished, td_prev_tab_reset),

  // next tab
  [TD_NEXT_TAB] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_next_tab_finished, td_next_tab_reset),
};

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

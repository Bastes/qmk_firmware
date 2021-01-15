/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
  _QWERTY = 0, // default layer
  _SYMBOLS,    // symbols
  _MEDIA,      // media keys
  _FRENCH,     // fucking french accented chars
  _FPS,        // fps-oriented layout
  _ARROWS,     // Keymap 5: Arrow Layer
  _REGOLITH_F, // Keymap 6: Regolith & FXX
};

#define RGB_DI_PIN D3
#define RGBLED_NUM 20

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
# define SNTAB LCTL(KC_PGDOWN)
# define SPTAB LCTL(KC_PGUP)
# define Z_CTL LCTL_T(KC_Z)
# define X_ALT LALT_T(KC_X)
# define C_L1 LT(1, KC_C)
# define V_L3 LT(3, KC_V)
# define SCLN_L2 LT(2,KC_SCLN)
# define M_L3 LT(3, KC_M)
# define COMM_L1 LT(1, KC_COMM)
# define DOT_ALT LALT_T(KC_DOT)
# define SLS_CTL RCTL_T(KC_SLSH)
# define TAP_REG TD(TAP_REGOLITH)

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
  [UCIRCL]  = 0x00FB,
  [UCIRCU]  = 0x00DB,
  [UGRAVL]  = 0x00F9,
  [UGRAVU]  = 0x00D9,
  [UUMLL]   = 0x00FC,
  [UUMLU]   = 0x00DC
};

////////////////////////////////////////////////////////////////////////////////
// BEGIN tap dances

// Tap dances
enum {
    SR1,
    SR2,
    SR3,
    SR4,
    SR5,
    SR6,
    SR7,
    SR8,
    SR9,
    SR0,
    TAP_REGOLITH
};

// Tap dance modes
enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    NOOP
};

typedef struct {
    uint16_t kc;
} qk_tap_dance_regolith_t;

void tapdance_regolith_finished(qk_tap_dance_state_t *state, void *user_data) {
    qk_tap_dance_dual_role_t *pair = (qk_tap_dance_dual_role_t *)user_data;

    if (state->count == 1) {
        tap_code16(LGUI(pair->kc));
    } else if (state->count == 2) {
        tap_code16(LGUI(LALT(pair->kc)));
    } else if (state->count == 3) {
        tap_code16(LGUI(LSFT(pair->kc)));
    }
}

#define MY_CUSTOM_ACTION_TAPDANCE(keycode) {  \
    .fn = { NULL, NULL, (void *)tapdance_regolith_finished }, \
    .user_data = (void *)&((qk_tap_dance_regolith_t) { keycode }),  \
  }


typedef struct {
    bool is_press_action;
    uint8_t state;
} tap_and_hold;

// Create an instance of 'tap' for the 'r1' tap dance.
static tap_and_hold tap_and_hold_state = {
    .is_press_action = true,
    .state = 0
};

uint8_t cur_dance(qk_tap_dance_state_t *state);
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted || !state->pressed) return DOUBLE_TAP;
        else return DOUBLE_HOLD;
    } else return NOOP;
}

// For the x tap dance. Put it here so it can be used in any keymap
void tap_and_hold_finished(qk_tap_dance_state_t *state, void *user_data);
void tap_and_hold_finished(qk_tap_dance_state_t *state, void *user_data) {
    tap_and_hold_state.state = cur_dance(state);
    switch (tap_and_hold_state.state) {
        case SINGLE_TAP:
          layer_on(6);
          set_oneshot_layer(6, ONESHOT_START);
          clear_oneshot_layer_state(ONESHOT_PRESSED);
          break;
        case SINGLE_HOLD:
          layer_on(6);
          register_mods(MOD_BIT(KC_LALT));
          break;
        case DOUBLE_TAP:
          set_oneshot_mods(MOD_BIT(KC_LGUI));
          break;
        case DOUBLE_HOLD:
          register_mods(MOD_BIT(KC_LGUI));
          break;
        case NOOP:
          break;
    }
}
void tap_and_hold_reset(qk_tap_dance_state_t *state, void *user_data);
void tap_and_hold_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (tap_and_hold_state.state) {
        case SINGLE_TAP:
          break;
        case SINGLE_HOLD:
          unregister_mods(MOD_BIT(KC_LALT));
          layer_off(6);
          break;
        case DOUBLE_TAP:
          break;
        case DOUBLE_HOLD:
          unregister_mods(MOD_BIT(KC_LGUI));
          break;
        case NOOP:
          break;
    }
    tap_and_hold_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [SR1] = MY_CUSTOM_ACTION_TAPDANCE(KC_1),
    [SR2] = MY_CUSTOM_ACTION_TAPDANCE(KC_2),
    [SR3] = MY_CUSTOM_ACTION_TAPDANCE(KC_3),
    [SR4] = MY_CUSTOM_ACTION_TAPDANCE(KC_4),
    [SR5] = MY_CUSTOM_ACTION_TAPDANCE(KC_5),
    [SR6] = MY_CUSTOM_ACTION_TAPDANCE(KC_6),
    [SR7] = MY_CUSTOM_ACTION_TAPDANCE(KC_7),
    [SR8] = MY_CUSTOM_ACTION_TAPDANCE(KC_8),
    [SR9] = MY_CUSTOM_ACTION_TAPDANCE(KC_9),
    [SR0] = MY_CUSTOM_ACTION_TAPDANCE(KC_0),
    [TAP_REGOLITH] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tap_and_hold_finished, tap_and_hold_reset)
};

// END tap dances
////////////////////////////////////////////////////////////////////////////////

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * 0 - QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   Tab  |  Q   |  W   |  E   |  R   |  T   |                              |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | CapsLk |  A   |  S   |  D   |  F   |  G   |                              |   H  |   J  |   K  |   L  | ;  : |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift | Z/LCl| X/Alt| C/L1 | V/L3 |  B   |  ESC |  Del |  |  TL4 |      |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |  OS* | Space|BckSpc|  |  *L5 | Enter|  OS* |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
      KC_CLCK,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L, SCLN_L2, KC_QUOT,
      KC_LSFT,   Z_CTL,   X_ALT,    C_L1,    V_L3,    KC_B,  KC_ESC,  KC_DEL,   TT(4), _______,    KC_N,    M_L3, COMM_L1, DOT_ALT, SLS_CTL, KC_RSFT,
                                 _______, _______, TAP_REG,  KC_SPC, KC_BSPC,   TT(5),  KC_ENT, TAP_REG, _______, _______
    ),
/*
 * 1 - Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   !  |   @  |   {  |   }  |   |  |                              |   &  |   7  |   8  |   9  |   *  | NumLck |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |                              |   -  |   4  |   5  |   6  |   +  | Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |      |  |      |      |   _  |   1  |   2  |   3  |   =  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |   0  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYMBOLS] = LAYOUT(
      _______, KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR, KC_PIPE,                                     KC_AMPR,    KC_7,    KC_8,    KC_9, KC_PAST, KC_NLCK,
      _______, KC_HASH,  KC_DLR, KC_LPRN, KC_RPRN,  KC_GRV,                                     KC_MINS,    KC_4,    KC_5,    KC_6, KC_PPLS,  KC_INS,
      _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______, _______, _______, KC_UNDS,    KC_1,    KC_2,    KC_3,  KC_EQL, _______,
                                 _______, _______, _______, _______, _______, _______, _______,    KC_0, _______, _______
    ),
/*
 * 2 - Media & Mouse
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      | MsWhL| MsUp |MsWhR |MsWhUp|                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|MsWhDn|                              |      | Prev | Play | Next |      |        |
 * |--------+------+------+------+------+------|-------------.  ,-------------|------+------+------+------+------+--------|
 * |        | LCtl | LAlt |      |      |      |      | MClk |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------|------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | LClk | RClk |  |BBack | BFwd | Mute |VolDn |VolUp |
 *                        `----------------------------------'  `----------------------------------'
 */
     [_MEDIA] = LAYOUT(
       _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,                                     _______, _______, _______, _______, _______, _______,
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                                     _______, _______, _______, _______, _______, _______,
       _______, KC_LCTL, KC_LALT, _______, _______, _______, _______, KC_BTN3, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,
                                  _______, _______, _______, KC_BTN1, KC_BTN2, KC_WBAK, KC_WFWD, KC_MUTE, KC_VOLD, KC_VOLU
     ),
/*
 * 3 - Fucking french accented chars
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | Æ  æ | Ê  ê | É  é | È  è |      |                              | Û  û | Ù  ù | Î  î | Ô  ô | Œ  œ |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | À  à | Â  â | Ë  ë |    € |      |                              |      | Ü  ü | Ï  ï | Ö  ö |      |        |
 * |--------+------+------+------+------+------|-------------.  ,-------------|------+------+------+------+------+--------|
 * |        | Ä  ä |      | Ç  ç |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | NbSp |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
     [_FRENCH] = LAYOUT(
       _______,   XP_AE,   XP_EC,   XP_EA,   XP_EG, _______,                                       XP_UC,   XP_UG,   XP_IC,   XP_OC,   XP_OE, _______,
       _______,   XP_AG,   XP_AC,   XP_EU,   X_EUR, _______,                                     _______,   XP_UU,   XP_IU,   XP_OU, _______, _______,
       _______,   XP_AU, _______,   XP_CC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                  _______, _______, _______,   NBSPC, _______, _______, _______, _______, _______, _______
     ),
/*
 * 4 - FPS (classic QWERTY)
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | CapsLk |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  |  ; : |  ' "   |
 * |--------+------+------+------+------+------|-------------.  ,-------------|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |  Esc |  Del |  |  L4  |      |   N  |   M  |  , < |  . > |  / ? | RShift |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 *                        |      |      |      | Space|Bckspc|  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
     [_FPS] = LAYOUT(
        KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
       KC_CLCK,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
         KC_LS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_ESC,  KC_DEL,   TG(4), _______,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_RS,
                                  _______, _______, _______,  KC_SPC, KC_BSPC, _______, _______, _______, _______, _______
     ),
/*
 * 5 - Arrows & Movements
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      | Home |   ^  |  End | PgUp |                              | MOD> | Hue+ | Sat+ | Val+ |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |  <=  |   v  |  =>  | PgDn |                              | <MOD | Hue- | Sat- | Val- |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | <Tab |      | Tab> |      |  Esc |      |  |      |      | LEDs |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |  L5  |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
     [_ARROWS] = LAYOUT(
       _______, _______, KC_HOME,   KC_UP,  KC_END, KC_PGUP,                                     RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______,
       _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                                    RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,
       _______, _______,   SPTAB, _______,   SNTAB, _______, _______, _______, _______, _______, RGB_TOG, _______, _______, _______, _______, _______,
                                  _______, _______, _______, _______, _______,   TG(5), _______, _______, _______, _______
     ),
/*
 * 6 - Regolith & FXX
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |                              |      |  R7  |  R8  |  R9  |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F6  |  F7  |  F8  |  F9  | F10  |                              |      |  R4  |  R5  |  R6  |      |        |
 * |--------+------+------+------+------+------|-------------.  ,-------------|------+------+------+------+------+--------|
 * |        |      |      |      | F11  | F12  |      |      |  |      |      |      |  R1  |  R2  |  R3  |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |  R0  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
     [_REGOLITH_F] = LAYOUT(
       _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                     _______, TD(SR7), TD(SR8), TD(SR9), _______, _______,
       _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                                     _______, TD(SR4), TD(SR5), TD(SR6), _______, _______,
       _______, _______, _______, _______,  KC_F11,  KC_F12, _______, _______, _______, _______, _______, TD(SR1), TD(SR2), TD(SR3), _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, TD(SR0), _______, _______
     ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;
}

static void render_kyria_logo(void) {
    static const char PROGMEM kyria_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
        0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
        0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    };
    oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}

static void render_qmk_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // QMK Logo and version information
    render_qmk_logo();
    oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case _SYMBOLS:
            oled_write_P(PSTR("Symbols\n"), false);
            break;
        case _MEDIA:
            oled_write_P(PSTR("Media\n"), false);
            break;
        case _FRENCH:
            oled_write_P(PSTR("French\n"), false);
            break;
        case _FPS:
            oled_write_P(PSTR("FPS\n"), false);
            break;
        case _ARROWS:
            oled_write_P(PSTR("Arrows\n"), false);
            break;
        case _REGOLITH_F:
            oled_write_P(PSTR("Regolith\n"), false);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status(); // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_kyria_logo();
    }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
#endif

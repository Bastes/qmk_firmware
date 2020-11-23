#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
  _QWERTY = 0, // default layer
  _SYMBOLS,    // symbols
  _MEDIA,      // media keys
  _FRENCH,     // fucking french accented chars
  _FPS,        // fps-oriented layout
  _ARROWS,     // Keymap 5: Arrow Layer
  _REGOLITH_F, // Keymap 6: Regolith & FXX
};

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
# define LGUI_1 LGUI(KC_1)
# define LGUI_2 LGUI(KC_2)
# define LGUI_3 LGUI(KC_3)
# define LGUI_4 LGUI(KC_4)
# define LGUI_5 LGUI(KC_5)
# define LGUI_6 LGUI(KC_6)
# define LGUI_7 LGUI(KC_7)
# define LGUI_8 LGUI(KC_8)
# define LGUI_9 LGUI(KC_9)
# define LGUI_0 LGUI(KC_0)
# define SGUI_1 SGUI(KC_1)
# define SGUI_2 SGUI(KC_2)
# define SGUI_3 SGUI(KC_3)
# define SGUI_4 SGUI(KC_4)
# define SGUI_5 SGUI(KC_5)
# define SGUI_6 SGUI(KC_6)
# define SGUI_7 SGUI(KC_7)
# define SGUI_8 SGUI(KC_8)
# define SGUI_9 SGUI(KC_9)
# define SGUI_0 SGUI(KC_0)

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

/////////////////////////////////////
// BEGIN custom tap-hold dancing PT 1

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP, // Send two single taps
    TRIPLE_TAP,
    TRIPLE_HOLD
};

// Tap dance enums
enum {
    R1_TAP
};

uint8_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void x_finished(qk_tap_dance_state_t *state, void *user_data);
void x_reset(qk_tap_dance_state_t *state, void *user_data);

// END custom tap-hold dancing PT 1
///////////////////////////////////

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |  | \   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CapsLk |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |:; /L2|  " '   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |Z/LCtl| X/Alt| C/L1 | V/L3 |   B  |      |           |      |   N  | M/L3 | ,/L1 | ./Alt|?/ /RC| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |  OS  |                                       |  OS  |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Esc  | Del  |      |       |      |  L6* |  L4  |
 *                                 |------|------|------|       |------|------|------|
 *                                 | Space|Bckspc|      |       |      |  L5* |Return|
 *                                 `--------------------'       `--------------------'
 */
[_QWERTY] = LAYOUT_ergodox_80(
  // left hand
    KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_NO,
  KC_CLCK,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_LS, Z_CTL,   X_ALT,    C_L1,    V_L3,    KC_B, KC_NO,
    KC_NO, KC_NO,   KC_NO,   KC_NO, KC_LGUI,
                                      KC_NO,   KC_NO,
                                     KC_ESC,  KC_DEL, KC_NO,
                                     KC_SPC, KC_BSPC, KC_NO,
  // right hand
  KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,
  KC_NO,    KC_Y,    KC_U,    KC_I,       KC_O,    KC_P, KC_BSLS,
            KC_H,    KC_J,    KC_K,       KC_L, SCLN_L2, KC_QUOT,
  KC_NO,    KC_N,    M_L3, COMM_L1,    DOT_ALT, SLS_CTL,   KC_RS,
                  KC_LGUI,   KC_NO, TD(R1_TAP),   KC_NO,   KC_NO,
  KC_NO,   KC_NO,
  KC_NO,  OSL(6),   TG(4),
  KC_NO,  OSL(5),  KC_ENT
),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   &  |   7  |   8  |   9  |   *  | NumLck |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------|   -  |   4  |   5  |   6  |   +  | Insert |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   _  |   1  |   2  |   3  |   =  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   ,  |   .  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |------|------|------|       |------|------|------|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_SYMBOLS] = LAYOUT_ergodox_80(
  // left hand
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
  KC_NO, KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR, KC_PIPE, KC_NO,
  KC_NO, KC_HASH,  KC_DLR, KC_LPRN, KC_RPRN,  KC_GRV,
  KC_NO, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_NO,
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                               KC_NO, KC_NO,
                                      KC_NO,   KC_NO, KC_NO,
                                      KC_NO,   KC_NO, KC_NO,
  // right hand
  KC_NO,   KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_AMPR, KC_P7,   KC_P8,  KC_P9, KC_PAST, KC_NLCK,
         KC_MINS, KC_P4,   KC_P5,  KC_P6, KC_PPLS,  KC_INS,
  KC_NO, KC_UNDS, KC_P1,   KC_P2,  KC_P3,  KC_EQL,   KC_NO,
                  KC_P0, KC_COMM, KC_DOT,   KC_NO,   KC_NO,
  KC_NO,   KC_NO,
  KC_NO,   KC_NO, KC_NO,
  KC_NO,   KC_NO, KC_NO
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
 * | LShift | LCtl | LAlt |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Mute |VolDn |VolUp |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      | MClk |      |       |      |      |      |
 *                                 |------|------|------|       |------|------|------|
 *                                 | LClk | RClk |      |       |      |BBack | BFwd |
 *                                 `--------------------'       `--------------------'
 */
[_MEDIA] = LAYOUT_ergodox_80(
  // left hand
  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,
  KC_NO,   KC_NO, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, KC_NO,
  KC_NO,   KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
  KC_LS, KC_LCTL, KC_LALT,   KC_NO,   KC_NO,   KC_NO, KC_NO,
  KC_NO,   KC_NO, KC_TRNS,   KC_NO,   KC_NO,
                                                 KC_NO, KC_NO,
                                        KC_NO, KC_BTN3, KC_NO,
                                      KC_BTN1, KC_BTN2, KC_NO,
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
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |------|------|------|       |------|------|------|
 *                                 | NbSp |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */

[_FRENCH] = LAYOUT_ergodox_80(
  // left hand
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, XP_AE, XP_EC, XP_EA, XP_EG, KC_NO, KC_NO,
  KC_NO, XP_AG, XP_AC, XP_EU, X_EUR, KC_NO,
  KC_LS, XP_AU, KC_NO, XP_CC, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                     KC_NO, KC_NO,
                              KC_NO, KC_NO, KC_NO,
                              NBSPC, KC_NO, KC_NO,
  // right hand
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, XP_UC, XP_UG, XP_IC, XP_OC, XP_OE, KC_NO,
         KC_NO, XP_UU, XP_IU, XP_OU, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RS,
                KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO,
  KC_NO, KC_NO, KC_NO
),

/* Keymap 4: FPS Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | CapsLk |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ; : |  ' "   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  , < |  . > |  / ? | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Esc  |  Del |      |       |      |      |  L4  |
 *                                 |------|------|------|       |------|------|------|
 *                                 | Space|Bckspc|      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_FPS] = LAYOUT_ergodox_80(
  // left hand
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,
   KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,    KC_T, KC_NO,
  KC_CLCK,  KC_A,  KC_S,  KC_D,  KC_F,    KC_G,
    KC_LS,  KC_Z,  KC_X,  KC_C,  KC_V,    KC_B, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                         KC_NO, KC_NO,
                               KC_ESC,  KC_DEL, KC_NO,
                               KC_SPC, KC_BSPC, KC_NO,
  // right hand
  KC_NO, KC_NO, KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,
  KC_NO,  KC_Y,  KC_U,    KC_I,   KC_O,    KC_P, KC_BSLS,
          KC_H,  KC_J,    KC_K,   KC_L, KC_SCLN, KC_QUOT,
  KC_NO,  KC_N,  KC_M, KC_COMM, KC_DOT, KC_SLSH,   KC_RS,
                KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,
  KC_NO, KC_NO,
  KC_NO, KC_NO, TG(4),
  KC_NO, KC_NO, KC_NO
),

/* Keymap 5: Arrow Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Home |   ^  |  End | PgUp |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  <=  |   v  |  =>  | PgDn |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Esc  |      |      |       |      |      |      |
 *                                 |------|------|------|       |------|------|------|
 *                                 | PTab | NTab |      |       |      |  L5  |      |
 *                                 `--------------------'       `--------------------'
 */
[_ARROWS] = LAYOUT_ergodox_80(
  // left hand
  KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO,     KC_NO, KC_NO,
  KC_NO, KC_NO, KC_HOME,   KC_UP,   KC_END,   KC_PGUP, KC_NO,
  KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDOWN,
  KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO,     KC_NO, KC_NO,
  KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO,
                                                KC_NO, KC_NO,
                                    KC_ESC,     KC_NO, KC_NO,
                                     SPTAB,     SNTAB, KC_NO,
  // right hand
  KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,
  KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,
          KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,
  KC_NO,  KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,
                 KC_NO, KC_NO, KC_LALT, KC_LCTL, KC_RS,
  KC_NO,  KC_NO,
  KC_NO,  KC_NO, KC_NO,
  KC_NO, OSL(5), KC_NO
),

/* Keymap 6: Regolith & FXX
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  | F10  |  F11   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  S1  |  S2  |  S3  |  S4  |  S5  |------|           |------|  S6  |  S7  |  S8  |  S9  | S10  |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  M1  |  M2  |  M3  |  M4  |  M5  |      |           |      |  M6  |  M7  |  M8  |  M9  | M10  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |  L6  |      |
 *                                 |------|------|------|       |------|------|------|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_REGOLITH_F] = LAYOUT_ergodox_80(
  // left hand
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,
  KC_NO,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5, KC_NO,
  KC_NO, LGUI_1, LGUI_2, LGUI_3, LGUI_4, LGUI_5,
  KC_NO, SGUI_1, SGUI_2, SGUI_3, SGUI_4, SGUI_5, KC_NO,
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
                                          KC_NO, KC_NO,
                                  KC_NO,  KC_NO, KC_NO,
                                  KC_NO,  KC_NO, KC_NO,
  // right hand
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
  KC_NO,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11,
         LGUI_6, LGUI_7, LGUI_8, LGUI_9, LGUI_0, KC_F12,
  KC_NO, SGUI_6, SGUI_7, SGUI_8, SGUI_9, SGUI_0,  KC_NO,
                  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
  KC_NO,  KC_NO,
  KC_NO, OSL(6),  KC_NO,
  KC_NO,  KC_NO,  KC_NO
)
};


/////////////////////////////////////
// BEGIN custom tap-hold dancing PT 2

/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted || !state->pressed) return DOUBLE_TAP;
        else return DOUBLE_HOLD;
    } else if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TRIPLE_TAP;
        else return TRIPLE_HOLD;
    } else return 8;
}

// Create an instance of 'tap' for the 'r1' tap dance.
static tap r1_tap_state = {
    .is_press_action = true,
    .state = 0
};

void r1_finished(qk_tap_dance_state_t *state, void *user_data) {
    r1_tap_state.state = cur_dance(state);
    switch (r1_tap_state.state) {
        case SINGLE_TAP: register_code(KC_1); break;
        case SINGLE_HOLD: register_code(KC_2); break;
        case DOUBLE_TAP: register_code(KC_3); break;
        case DOUBLE_HOLD: register_code(KC_4); break;
        case TRIPLE_TAP: register_code(KC_5); break;
        case TRIPLE_HOLD: register_code(KC_6); break;
    }
}

void r1_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (r1_tap_state.state) {
        case SINGLE_TAP: unregister_code(KC_1); break;
        case SINGLE_HOLD: unregister_code(KC_2); break;
        case DOUBLE_TAP: unregister_code(KC_3); break;
        case DOUBLE_HOLD: unregister_code(KC_4); break;
        case TRIPLE_TAP: unregister_code(KC_5); break;
        case TRIPLE_HOLD: unregister_code(KC_6); break;
    }
    r1_tap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [R1_TAP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, r1_finished, r1_reset)
};

// BEGIN custom tap-hold dancing PT 2
/////////////////////////////////////

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

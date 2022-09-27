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
  _ARROWS,     // Keymap 5: Arrow Layer
  _FPS         // fps-oriented layout
};

#define RGB_DI_PIN D3
#define RGBLED_NUM 20

// shortcuts
# define KC_LS KC_LSFT
# define KC_RS KC_RSFT
# define NBSPC X(NBSP)
# define ZWSPC X(ZWSP)
# define X_DEG X(DEGREE)
# define XP_AC XP(ACIRCL, ACIRCU)
# define XP_AE XP(AELIGL, AELIGU)
# define XP_AG XP(AGRAVL, AGRAVU)
# define XP_AU XP(AUMLL, AUMLU)
# define XP_CC XP(CCEDL, CCEDU)
# define XP_EA XP(EACUTEL, EACUTEU)
# define XP_EC XP(ECIRCL, ECIRCU)
# define XP_EG XP(EGRAVL, EGRAVU)
# define X_ELI X(ELLIPS)
# define XP_EU XP(EUMLL, EUMLU)
# define X_EUR X(EURO)
# define XP_IC XP(ICIRCL, ICIRCU)
# define XP_IU XP(IUMLL, IUMLU)
# define XP_NT XP(NTLDL, NTLDU)
# define XP_OC XP(OCIRCL,OCIRCU)
# define XP_OE XP(OELIGL,OELIGU)
# define XP_OU XP(OUMLL, OUMLU)
# define XP_UC XP(UCIRCL, UCIRCU)
# define XP_UG XP(UGRAVL, UGRAVU)
# define XP_UU XP(UUMLL, UUMLU)
# define SNTAB LCTL(KC_PGDOWN)
# define SPTAB LCTL(KC_PGUP)
# define A_LSH LSFT_T(KC_A)
# define S_CTL LCTL_T(KC_S)
# define D_ALT LALT_T(KC_D)
# define F_L1 LT(1, KC_F)
# define G_L3 LT(3, KC_G)
# define H_L3 LT(3, KC_H)
# define J_L1 LT(1, KC_J)
# define K_ALT LALT_T(KC_K)
# define L_CTL RCTL_T(KC_L)
# define SC_RSH RSFT_T(KC_SCLN)

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
  DEGREE,
  EACUTEL,
  EACUTEU,
  ECIRCL,
  ECIRCU,
  EGRAVL,
  EGRAVU,
  ELLIPS,
  EUMLL,
  EUMLU,
  EURO,
  ICIRCL,
  ICIRCU,
  IUMLL,
  IUMLU,
  NBSP,
  NTLDL,
  NTLDU,
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
  UUMLU,
  ZWSP
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
  [DEGREE]  = 0x00B0,
  [EACUTEL] = 0x00E9,
  [EACUTEU] = 0x00C9,
  [ECIRCL]  = 0x00EA,
  [ECIRCU]  = 0x00CA,
  [EGRAVL]  = 0x00E8,
  [EGRAVU]  = 0x00C8,
  [ELLIPS]  = 0x2026,
  [EUMLL]   = 0x00EB,
  [EUMLU]   = 0x00CB,
  [EURO]    = 0x20AC,
  [ICIRCL]  = 0x00EE,
  [ICIRCU]  = 0x00CE,
  [IUMLL]   = 0x00EF,
  [IUMLU]   = 0x00CF,
  [NBSP]    = 0x00A0,
  [NTLDL]   = 0x00F1,
  [NTLDU]   = 0x00D1,
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
  [ZWSP]    = 0x200B
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * 0 - QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   Tab  |  Q   |  W   |  E   |  R   |  T   |                              |   Y  |   U  |   I  |   O  |   P  |  \ |   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | A/LSh| S/Ctl| D/Alt| F/Sym| G/Acc|                              | H/Acc| J/Sym| K/Alt| L/Ctl|;:/RSh|  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  Z   |  X   |  C   |  V   |  B   |  Esc |  Del |  |      | CLck |   N  |   M  | ,  < | . >  | /  ? |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | *L5  |  OS  | Space|BckSpc|  |  *L4 | Enter|  OS  | *L2  | Mute |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT(
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS,
      _______,   A_LSH,   S_CTL,   D_ALT,    F_L1,    G_L3,                                        H_L3,    J_L1,   K_ALT,   L_CTL,  SC_RSH, KC_QUOT,
      _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_ESC,  KC_DEL, _______, KC_CLCK,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, _______,
                                 _______,   TT(5), KC_LGUI,  KC_SPC, KC_BSPC,   TT(4),  KC_ENT, KC_LGUI,   TT(2), KC_MUTE
    ),
/*
 * 1 - Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | PrtScr |   !  |   @  |   {  |   }  |   |  |                              |   &  |   7  |   8  |   9  |   *  | NumLck |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  ZwSpc |   #  |   $  |   (  |   )  |   `  |                              |   -  |   4  |   5  |   6  |   +  | Insert |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  NbSpc |   %  |   ^  |   [  |   ]  |   ~  |      |      |  |      |      |   _  |   1  |   2  |   3  |   =  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |   0  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_SYMBOLS] = LAYOUT(
      KC_PSCR, KC_EXLM,   KC_AT, KC_LCBR, KC_RCBR, KC_PIPE,                                     KC_AMPR,    KC_7,    KC_8,    KC_9, KC_PAST, KC_NLCK,
        ZWSPC, KC_HASH,  KC_DLR, KC_LPRN, KC_RPRN,  KC_GRV,                                     KC_MINS,    KC_4,    KC_5,    KC_6, KC_PPLS,  KC_INS,
        NBSPC, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, _______, _______, _______, KC_UNDS,    KC_1,    KC_2,    KC_3,  KC_EQL, _______,
                                 _______, _______, _______, _______, _______, _______, _______,    KC_0, _______, _______
    ),
/*
 * 2 - Media & Mouse
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      | MsWhL| MsUp |MsWhR |MsWhUp|                              |  F1  |  F2  |  F3  |  F4  |  F5  |   F6   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|MsWhDn|                              |  F7  |  F8  |  F9  | F10  | F11  |  F12   |
 * |--------+------+------+------+------+------|-------------.  ,-------------|------+------+------+------+------+--------|
 * |        | LCtl | LAlt |      |      |      |BBack | BFwd |  |      |      |      | Mute |VolDn |VolUp |      |        |
 * `----------------------+------+------+------+------|------|  |------+------+------+------+------+----------------------'
 *                        |      |      | MClk | LClk | RClk |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
     [_MEDIA] = LAYOUT(
       _______, _______, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,                                       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                                       KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
       _______, KC_LCTL, KC_LALT, _______, _______, _______, KC_WBAK, KC_WFWD, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,
                                  _______, _______, KC_BTN3, KC_BTN1, KC_BTN2, _______, _______, _______, _______, _______
     ),
/*
 * 3 - Fucking french accented chars
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | Æ  æ | Ê  ê | É  é | È  è |   °  |                              | Û  û | Ù  ù | Î  î | Ô  ô | Œ  œ |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | À  à | Â  â | Ë  ë |    € |      |                              |      | Ü  ü | Ï  ï | Ö  ö |      |        |
 * |--------+------+------+------+------+------|-------------.  ,-------------|------+------+------+------+------+--------|
 * |        | Ä  ä |      | Ç  ç |      |      |      |      |  |      |      | Ñ  ñ |      |      |   …  |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
     [_FRENCH] = LAYOUT(
       _______,   XP_AE,   XP_EC,   XP_EA,   XP_EG,   X_DEG,                                       XP_UC,   XP_UG,   XP_IC,   XP_OC,   XP_OE, _______,
       _______,   XP_AG,   XP_AC,   XP_EU,   X_EUR, _______,                                     _______,   XP_UU,   XP_IU,   XP_OU, _______, _______,
       _______,   XP_AU, _______,   XP_CC, _______, _______, _______, _______, _______, _______,   XP_NT, _______, _______,   X_ELI, _______, _______,
                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
     ),
/*
 * 4 - Arrows & Movements
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
                                  _______, _______, _______, _______, _______,   TG(4), _______, _______, _______, _______
     ),
/*
 * 5 - FPS (classic QWERTY)
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
         KC_LS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_ESC,  KC_DEL,   TG(5), _______,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   KC_RS,
                                  _______, _______, _______,  KC_SPC, KC_BSPC, _______, _______, _______, _______, _______
     ),
/*
 * Ideas for an emoji layer:
 * :wink:        U+1F609 😉
 * :thumbsup:    U+1F44D 👍
 * :thumbsdown:  U+1F44E 👎
 * :slightsmile: U+1F642 🙂
 */

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
        case _ARROWS:
            oled_write_P(PSTR("Arrows\n"), false);
            break;
        case _FPS:
            oled_write_P(PSTR("FPS\n"), false);
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
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Page up/Page down
        if (clockwise) {
            tap_code16(KC_BRIGHTNESS_UP);
        } else {
            tap_code16(KC_BRIGHTNESS_DOWN);
        }
    }
    else if (index == 1) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}
#endif

#ifdef RGBLIGHT_ENABLE
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 20, HSV_RED}
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 3, HSV_CYAN},
    { 9, 1, HSV_CYAN},
    {10, 1, HSV_CYAN},
    {17, 3, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 3, HSV_PURPLE},
    { 9, 1, HSV_PURPLE},
    {10, 1, HSV_PURPLE},
    {17, 3, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 3, HSV_GREEN},
    { 9, 1, HSV_GREEN},
    {10, 1, HSV_GREEN},
    {17, 3, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 3, HSV_ORANGE},
    { 9, 1, HSV_ORANGE},
    {10, 1, HSV_ORANGE},
    {17, 3, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM my_layer6_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 3, HSV_PINK},
    { 9, 1, HSV_PINK},
    {10, 1, HSV_PINK},
    {17, 3, HSV_PINK}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer, // Overrides caps lock layer
    my_layer2_layer,   // Overrides other layers
    my_layer3_layer,
    my_layer4_layer,
    my_layer5_layer,
    my_layer6_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

// Now reacting to user input
bool led_update_user(led_t led_state) {
    // Reacting to caps lock status change
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    // Default layer lighting
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Layer activations
    rgblight_set_layer_state(1, layer_state_cmp(state, _SYMBOLS));
    rgblight_set_layer_state(2, layer_state_cmp(state, _MEDIA));
    rgblight_set_layer_state(3, layer_state_cmp(state, _FRENCH));
    rgblight_set_layer_state(4, layer_state_cmp(state, _ARROWS));
    rgblight_set_layer_state(5, layer_state_cmp(state, _FPS));
    return state;
}
#endif

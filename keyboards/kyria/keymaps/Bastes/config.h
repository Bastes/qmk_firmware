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

#pragma once

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  #define RGBLIGHT_EFFECT_TWINKLE
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8

  #define RGBLIGHT_LAYERS
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK

#define UNICODE_SELECTED_MODES UC_LNX


#define MOUSEKEY_INTERVAL       20
#define MOUSEKEY_DELAY          0
#define MOUSEKEY_TIME_TO_MAX    240
#define MOUSEKEY_MAX_SPEED      120
#define MOUSEKEY_WHEEL_DELAY    0

#define TAPPING_TOGGLE 2 // triple-tap to toggle

#define TAPPING_TERM 200
#define IGNORE_MOD_TAP_INTERRUPT // this makes it possible to do rolling combos (zx) with keys that convert to other keys on hold (z becomes ctrl when you hold it, and when this option isn't enabled, z rapidly followed by x actually sends Ctrl-x. That's bad.)


#define RGBLIGHT_LAYERS
#define RGBLIGHT_LED_MAP { 0, 1, 2, 9, 8, 7, 4, 3, 5, 6, 19, 18, 17, 10, 11, 12, 15, 16, 14, 13 }

// Using the right side as the master
#define MASTER_RIGHT

// Using rotary encoders
#define ENCODER_RESOLUTION 2

/*
Copyright 2021 benkyriakou

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0xFEED
#define PRODUCT_ID   0x0000
#define DEVICE_VER   0x0001
#define MANUFACTURER bk6u
#define PRODUCT      knob

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 1

/* Uno default pinout */
#define MATRIX_ROW_PINS { D7 }
#define MATRIX_COL_PINS { B1 }
#define DIODE_DIRECTION COL2ROW
#define UNUSED_PINS

#define ENCODERS_PAD_A { D1 }
#define ENCODERS_PAD_B { F4 }
#define ENCODER_DIRECTION_FLIP
#define ENCODER_RESOLUTION 3

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#define RGB_DI_PIN E6
#define RGBLED_NUM 4
#define RGBLIGHT_ANIMATIONS

#define TAPPING_TERM 200

/* Copyright 2021 benkyriakou
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

enum custom_keycodes {
  KC_MYMEDIA = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_MYMEDIA),
};

void encoder_update_user(int8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_AUDIO_VOL_UP);
    } else {
      tap_code(KC_AUDIO_VOL_DOWN);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  static uint16_t my_hash_timer;

  switch (keycode) {
    case KC_MYMEDIA:
      if(record->event.pressed) {
        my_hash_timer = timer_read();
      } else {
        if (timer_elapsed(my_hash_timer) > TAPPING_TERM) {
          // Do long press keycode
          rgblight_toggle();
        }
        else {
          // Do short press keycode
          tap_code16(KC_MEDIA_PLAY_PAUSE);
        }
      }
      return false; // We handled this keypress
  }
  return true; // We didn't handle other keypresses
}

#ifdef RGBLIGHT_ENABLE
void keyboard_post_init_user(void) {
  rgblight_enable();
  rgblight_mode(RGBLIGHT_MODE_RAINBOW_MOOD);
  rgblight_decrease_val_noeeprom();
  rgblight_decrease_val_noeeprom();
}
#endif

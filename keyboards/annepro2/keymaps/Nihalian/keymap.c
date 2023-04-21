 /* Copyright 2021 OpenAnnePro community
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

enum my_keycodes {
  MY_RGB_TOG = SAFE_RANGE
};

enum anne_pro_layers {
    BASE,
    FN1,
    FN2,
};

// clang-format off
// Key symbols are based on QMK. Use them to remap your keyboard
/*
* Layer BASE
* ,-----------------------------------------------------------------------------------------.
* | esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* |  FN1    |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |     FN2     |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in BASE
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* | Caps    |     |     |     |     |     |     |     |     |     |     |     |    ENTER    |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |       UP       |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |                                 |       |  LEFT | DOWN  | RIGHT |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [BASE] = LAYOUT_60_ansi( /* Base */
    KC_ESC,           KC_1,    KC_2,    KC_3, KC_4, KC_5, KC_6,   KC_7, KC_8, KC_9,    KC_0,             KC_MINS,          KC_EQL,        KC_BSPC,
    KC_TAB,           KC_Q,    KC_W,    KC_E, KC_R, KC_T, KC_Y,   KC_U, KC_I, KC_O,    KC_P,             KC_LBRC,          KC_RBRC,       KC_BSLS,
    LT(FN1, KC_CAPS), KC_A,    KC_S,    KC_D, KC_F, KC_G, KC_H,   KC_J, KC_K, KC_L,    KC_SCLN,          KC_QUOT,          LT(FN2, KC_ENT),
    KC_LSFT,                   KC_Z,    KC_X, KC_C, KC_V, KC_B,   KC_N, KC_M, KC_COMM, KC_DOT,           KC_SLSH,          RSFT_T(KC_UP),
    KC_LCTL,          KC_LGUI, KC_LALT,                   KC_SPC,             KC_RALT, LT(FN1, KC_LEFT), LT(FN2, KC_DOWN), RCTL_T(KC_RGHT)
),
  /*
  * Layer FN1
  * ,-----------------------------------------------------------------------------------------.
  * |  `  |  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  | UP  |  e  |  r  |  t  |  y  |  u  |  i  |  o  | PS | HOME | END |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Caps    |LEFT |DOWN |RIGHT|  f  |  g  |  h  |  j  |  k  |  l  | PGUP|PGDN |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |V-UP |V-DWN|MUTE |  v  |  b  |  n  |  m  |  ,  |INSRT| DEL |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/ *
  */
 [FN1] = LAYOUT_60_ansi( /* FN1 */
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,
    _______, _______, KC_UP,   _______, _______, _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_PSCR, KC_HOME, KC_END,  _______,
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_PGUP, KC_PGDN, _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,  KC_DEL,  _______,
    _______, _______, _______,                            _______,                   _______, _______, TG(FN2), _______
),
  /*
  * Layer FN2
  * ,-----------------------------------------------------------------------------------------.
  * |  ~  | BT1 | BT2 | BT3 | BT4 |  5  |  6  |  7 |  8 | MOD | TOG | BRI- | BRI+ |    Bksp   |
  * |-----------------------------------------------------------------------------------------+
  * | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p |  [   |  ]  |   \    |
  * |-----------------------------------------------------------------------------------------+
  * | Caps    |  a  |  s  |  d  |  f  |  g  |  h  |B-DWN|B-UP |  l  |  ;  |  '  |    Enter    |
  * |-----------------------------------------------------------------------------------------+
  * | Shift      |  z  |  x  |  c  |V-DWN|V-UP |MUTE |  m  |  ,  |  .  |  /  |    Shift       |
  * |-----------------------------------------------------------------------------------------+
  * | Ctrl  |  L1   |  Alt  |               space             |  Alt  |  FN1  |  FN2  | Ctrl  |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [FN2] = LAYOUT_60_ansi( /* FN2 */
    _______, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, _______, _______, _______, _______, KC_AP_RGB_MOD, MY_RGB_TOG,       KC_AP_RGB_VAD, KC_AP_RGB_VAI, _______,
    _______, _______,    _______,    _______,    _______,    _______, _______, _______, _______, _______,       _______,       _______,       _______,       _______,
    _______, _______,    _______,    _______,    _______,    _______, _______, KC_BRID, KC_BRIU, _______,       _______,       _______,       _______,
    _______,             _______,    _______,    _______,    KC_VOLD, KC_VOLU, KC_MUTE, _______, _______,       _______,       _______,       _______,
    _______, _______,    _______,                                     _______,                   _______,       TG(FN1),       _______,       _______
 ),
};
// clang-format on

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) { uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_RED);
                }
            }
        }
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MY_RGB_TOG:
      if (record->event.pressed) {
        // Do something when pressed
        HSV hsv = rgb_matrix_get_hsv();
        if (get_mods() & MOD_MASK_SHIFT) {
          rgb_matrix_increase_speed_noeeprom();
          return false;
        } else if (get_mods() & MOD_MASK_CTRL) {
          rgb_matrix_decrease_speed_noeeprom();
          return false;
        } else {
          if (hsv.v == 0) {
            rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, 255);
          } else {
            rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, 0);
          }
            return false;
        }
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}


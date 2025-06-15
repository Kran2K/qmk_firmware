/* Copyright 2022 @ Keychron (https://www.keychron.com)
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
#include "quantum.h"

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

#define FN_F4_TOGGLE SAFE_RANGE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_tkl_f13_ansi(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_NO,    KC_NO,    RM_VALD,  RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    KC_MUTE,  KC_NO,    KC_NO,    RM_NEXT,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RCMD,  KC_ROPT,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_tkl_f13_ansi(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     RM_TOGG,  _______,  _______,  RM_TOGG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_tkl_f13_ansi(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,  KC_PSCR,  KC_NO,    RM_NEXT,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_tkl_f13_ansi(
        _______,  KC_BRID,  KC_BRIU,  _______,  FN_F4_TOGGLE,  RM_VALD,  RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RM_TOGG,  _______,  _______,  RM_TOGG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = {ENCODER_CCW_CW(RM_VALD, RM_VALU) },
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = {ENCODER_CCW_CW(RM_VALD, RM_VALU) }
};
#endif // ENCODER_MAP_ENABLE

bool strafe_enabled = false;

typedef struct {
    bool active;
    uint16_t start_time;
    uint16_t duration;
    uint16_t keycode;
    bool key_sent;
} async_key_t;

async_key_t async = {0};

bool w_down = false;
bool s_down = false;

bool user_override_w = false;
bool user_override_s = false;

uint16_t w_pressed_time = 0;
uint16_t s_pressed_time = 0;

bool is_mid_air = false;
uint16_t mid_air_start_time = 0;

float getCounterStrafeHoldTime(float ms) {
    if (ms < 80.0f) return 0.0f;
    if (ms > 560.0f) return 115.0f;
    return -0.00034f * ms * ms + 0.355f * ms + 25.5f;
}

bool is_lalt_pressed(void) {
    return get_mods() & MOD_BIT(KC_LALT);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == FN_F4_TOGGLE && record->event.pressed) {
        strafe_enabled = !strafe_enabled;
        return false;
    }

    if (!strafe_enabled) return true;

    if (keycode == KC_SPC && record->event.pressed) {
        is_mid_air = true;
        mid_air_start_time = timer_read();
        return true;
    }

    if (keycode == KC_W) {
        if (record->event.pressed) {
            user_override_w = true;
        } else {
            user_override_w = false;
        }
    }
    if (keycode == KC_S) {
        if (record->event.pressed) {
            user_override_s = true;
        } else {
            user_override_s = false;
        }
    }

    if (keycode == KC_W || keycode == KC_S) {
        bool is_w = keycode == KC_W;
        bool is_pressed = record->event.pressed;

        if (is_pressed) {
            if (is_w) {
                w_pressed_time = timer_read();
                w_down = true;
            } else {
                s_pressed_time = timer_read();
                s_down = true;
            }
        } else {
            if (is_w) {
                w_down = false;
            } else {
                s_down = false;
            }

            if (is_lalt_pressed()) return true;
            if (is_mid_air) return true;

            bool opposite_pressed = is_w ? s_down : w_down;
            if (opposite_pressed) return true;

            uint16_t held_time = (keycode == KC_W) ? timer_elapsed(w_pressed_time)
                                                   : timer_elapsed(s_pressed_time);
            uint16_t press_duration = getCounterStrafeHoldTime(held_time);

            async.active = true;
            async.start_time = timer_read();
            async.duration = press_duration;
            async.keycode = (keycode == KC_W) ? KC_S : KC_W;
            async.key_sent = false;
        }
    }

    return true;
}

void matrix_scan_user(void) {
    if (is_mid_air && timer_elapsed(mid_air_start_time) > 650) {
        is_mid_air = false;
    }

    if (!async.active) return;

    uint16_t elapsed = timer_elapsed(async.start_time);

    if (!async.key_sent && elapsed >= 0) {
        register_code(async.keycode);
        async.key_sent = true;
    }

    if (async.key_sent && elapsed >= async.duration) {
        bool user_holding =
            (async.keycode == KC_W && user_override_w) ||
            (async.keycode == KC_S && user_override_s);

        if (!user_holding) {
            unregister_code(async.keycode);
        }

        async.active = false;
    }
}
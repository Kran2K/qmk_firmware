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

async_key_t ws_async = {0};
async_key_t ad_async = {0};

bool w_down = false;
bool s_down = false;
bool user_override_w = false;
bool user_override_s = false;
uint16_t w_pressed_time = 0;
uint16_t s_pressed_time = 0;

bool a_down = false;
bool d_down = false;
bool user_override_a = false;
bool user_override_d = false;
uint16_t a_pressed_time = 0;
uint16_t d_pressed_time = 0;

bool is_mid_air = false;
uint16_t mid_air_start_time = 0;

bool is_lalt_pressed(void) {
    return get_mods() & MOD_BIT(KC_LALT);
}

float getCounterStrafeHoldTime(float ms, bool is_ws_axis) {
    float min_threshold = is_ws_axis ? 80.0f  : 150.0f;
    float max_threshold = 560.0f;
    float max_output    = 115.0f;

    if (ms < min_threshold) return 0.0f;
    if (ms > max_threshold) return max_output;

    return -0.00034f * ms * ms + 0.355f * ms + 25.5f;
}

void trigger_counter_strafe(uint16_t held_key, uint16_t held_time, bool is_ws_axis) {
    uint16_t counter_key = (held_key == KC_W) ? KC_S :
                           (held_key == KC_S) ? KC_W :
                           (held_key == KC_A) ? KC_D : KC_A;

    uint16_t press_duration = getCounterStrafeHoldTime(held_time, is_ws_axis);

    async_key_t *target_async = is_ws_axis ? &ws_async : &ad_async;

    target_async->active = true;
    target_async->start_time = timer_read();
    target_async->duration = press_duration;
    target_async->keycode = counter_key;
    target_async->key_sent = false;
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
            w_pressed_time = timer_read();
            w_down = true;
        } else {
            user_override_w = false;
            w_down = false;
            if (s_down) {
                s_pressed_time = timer_read();
            }
            
            // 키를 뗄 때 카운터 스트레이프 로직
            if (!is_lalt_pressed() && !is_mid_air && !s_down) {
                uint16_t held_time = timer_elapsed(w_pressed_time);
                trigger_counter_strafe(KC_W, held_time, true);
            }
        }
    }
    
    if (keycode == KC_S) {
        if (record->event.pressed) {
            user_override_s = true;
            s_pressed_time = timer_read();
            s_down = true;
        } else {
            user_override_s = false;
            s_down = false;
            if (w_down) {
                w_pressed_time = timer_read();
            }
            
            // 키를 뗄 때 카운터 스트레이프 로직
            if (!is_lalt_pressed() && !is_mid_air && !w_down) {
                uint16_t held_time = timer_elapsed(s_pressed_time);
                trigger_counter_strafe(KC_S, held_time, true);
            }
        }
    }

    if (keycode == KC_A) {
        if (record->event.pressed) {
            user_override_a = true;
            a_pressed_time = timer_read();
            a_down = true;
        } else {
            user_override_a = false;
            a_down = false;
            if (d_down) {
                d_pressed_time = timer_read();
            }
            
            // 키를 뗄 때 카운터 스트레이프 로직
            if (!is_lalt_pressed() && !is_mid_air && !d_down && !ad_async.active) {
                uint16_t held_time = timer_elapsed(a_pressed_time);
                trigger_counter_strafe(KC_A, held_time, false);
            }
        }
    }
    
    if (keycode == KC_D) {
        if (record->event.pressed) {
            user_override_d = true;
            d_pressed_time = timer_read();
            d_down = true;
        } else {
            user_override_d = false;
            d_down = false;
            if (a_down) {
                a_pressed_time = timer_read();
            }
            
            // 키를 뗄 때 카운터 스트레이프 로직
            if (!is_lalt_pressed() && !is_mid_air && !a_down && !ad_async.active) {
                uint16_t held_time = timer_elapsed(d_pressed_time);
                trigger_counter_strafe(KC_D, held_time, false);
            }
        }
    }

    return true;
}

void matrix_scan_user(void) {
    if (is_mid_air && timer_elapsed(mid_air_start_time) > 650) {
        is_mid_air = false;
    }

    // W/S async 처리
    if (ws_async.active) {
        uint16_t elapsed = timer_elapsed(ws_async.start_time);

        if (!ws_async.key_sent && elapsed >= 0) {
            register_code(ws_async.keycode);
            ws_async.key_sent = true;
        }

        if (ws_async.key_sent && elapsed >= ws_async.duration) {
            bool user_holding =
                (ws_async.keycode == KC_W && user_override_w) ||
                (ws_async.keycode == KC_S && user_override_s);

            if (!user_holding) {
                unregister_code(ws_async.keycode);
            }

            ws_async.active = false;
        }
    }

    // A/D async 처리
    if (ad_async.active) {
        uint16_t elapsed = timer_elapsed(ad_async.start_time);

        if (!ad_async.key_sent && elapsed >= 0) {
            register_code(ad_async.keycode);
            ad_async.key_sent = true;
        }

        if (ad_async.key_sent && elapsed >= ad_async.duration) {
            bool user_holding =
                (ad_async.keycode == KC_A && user_override_a) ||
                (ad_async.keycode == KC_D && user_override_d);

            if (!user_holding) {
                unregister_code(ad_async.keycode);
            }

            ad_async.active = false;
        }
    }
}
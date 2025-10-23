
/* Copyright 2024 @ Keychron (https://www.keychron.com)
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

 // qmk compile -kb keychron/q3_he/ansi_encoder -km counter_strafer

#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
};

enum custom_keycodes {
    CS_A = SAFE_RANGE,
    CS_D,
    CS_W,
    CS_S,
    FN_DEL_TOGGLE,
    FN_END_TOGGLE,
    FN_PGDN_TOGGLE,
};

#define FN_MAC MO(MAC_FN)
#define FN_WIN MO(WIN_FN)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_87(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MUTE,   KC_SNAP,  KC_SIRI,  RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,   KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,   KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,             KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN, FN_MAC,   KC_RCTL,   KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_87(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   RGB_TOG,   _______,  _______,  RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   FN_DEL_TOGGLE,  FN_END_TOGGLE,  FN_PGDN_TOGGLE,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,             _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,   _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_87(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_MUTE,   KC_PSCR,  KC_CTANA, RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,   KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     CS_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,   KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  CS_A,     CS_S,     CS_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,             KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  FN_WIN,   KC_RCTL,   KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_87(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_TOG,   _______,  _______,  RGB_TOG,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   FN_DEL_TOGGLE,  FN_END_TOGGLE,  FN_PGDN_TOGGLE,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,             _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______,   _______,  _______,  _______),
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif // ENCODER_MAP_ENABLE

typedef enum {
    AD_CS_STATE_IDLE,      // 아무것도 안 눌림
    AD_CS_STATE_A_HELD,    // A만 눌림
    AD_CS_STATE_D_HELD,    // D만 눌림
    AD_CS_STATE_BOTH_HELD, // A, D 둘 다 눌림
    AD_CS_STATE_A_AUTO,    // 펌웨어가 A를 자동으로 누르는 중 (카운터 스트레이핑)
    AD_CS_STATE_D_AUTO,    // 펌웨어가 D를 자동으로 누르는 중 (카운터 스트레이핑)
} ad_cs_state_t;

typedef enum {
    WS_CS_STATE_IDLE,
    WS_CS_STATE_W_HELD,
    WS_CS_STATE_S_HELD,
    WS_CS_STATE_BOTH_HELD,
    WS_CS_STATE_W_AUTO,
    WS_CS_STATE_S_AUTO,
} ws_cs_state_t;

#define BOTH_HELD_PADDING_MS 80
#define ALT_DELAY_MS 1500
#define RAPID_FIRE_MIN_MS 135
#define RAPID_FIRE_MAX_MS 145

static bool strafe_enabled = false;
static bool rapid_fire_enabled = false;
static bool gaming_mode_enabled = false;

// AD Strafe
static ad_cs_state_t ad_cs_state = AD_CS_STATE_IDLE;
static uint16_t a_key_timer           = 0;
static uint16_t d_key_timer           = 0;
static uint16_t auto_cs_hold_duration = 0;
static uint32_t auto_cs_timer_start   = 0;
static bool     a_physical_pressed    = false;
static bool     d_physical_pressed    = false;
static uint16_t both_held_timer       = 0;

// WS Strafe
static ws_cs_state_t ws_cs_state = WS_CS_STATE_IDLE;
static uint16_t w_key_timer              = 0;
static uint16_t s_key_timer              = 0;
static uint16_t auto_ws_cs_hold_duration = 0;
static uint32_t auto_ws_cs_timer_start   = 0;
static bool     w_physical_pressed       = false;
static bool     s_physical_pressed       = false;
static uint16_t ws_both_held_timer       = 0;

// Mid-air detection
static bool     is_mid_air         = false;
static uint16_t mid_air_start_time = 0;

// ALT delay tracking
static uint32_t alt_release_time = 0;

// Rapid fire C key
static bool     c_physical_pressed = false;
static uint32_t c_last_fire_time = 0;
static uint16_t c_next_interval = RAPID_FIRE_MIN_MS;

uint16_t getCounterStrafeHoldTime(uint16_t ms, bool is_ws_axis) {
    uint16_t min_threshold = is_ws_axis ? 70.0  : 100.0;
    uint16_t max_threshold = 560;
    uint16_t max_output    = 115;

    if (ms < min_threshold) return 0;
    if (ms > max_threshold) return max_output;

    float res = -0.00034f * ms * ms + 0.355f * ms + 25.5f; // empirically tuned

    return (uint16_t)res;
}

bool should_disable_counter_strafe(void) {
    if (timer_elapsed32(alt_release_time) < ALT_DELAY_MS) {
        return true;
    } 

    bool lalt_pressed = get_mods() & MOD_BIT(KC_LALT);
    
    if (lalt_pressed) {
        return true;
    }
    
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Track ALT release
    if (keycode == KC_LALT && !record->event.pressed) {
        alt_release_time = timer_read32();
    }

    // Gaming mode filter
    if (gaming_mode_enabled) {
        if (keycode == KC_GRV || keycode == KC_LWIN || keycode == KC_RWIN) {
            return false;
        }
    }

    // Toggle handlers
    if (record->event.pressed) {
        switch (keycode) {
            case FN_DEL_TOGGLE:
                strafe_enabled = !strafe_enabled;
                return false;
            case FN_END_TOGGLE:
                rapid_fire_enabled = !rapid_fire_enabled;
                return false;
            case FN_PGDN_TOGGLE:
                gaming_mode_enabled = !gaming_mode_enabled;
                return false;
            default:
                break;
        }
    }

    if (keycode == KC_SPC && record->event.pressed) {
        is_mid_air = true;
        mid_air_start_time = timer_read();
    }

    // Rapid fire C key
    if (keycode == KC_C) {
        if (record->event.pressed) {
            c_physical_pressed = true;
            if (rapid_fire_enabled) {
                register_code(KC_C);
                c_last_fire_time = timer_read32();
                c_next_interval = RAPID_FIRE_MIN_MS + (rand() % (RAPID_FIRE_MAX_MS - RAPID_FIRE_MIN_MS + 1));
                return false;
            }
        } else {
            c_physical_pressed = false;
            if (rapid_fire_enabled) {
                unregister_code(KC_C);
                return false;
            }
        }
        return true;
    }

    if (!strafe_enabled) {
        switch (keycode) {
            case CS_A: if (record->event.pressed) register_code(KC_A); else unregister_code(KC_A); return false;
            case CS_D: if (record->event.pressed) register_code(KC_D); else unregister_code(KC_D); return false;
            case CS_W: if (record->event.pressed) register_code(KC_W); else unregister_code(KC_W); return false;
            case CS_S: if (record->event.pressed) register_code(KC_S); else unregister_code(KC_S); return false;
            default: break;
        }
        return true;
    }

    switch (keycode) {
        case CS_A:
            if (record->event.pressed) {
                a_physical_pressed = true;
                switch (ad_cs_state) {
                    case AD_CS_STATE_IDLE:
                        ad_cs_state = AD_CS_STATE_A_HELD;
                        break;
                    case AD_CS_STATE_D_HELD:
                        both_held_timer = timer_read(); // BOTH 상태 진입 시 타이머 시작
                        ad_cs_state = AD_CS_STATE_BOTH_HELD;
                        break;
                    case AD_CS_STATE_D_AUTO:
                        unregister_code(KC_D);
                        ad_cs_state = AD_CS_STATE_A_HELD;
                        break;
                    default:
                        break;
                }
                a_key_timer = timer_read();
                register_code(KC_A);
            } else {
                a_physical_pressed = false;
                if (ad_cs_state == AD_CS_STATE_A_AUTO) return false;
                unregister_code(KC_A);
                switch (ad_cs_state) {
                    case AD_CS_STATE_A_HELD: {
                        uint16_t held_time = timer_elapsed(a_key_timer);
                        auto_cs_hold_duration = getCounterStrafeHoldTime(held_time, false);
                        if (auto_cs_hold_duration > 0) {
                            ad_cs_state = AD_CS_STATE_D_AUTO;
                            auto_cs_timer_start = timer_read32();
                            if (!is_mid_air && !should_disable_counter_strafe()) {
                                register_code(KC_D);
                            }
                        } else {
                            ad_cs_state = AD_CS_STATE_IDLE;
                        }
                        break;
                    }
                    case AD_CS_STATE_BOTH_HELD: {
                        uint16_t both_held_time = timer_elapsed(both_held_timer);
                        if (both_held_time <= BOTH_HELD_PADDING_MS) {
                            // 짧은 시간 BOTH였다면 D_AUTO 진입
                            // uprintf("ignoring short both state!! both_held_time:%d\n", both_held_time);
                            ad_cs_state = AD_CS_STATE_D_AUTO;
                            // 이미 both_held_time 만큼 감속 했기 때문에 총 시간에서 both_held_time을 빼줌
                            auto_cs_hold_duration = MAX(0, getCounterStrafeHoldTime(timer_elapsed(a_key_timer), false) - both_held_time);
                            auto_cs_timer_start = timer_read32();
                            if (!is_mid_air && !should_disable_counter_strafe()) {
                                register_code(KC_D);
                            }
                        } else {
                            ad_cs_state = AD_CS_STATE_D_HELD;
                            d_key_timer = timer_read();
                        }
                        break;
                    }
                    default:
                        break;
                }
            }
            return false;

        case CS_D:
            if (record->event.pressed) {
                d_physical_pressed = true;
                switch (ad_cs_state) {
                    case AD_CS_STATE_IDLE:
                        ad_cs_state = AD_CS_STATE_D_HELD;
                        break;
                    case AD_CS_STATE_A_HELD:
                        both_held_timer = timer_read(); // BOTH 상태 진입 시 타이머 시작
                        ad_cs_state = AD_CS_STATE_BOTH_HELD;
                        break;
                    case AD_CS_STATE_A_AUTO:
                        unregister_code(KC_A);
                        ad_cs_state = AD_CS_STATE_D_HELD;
                        break;
                    default:
                        break;
                }
                d_key_timer = timer_read();
                register_code(KC_D);
            } else {
                d_physical_pressed = false;
                if (ad_cs_state == AD_CS_STATE_D_AUTO) return false;
                unregister_code(KC_D);
                switch (ad_cs_state) {
                    case AD_CS_STATE_D_HELD: {
                        uint16_t held_time = timer_elapsed(d_key_timer);
                        auto_cs_hold_duration = getCounterStrafeHoldTime(held_time, false);
                        if (auto_cs_hold_duration > 0) {
                            ad_cs_state = AD_CS_STATE_A_AUTO;
                            auto_cs_timer_start = timer_read32();
                            if (!is_mid_air && !should_disable_counter_strafe()) {
                                register_code(KC_A);
                            }
                        } else {
                            ad_cs_state = AD_CS_STATE_IDLE;
                        }
                        break;
                    }
                    case AD_CS_STATE_BOTH_HELD: {
                        uint16_t both_held_time = timer_elapsed(both_held_timer);
                        if (both_held_time <= BOTH_HELD_PADDING_MS) {
                            ad_cs_state = AD_CS_STATE_A_AUTO;
                            auto_cs_hold_duration = MAX(0, getCounterStrafeHoldTime(timer_elapsed(d_key_timer), false) - both_held_time);
                            auto_cs_timer_start = timer_read32();
                            if (!is_mid_air && !should_disable_counter_strafe()) {
                                register_code(KC_A);
                            }
                        } else {
                            ad_cs_state = AD_CS_STATE_A_HELD;
                            a_key_timer = timer_read();
                        }
                        break;
                    }
                    default:
                        break;
                }
            }
            return false;

        case CS_W:
            if (record->event.pressed) {
                w_physical_pressed = true;
                switch (ws_cs_state) {
                    case WS_CS_STATE_IDLE:
                        ws_cs_state = WS_CS_STATE_W_HELD;
                        break;
                    case WS_CS_STATE_S_HELD:
                        ws_cs_state = WS_CS_STATE_BOTH_HELD;
                        ws_both_held_timer = timer_read();
                        break;
                    case WS_CS_STATE_S_AUTO:
                        unregister_code(KC_S);
                        ws_cs_state = WS_CS_STATE_W_HELD;
                        break;
                    default:
                        break;
                }
                w_key_timer = timer_read();
                register_code(KC_W);
            } else {
                w_physical_pressed = false;
                if (ws_cs_state == WS_CS_STATE_W_AUTO) return false;
                unregister_code(KC_W);
                switch (ws_cs_state) {
                    case WS_CS_STATE_W_HELD: {
                        uint16_t held_time = timer_elapsed(w_key_timer);
                        auto_ws_cs_hold_duration = getCounterStrafeHoldTime(held_time, true);
                        if (auto_ws_cs_hold_duration > 0) {
                            ws_cs_state = WS_CS_STATE_S_AUTO;
                            auto_ws_cs_timer_start = timer_read32();
                            if (!is_mid_air && !should_disable_counter_strafe()) {
                                register_code(KC_S);
                            }
                        } else {
                            ws_cs_state = WS_CS_STATE_IDLE;
                        }
                        break;
                    }
                    case WS_CS_STATE_BOTH_HELD: {
                        uint16_t both_held_time = timer_elapsed(ws_both_held_timer);
                        if (both_held_time <= BOTH_HELD_PADDING_MS) {
                            ws_cs_state = WS_CS_STATE_S_AUTO;
                            auto_ws_cs_hold_duration = MAX(0, getCounterStrafeHoldTime(timer_elapsed(w_key_timer), true) - both_held_time);
                            auto_ws_cs_timer_start = timer_read32();
                            if (!is_mid_air && !should_disable_counter_strafe()) {
                                register_code(KC_S);
                            }
                        } else {
                            ws_cs_state = WS_CS_STATE_S_HELD;
                            s_key_timer = timer_read();
                        }
                        break;
                    }
                    default:
                        break;
                }
            }
            return false;

        case CS_S:
            if (record->event.pressed) {
                s_physical_pressed = true;
                switch (ws_cs_state) {
                    case WS_CS_STATE_IDLE:
                        ws_cs_state = WS_CS_STATE_S_HELD;
                        break;
                    case WS_CS_STATE_W_HELD:
                        ws_cs_state = WS_CS_STATE_BOTH_HELD;
                        ws_both_held_timer = timer_read();
                        break;
                    case WS_CS_STATE_W_AUTO:
                        unregister_code(KC_W);
                        ws_cs_state = WS_CS_STATE_S_HELD;
                        break;
                    default:
                        break;
                }
                s_key_timer = timer_read();
                register_code(KC_S);
            } else {
                s_physical_pressed = false;
                if (ws_cs_state == WS_CS_STATE_S_AUTO) return false;
                unregister_code(KC_S);
                switch (ws_cs_state) {
                    case WS_CS_STATE_S_HELD: {
                        uint16_t held_time = timer_elapsed(s_key_timer);
                        auto_ws_cs_hold_duration = getCounterStrafeHoldTime(held_time, true);
                        if (auto_ws_cs_hold_duration > 0) {
                            ws_cs_state = WS_CS_STATE_W_AUTO;
                            auto_ws_cs_timer_start = timer_read32();
                            if (!is_mid_air && !should_disable_counter_strafe()) {
                                register_code(KC_W);
                            }
                        } else {
                            ws_cs_state = WS_CS_STATE_IDLE;
                        }
                        break;
                    }
                    case WS_CS_STATE_BOTH_HELD: {
                        uint16_t both_held_time = timer_elapsed(ws_both_held_timer);
                        if (both_held_time <= BOTH_HELD_PADDING_MS) {
                            ws_cs_state = WS_CS_STATE_W_AUTO;
                            auto_ws_cs_hold_duration = MAX(0, getCounterStrafeHoldTime(timer_elapsed(s_key_timer), true) - both_held_time);
                            auto_ws_cs_timer_start = timer_read32();
                            if (!is_mid_air && !should_disable_counter_strafe()) {
                                register_code(KC_W);
                            }
                        } else {
                            ws_cs_state = WS_CS_STATE_W_HELD;
                            w_key_timer = timer_read();
                        }
                        break;
                    }
                    default:
                        break;
                }
            }
            return false;

        default:
            break;
    }
    return true;
}

void matrix_scan_user(void) {
    if (is_mid_air && timer_elapsed(mid_air_start_time) > 650) {
        is_mid_air = false;
    }

    // Rapid fire C key
    if (rapid_fire_enabled && c_physical_pressed) {
        if (timer_elapsed32(c_last_fire_time) >= c_next_interval) {
            unregister_code(KC_C);
            wait_ms(5);
            register_code(KC_C);
            c_last_fire_time = timer_read32();
            c_next_interval = RAPID_FIRE_MIN_MS + (rand() % (RAPID_FIRE_MAX_MS - RAPID_FIRE_MIN_MS + 1));
        }
    }

    // AD Strafe Auto Logic
    if (ad_cs_state == AD_CS_STATE_A_AUTO) {
        if (timer_elapsed32(auto_cs_timer_start) >= auto_cs_hold_duration) {
            if (a_physical_pressed) {
                ad_cs_state = AD_CS_STATE_A_HELD;
            } else {
                unregister_code(KC_A);
                ad_cs_state = AD_CS_STATE_IDLE;
            }
        }
    } else if (ad_cs_state == AD_CS_STATE_D_AUTO) {
        if (timer_elapsed32(auto_cs_timer_start) >= auto_cs_hold_duration) {
            if (d_physical_pressed) {
                ad_cs_state = AD_CS_STATE_D_HELD;
            } else {
                unregister_code(KC_D);
                ad_cs_state = AD_CS_STATE_IDLE;
            }
        }
    }

    // WS Strafe Auto Logic
    if (ws_cs_state == WS_CS_STATE_W_AUTO) {
        if (timer_elapsed32(auto_ws_cs_timer_start) >= auto_ws_cs_hold_duration) {
            if (w_physical_pressed) {
                ws_cs_state = WS_CS_STATE_W_HELD;
            } else {
                unregister_code(KC_W);
                ws_cs_state = WS_CS_STATE_IDLE;
            }
        }
    } else if (ws_cs_state == WS_CS_STATE_S_AUTO) {
        if (timer_elapsed32(auto_ws_cs_timer_start) >= auto_ws_cs_hold_duration) {
            if (s_physical_pressed) {
                ws_cs_state = WS_CS_STATE_S_HELD;
            } else {
                unregister_code(KC_S);
                ws_cs_state = WS_CS_STATE_IDLE;
            }
        }
    }
}
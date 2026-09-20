// Copyright 2026 Eric Ottosson (@ericotsn) <contact@ericotsn.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    BASE,
    EXT,
};

enum keycode_aliases {
    CTL_ESC = LCTL_T(KC_ESC),
    SPC_EXT = LT(EXT, KC_SPACE),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_tkl_f13_ansi_tsangan(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MUTE,    KC_PSCR, KC_SCRL, KC_PAUS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,             KC_UP,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                                      KC_RGUI, KC_RALT, KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [EXT] = LAYOUT_tkl_f13_ansi_tsangan(
        _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, _______, _______, _______, _______,    _______, _______, QK_BOOT,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_DEL,  _______, _______, _______,    _______, _______, _______,
        _______, OS_LGUI, OS_LALT, OS_LSFT, OS_LCTL, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, _______,          _______,
        _______,          C(KC_Z), C(KC_X), C(KC_C), C(KC_V), _______, _______, _______, _______, _______, _______,          _______,             _______,
        _______, _______, _______,                            XXXXXXX,                                     _______, _______, _______,    _______, _______, _______
    ),
};
// clang-format on

///////////////////////////////////////////////////////////////////////////////
// Custom Quantum Functions (https://docs.qmk.fm/custom_quantum_functions)
///////////////////////////////////////////////////////////////////////////////

void keyboard_post_init_user(void) {
    rgblight_enable();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(HSV_WHITE);
}

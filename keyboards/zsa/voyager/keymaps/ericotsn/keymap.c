// Copyright 2026 Eric Ottosson (@ericotsn) <contact@ericotsn.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum keycode_aliases {
    HRM_A = LALT_T(KC_A),
    HRM_S = LT(1, KC_S),
    HRM_D = LSFT_T(KC_D),
    HRM_F = LCTL_T(KC_F),
    HRM_V = LGUI_T(KC_V),

    HRM_J   = RCTL_T(KC_J),
    HRM_K   = RSFT_T(KC_K),
    HRM_L   = LT(1, KC_L),
    HRM_SCL = RALT_T(KC_SCLN),
    HRM_M   = RGUI_T(KC_M),
    HRM_DOT = LT(3, KC_DOT),

    LT_BSPC = LT(2, KC_BSPC),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_UNDS, KC_A,    HRM_S,   HRM_D,   HRM_F,   KC_G,                         KC_H,    HRM_J,   HRM_K,   HRM_L,   HRM_SCL, KC_QUOT,
        CW_TOGG, KC_Z,    KC_X,    KC_C,    HRM_V,   KC_B,                         KC_N,    HRM_M,   KC_COMM, HRM_DOT, KC_SLSH, KC_COLN,
                                                     LT_BSPC, KC_ESC,     KC_ENT,  KC_SPC
    ),
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_GRV,  KC_LABK, KC_RABK, KC_MINS, KC_PIPE,                      KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR,  _______, _______,
        _______, KC_EXLM, KC_ASTR, KC_SLSH, KC_EQL,  KC_AMPR,                      KC_HASH, KC_LPRN, KC_RPRN, KC_SCLN, KC_DQUO, _______,
        _______, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,                      KC_AT,   KC_COLN, KC_COMM, KC_DOT,  KC_QUOT, _______,
                                                     _______, _______,    _______, _______
    ),
    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______,                      KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, _______,
                                                     _______, _______,    _______, _______
    ),
    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, KC_VOLD, KC_VOLU, KC_MUTE, _______,                      _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, A(KC_3), A(KC_2), A(KC_1), _______,                      _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, A(KC_6), A(KC_5), A(KC_4), _______,                      _______, _______, _______, _______, _______, _______,
                                                     KC_MPLY, _______,    _______, _______
    ),
};

#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        '*', '*', '*', '*', '*', '*',            '*', '*', '*', '*', '*', '*',
        '*', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', '*',
        '*', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', '*',
        '*', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', '*',
                                 '*', '*',  '*', '*'
    );
#endif // CHORDAL_HOLD
// clang-format on

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_WHITE);
}

#ifdef FLOW_TAP_TERM
bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        // case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}
#endif // FLOW_TAP_TERM

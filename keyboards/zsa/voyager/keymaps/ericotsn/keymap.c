// Copyright 2026 Eric Ottosson (@ericotsn) <contact@ericotsn.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    BASE,
    SYM,
    EXT,
};

enum custom_keycodes {
    OS_CUT = SAFE_RANGE,
    OS_COPY,
    OS_PSTE,
    OS_UNDO,
};

enum keycode_aliases {
    NXT_TAB = C(KC_TAB),
    PRV_TAB = C(S(KC_TAB)),

    HRM_A = LGUI_T(KC_A),
    HRM_S = LALT_T(KC_S),
    HRM_D = LSFT_T(KC_D),
    HRM_F = LCTL_T(KC_F),

    HRM_J   = RCTL_T(KC_J),
    HRM_K   = RSFT_T(KC_K),
    HRM_L   = RALT_T(KC_L),
    HRM_QUO = RGUI_T(KC_QUOT),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        CW_TOGG, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        KC_LCTL, HRM_A,   HRM_S,   HRM_D,   HRM_F,   KC_G,                         KC_H,    HRM_J,   HRM_K,   HRM_L,   HRM_QUO, KC_MINS,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                                                     MO(EXT), KC_SPC,     OS_LSFT, MO(SYM)
    ),
    [SYM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_GRV,  KC_LABK, KC_RABK, KC_MINS, KC_PIPE,                      KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR,  _______, _______,
        _______, KC_EXLM, KC_ASTR, KC_SLSH, KC_EQL,  KC_AMPR,                      KC_HASH, KC_LPRN, KC_RPRN, KC_SCLN, KC_DQUO, _______,
        _______, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,                      KC_AT,   KC_COLN, KC_COMM, KC_DOT,  _______, _______,
                                                     KC_UNDS, _______,    _______, _______
    ),
    [EXT] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_MSTP, KC_VOLU,                      KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_DEL,  KC_F12,
        _______, OS_LGUI, OS_LALT, OS_LSFT, OS_LCTL, KC_VOLD,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, _______,
        _______, OS_UNDO, OS_CUT,  OS_COPY, OS_PSTE, KC_MUTE,                      _______, KC_TAB,  PRV_TAB, NXT_TAB, KC_ENT,  _______,
                                                     _______, _______,    _______, KC_ESC
    ),
};
// clang-format on

///////////////////////////////////////////////////////////////////////////////
// Chordal Hold (https://docs.qmk.fm/tap_hold#chordal-hold)
///////////////////////////////////////////////////////////////////////////////

// clang-format off
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
        '*', '*', '*', '*', '*', '*',            '*', '*', '*', '*', '*', '*',
        '*', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', '*',
        '*', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', '*',
        '*', 'L', 'L', 'L', 'L', 'L',            'R', 'R', 'R', 'R', 'R', '*',
                                 '*', '*',  '*', '*'
    );
// clang-format on

///////////////////////////////////////////////////////////////////////////////
// Custom Quantum Functions (https://docs.qmk.fm/custom_quantum_functions)
///////////////////////////////////////////////////////////////////////////////

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_WHITE);
}

static void tap_primary_mod(uint16_t keycode) {
    tap_code16(detected_host_os() == OS_MACOS ? G(keycode) : C(keycode));
}

static bool process_os_shortcuts(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        case OS_CUT:
            tap_primary_mod(KC_X);
            return false;
        case OS_COPY:
            tap_primary_mod(KC_C);
            return false;
        case OS_PSTE:
            tap_primary_mod(KC_V);
            return false;
        case OS_UNDO:
            tap_primary_mod(KC_Z);
            return false;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_os_shortcuts(keycode, record)) {
        return false;
    }

    return true;
}

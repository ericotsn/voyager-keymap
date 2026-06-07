// Copyright 2026 Eric Ottosson (@ericotsn) <contact@ericotsn.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _GAME,
    _SYM,
    _EXT,
    _NUM,
};

enum custom_keycodes {
    OS_COPY = SAFE_RANGE,
    OS_PSTE,
    OS_CUT,
    OS_UNDO,
    IDEOPEN,
};

enum keycode_aliases {
    NXT_TAB = C(KC_TAB),
    PRV_TAB = C(S(KC_TAB)),

    LA_SYM = MO(_SYM),
    LA_EXT = MO(_EXT),

    // Home row modifiers for _BASE layer
    HM_A = LGUI_T(KC_A),
    HM_R = LALT_T(KC_R),
    HM_S = LSFT_T(KC_S),
    HM_T = LCTL_T(KC_T),

    HM_N = RCTL_T(KC_N),
    HM_E = RSFT_T(KC_E),
    HM_I = RALT_T(KC_I),
    HM_O = RGUI_T(KC_O),

    // Home row modifiers for _SYM layer
    HM_EQL  = LCTL_T(KC_EQL),
    HM_SLSH = LSFT_T(KC_SLSH),
    HM_ASTR = LALT_T(KC_8), // Tap => *
    HM_EXLM = LGUI_T(KC_1), // Tap => !

    HM_LPRN = RCTL_T(KC_9), // Tap => (
    HM_RPRN = RSFT_T(KC_0), // Tap => )
    HM_SCLN = RALT_T(KC_SCLN),
    HM_DQUO = RGUI_T(KC_QUOT), // Tap => "

    // Home row modifiers for _NUM layer
    HM_F4  = LCTL_T(KC_F4),
    HM_F5  = LSFT_T(KC_F5),
    HM_F6  = LALT_T(KC_F6),
    HM_F12 = LGUI_T(KC_F12),

    HM_4 = RCTL_T(KC_4),
    HM_5 = RSFT_T(KC_5),
    HM_6 = RALT_T(KC_6),
    HM_0 = RGUI_T(KC_0),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, TG(_GAME),
        _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_UNDS, _______,
        _______, HM_A,    HM_R,    HM_S,    HM_T,    KC_G,                         KC_M,    HM_N,    HM_E,    HM_I,    HM_O,    _______,
        _______, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_QUOT, _______,
                                                     LA_EXT,  KC_SPC,     OS_LSFT, LA_SYM
    ),
    [_GAME] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         _______, _______, _______, _______, _______, _______,
        KC_T,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                         _______, _______, _______, _______, _______, _______,
        KC_G,    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                         _______, _______, _______, _______, _______, _______,
        KC_B,    KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,                         _______, _______, _______, _______, _______, _______,
                                                     KC_SPC, _______,     _______, _______
    ),
    [_SYM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_GRV,  KC_LABK, KC_RABK, KC_MINS, KC_PIPE,                      KC_CIRC, KC_LCBR, KC_RCBR, KC_DLR,  KC_UNDS, _______,
        _______, HM_EXLM, HM_ASTR, HM_SLSH, HM_EQL,  KC_AMPR,                      KC_HASH, HM_LPRN, HM_RPRN, HM_SCLN, HM_DQUO, _______,
        _______, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,                      KC_AT,   KC_COLN, KC_COMM, KC_DOT,  KC_QUOT, _______,
                                                     _______, _______,    _______, _______
    ),
    [_EXT] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, CW_TOGG, _______, PRV_TAB, NXT_TAB, KC_VOLU,                      KC_PGUP, KC_HOME, KC_UP,   KC_END,  KC_DEL,  _______,
        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_VOLD,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, _______,
        _______, OS_UNDO, OS_CUT,  OS_COPY, OS_PSTE, KC_MPLY,                      KC_INS,  KC_ESC,  KC_TAB,  IDEOPEN, KC_ENT,  _______,
                                                     _______, _______,    _______, _______
    ),
    [_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_F11,  KC_F9,   KC_F8,   KC_F7,   _______,                      KC_ASTR, KC_7,    KC_8,    KC_9,    KC_SLSH, _______,
        _______, HM_F12,  HM_F6,   HM_F5,   HM_F4,   _______,                      KC_PLUS, HM_4,    HM_5,    HM_6,    HM_0,    _______,
        _______, KC_F10,  KC_F3,   KC_F2,   KC_F1,   _______,                      KC_MINS, KC_1,    KC_2,    KC_3,    KC_ENT,  _______,
                                                     _______, _______,    _______, _______
    ),
};
// clang-format on

///////////////////////////////////////////////////////////////////////////////
// Combos
//   https://docs.qmk.fm/features/combo
///////////////////////////////////////////////////////////////////////////////

const uint16_t PROGMEM combo_comm_dot[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_h_comm[]   = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_1_2[]      = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM combo_2_3[]      = {KC_2, KC_3, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_comm_dot, KC_SCLN),
    COMBO(combo_h_comm, KC_BSLS),
    COMBO(combo_1_2, KC_COMM),
    COMBO(combo_2_3, KC_DOT),
};

///////////////////////////////////////////////////////////////////////////////
// (OLKB) Tri Layers
//   https://docs.qmk.fm/ref_functions#update-tri-layer-state-state-x-y-z
///////////////////////////////////////////////////////////////////////////////

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _EXT, _SYM, _NUM);
}

///////////////////////////////////////////////////////////////////////////////
// Chordal Hold
//   https://docs.qmk.fm/tap_hold#chordal-hold
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
// Key Overrides
//   https://docs.qmk.fm/features/key_overrides
///////////////////////////////////////////////////////////////////////////////

const key_override_t comma_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_EXLM);
const key_override_t period_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_QUES);

const key_override_t *key_overrides[] = {&comma_key_override, &period_key_override};

///////////////////////////////////////////////////////////////////////////////
// OS Detection
//   https://docs.qmk.fm/features/os_detection
///////////////////////////////////////////////////////////////////////////////

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            rgb_matrix_sethsv_noeeprom(HSV_WHITE);
            break;
        case OS_WINDOWS:
            rgb_matrix_sethsv_noeeprom(HSV_BLUE);
            break;
        case OS_LINUX:
        case OS_UNSURE:
            rgb_matrix_set_color_all(RGB_RED);
            break;
    }

    return true;
}

///////////////////////////////////////////////////////////////////////////////
// Custom Quantum Functions
//   https://docs.qmk.fm/custom_quantum_functions
///////////////////////////////////////////////////////////////////////////////

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_WHITE);
}

static void tap_os_mod(uint16_t macos_keycode, uint16_t other_keycode) {
    switch (detected_host_os()) {
        case OS_MACOS:
        case OS_IOS:
            tap_code16(macos_keycode);
            return;
        case OS_WINDOWS:
        case OS_LINUX:
        case OS_UNSURE:
        default:
            tap_code16(other_keycode);
            return;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // QMK's Mod-Tap macros (e.g. LCTL_T) only preserve the 8-bit tap
        // keycode. As a result, shifted aliases like KC_LPRN lose their Shift
        // modifier and tap as KC_9 instead. This restores the intended shifted
        // keycodes.
        case HM_ASTR:
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap_code16(KC_ASTR);
                }
                return false;
            }
            return true;
        case HM_EXLM:
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap_code16(KC_EXLM);
                }
                return false;
            }
            return true;
        case HM_LPRN:
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap_code16(KC_LPRN);
                }
                return false;
            }
            return true;
        case HM_RPRN:
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap_code16(KC_RPRN);
                }
                return false;
            }
            return true;
        case HM_DQUO:
            if (record->tap.count) {
                if (record->event.pressed) {
                    tap_code16(KC_DQUO);
                }
                return false;
            }
            return true;

        case OS_COPY:
            if (record->event.pressed) {
                tap_os_mod(G(KC_C), C(KC_C));
            }
            return false;
        case OS_PSTE:
            if (record->event.pressed) {
                tap_os_mod(G(KC_V), C(KC_V));
            }
            return false;
        case OS_CUT:
            if (record->event.pressed) {
                tap_os_mod(G(KC_X), C(KC_X));
            }
            return false;
        case OS_UNDO:
            if (record->event.pressed) {
                tap_os_mod(G(KC_Z), C(KC_Z));
            }
            return false;

        case IDEOPEN:
            if (record->event.pressed) {
                switch (detected_host_os()) {
                    case OS_MACOS:
                    case OS_IOS:
                        tap_code16(G(KC_P)); // "Quick Open" in VS Code
                        return false;
                    case OS_WINDOWS:
                    case OS_LINUX:
                    case OS_UNSURE:
                    default:
                        tap_code(KC_LSFT);
                        tap_code(KC_LSFT); // "Search Everywhere" in JetBrains products
                        return false;
                }
            }

            return true;
    }

    return true;
}

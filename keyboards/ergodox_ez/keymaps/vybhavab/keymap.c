#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE_PD, // default layer
    QWERTY,
    GAMING,
    MOUSE,
    ARROWS,
    LSWITCH
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
    VRSN = EZ_SAFE_RANGE,
#else
    VRSN = SAFE_RANGE,
#endif
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[BASE_PD] = LAYOUT_ergodox_pretty(
  // left hand
  KC_PIPE,         KC_PLUS,     KC_LBRC,       KC_LCBR, KC_LPRN, KC_AMPR, KC_MEDIA_PLAY_PAUSE,  G(C(KC_Q)),         KC_EQUAL,    KC_RPRN,    KC_RCBR,    KC_RBRC, KC_ASTR, KC_EXLM,
  KC_TAB,          KC_SCLN,     KC_COMM,       KC_DOT,  KC_P,    KC_Y,    KC_NO,                G(S(C(KC_F16))),    KC_F,        KC_G,       KC_C,       KC_R,    KC_L,    KC_BSLS,
  LT(ARROWS, KC_ESC),KC_A,      KC_O,          KC_E,    KC_U,    KC_I,                                              KC_D,        KC_H,       KC_T,       KC_N,    KC_S,    LT(MOUSE,KC_MINS),
  KC_LSPO,         KC_QUOT,     KC_Q,          KC_J,    KC_K,    KC_X,    KC_DEL,               KC_KB_MUTE,         KC_B,        KC_M,       KC_W,       KC_V,    KC_Z,    KC_RSPC,
  KC_HYPR,         KC_DLR,      OSL(LSWITCH),  KC_LEFT, KC_RGHT,                                                                 KC_UP,      KC_DOWN,    KC_SLSH, KC_AT,   KC_MEH,
                                                                 KC_MPRV, KC_MNXT,              KC_KB_VOLUME_DOWN,  KC_KB_VOLUME_UP,
                                                                          C(KC_LEFT),           C(KC_RIGHT),
                                                         KC_BSPC,KC_LGUI,KC_LCTL,         KC_LALT,            KC_ENT, KC_SPC
),

[QWERTY] = LAYOUT_ergodox_pretty(
  // left hand
  KC_PIPE,         KC_PLUS,     KC_LBRC,       KC_LCBR, KC_LPRN, KC_AMPR, KC_TRNS,               KC_TRNS,            KC_EQUAL,    KC_RPRN,    KC_RCBR,    KC_RBRC, KC_ASTR, KC_MINS,
  KC_TRNS,         KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    KC_TRNS,               KC_TRNS,            KC_Y,        KC_U,       KC_I,       KC_O,    KC_P,    KC_BSLS,
  KC_TRNS,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,                                               KC_H,        KC_J,       KC_K,       KC_L,    KC_SCLN, LT(MOUSE,KC_QUOT),
  KC_TRNS,         KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    KC_TRNS,               KC_TRNS,            KC_N,        KC_M,       KC_COMM,    KC_DOT,  KC_SLSH, KC_RSPC,
  KC_TRNS,         KC_TRNS,     KC_TRNS,       KC_TRNS, KC_TRNS,                                                                  KC_TRNS,    KC_TRNS,    KC_EXLM, KC_TRNS, KC_TRNS,
                                                                 KC_TRNS, KC_TRNS,              KC_TRNS,            KC_TRNS,
                                                                          KC_TRNS,              KC_TRNS,
                                                         KC_TRNS,KC_TRNS, KC_TRNS,              KC_TRNS,            KC_TRNS, KC_TRNS
),

[GAMING] = LAYOUT_ergodox_pretty(
  // left hand
  KC_GRV,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_TRNS,              KC_TRNS,            KC_6,        KC_7,       KC_8,       KC_9,    KC_0,    KC_TRNS,
  KC_TRNS,         KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    KC_LBRC,              KC_RBRC,            KC_Y,        KC_U,       KC_I,       KC_O,    KC_P,    KC_BSLS,
  KC_TRNS,         KC_A,        KC_S,          KC_D,    KC_F,    KC_G,                                              KC_H,        KC_J,       KC_K,       KC_L,    KC_SCLN, LT(MOUSE,KC_QUOT),
  KC_LSFT,         KC_Z,        KC_X,          KC_C,    KC_V,    KC_B,    KC_EQL,               KC_MINS,            KC_N,        KC_M,       KC_COMM,    KC_DOT,  KC_SLSH, KC_RSPC,
  KC_LCTL,         KC_LALT,     KC_TRNS,       KC_TRNS, KC_TRNS,                                                                 KC_TRNS,    KC_TRNS,    KC_KB_MUTE, G(S(C(KC_F24))), KC_TRNS,
                                                                 KC_TRNS, KC_TRNS,              KC_TRNS,            KC_TRNS,
                                                                          KC_TRNS,              KC_TRNS,
                                                         KC_SPC, KC_TRNS, KC_TRNS,              TO(QWERTY),         KC_TRNS, KC_BSPC
),

[MOUSE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS,         KC_F1,     KC_F2,       KC_F3,   KC_F4,KC_F5,KC_F11,              KC_F12,            KC_F6,     KC_F7,    KC_F8,    KC_F9, KC_F10, KC_TRNS,
  KC_TRNS,         KC_TRNS,     KC_BTN1,       KC_MS_U,   KC_BTN2,KC_TRNS,KC_TRNS,              KC_TRNS,            KC_TRNS,     KC_TRNS,    KC_WH_D,    KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,         KC_TRNS,     KC_MS_L,       KC_MS_D,   KC_MS_R,KC_TRNS,                                          KC_TRNS,     KC_WH_L,    KC_WH_U,    KC_WH_R, KC_TRNS, KC_TRNS,
  KC_TRNS,         KC_TRNS,     KC_TRNS,       KC_BTN3,   KC_TRNS,KC_TRNS,KC_TRNS,              KC_TRNS,            KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,         KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,                                                               KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
                                                                 KC_TRNS, KC_TRNS,              KC_TRNS,            KC_TRNS,
                                                                          KC_TRNS,              KC_TRNS,
                                                         KC_ACL0, KC_ACL1,KC_ACL2,              KC_TRNS,            KC_TRNS, KC_TRNS
),


[ARROWS] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS,         KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,              KC_TRNS,            KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,         KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,              KC_TRNS,            KC_TRNS,     KC_TRNS,    KC_UP,      KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,         KC_TRNS,     KC_LCTL,       KC_LALT,   KC_LGUI,KC_TRNS,                                          KC_TRNS,     KC_LEFT,    KC_DOWN,    KC_RIGHT,KC_TRNS, KC_TRNS,
  KC_TRNS,         KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,              KC_TRNS,            KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,         KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,                                                               KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
                                                                  RGB_MOD,KC_TRNS,              RGB_TOG, KC_TRNS,
                                                                          KC_TRNS,              KC_TRNS,
                                                          RGB_VAD,RGB_VAI,KC_TRNS,              KC_TRNS, RGB_HUD, RGB_HUI
),

[LSWITCH] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS,         TO(BASE_PD), TO(QWERTY),    TO(GAMING),KC_TRNS,KC_TRNS,KC_TRNS,              KC_TRNS,            KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,         KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,              KC_TRNS,            KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,         KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,KC_TRNS,                                          KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,         KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,              KC_TRNS,            KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,         KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,                                                               KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
                                                                 KC_TRNS, KC_TRNS,              KC_TRNS,            KC_TRNS,
                                                                          KC_TRNS,              KC_TRNS,
                                                         KC_TRNS, KC_TRNS,KC_TRNS,              KC_TRNS,            KC_TRNS, KC_TRNS
),

/*
 * Full trans layer
  KC_TRNS,         KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,              KC_TRNS,            KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,         KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,              KC_TRNS,            KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,         KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,KC_TRNS,                                          KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,         KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,KC_TRNS,KC_TRNS,              KC_TRNS,            KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS,         KC_TRNS,     KC_TRNS,       KC_TRNS,   KC_TRNS,                                                               KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS,
                                                                 KC_TRNS, KC_TRNS,              KC_TRNS,            KC_TRNS,
                                                                          KC_TRNS,              KC_TRNS,
                                                         KC_TRNS, KC_TRNS,KC_TRNS,              KC_TRNS,            KC_TRNS, KC_TRNS
*/

};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// clang-format off
const key_override_t kc_pipe_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_PIPE, KC_GRV, 1 << BASE_PD);
const key_override_t kc_plus_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_PLUS, KC_1, 1 << BASE_PD);
const key_override_t kc_lbrc_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_LBRC, KC_2, 1 << BASE_PD);
const key_override_t kc_lcbr_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_LCBR, KC_3, 1 << BASE_PD);
const key_override_t kc_lprn_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_LPRN, KC_4, 1 << BASE_PD);
const key_override_t kc_ampr_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_AMPR, KC_5, 1 << BASE_PD);
const key_override_t kc_equal_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_EQUAL, KC_6, 1 << BASE_PD);
const key_override_t kc_rprn_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_RPRN, KC_7, 1 << BASE_PD);
const key_override_t kc_rcbr_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_RCBR, KC_8, 1 << BASE_PD);
const key_override_t kc_rbrc_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_RBRC, KC_9, 1 << BASE_PD);
const key_override_t kc_astr_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_ASTR, KC_0, 1 << BASE_PD);
const key_override_t kc_exlm_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_EXLM, KC_PERC, 1 << BASE_PD);
const key_override_t kc_bsls_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_BSLS, KC_HASH, 1 << BASE_PD);
const key_override_t kc_at_override    = ko_make_with_layers(MOD_MASK_SHIFT, KC_AT, KC_CIRC, 1 << BASE_PD);
const key_override_t kc_slsh_override  = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLSH, KC_QUES, 1 << BASE_PD);
const key_override_t kc_dlr_override   = ko_make_with_layers(MOD_MASK_SHIFT, KC_DLR, KC_TILD, 1 << BASE_PD);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
  &kc_pipe_override,
  &kc_plus_override,
  &kc_lbrc_override,
  &kc_lcbr_override,
  &kc_lprn_override,
  &kc_ampr_override,
  &kc_equal_override,
  &kc_rprn_override,
  &kc_rcbr_override,
  &kc_rbrc_override,
  &kc_astr_override,
  &kc_exlm_override,
  &kc_bsls_override,
  &kc_at_override,
  &kc_slsh_override,
  &kc_dlr_override,
  NULL
};

// clang-format on

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};

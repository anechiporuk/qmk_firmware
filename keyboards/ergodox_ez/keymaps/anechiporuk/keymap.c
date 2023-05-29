#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_dvorak.h"

// #define _______ KC_TRNS
// #define XXXXXXX KC_NO
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_LGUI OSM(MOD_LGUI)
#define OSM_RCTL OSM(MOD_RCTL)
#define OSM_RALT OSM(MOD_RALT)
#define OSM_RSFT OSM(MOD_RSFT)
#define OSM_RGUI OSM(MOD_RGUI)
#define OSL_SYMB OSL(Symbols)
#define OSL_NUMP OSL(NumPad)
#define OSL_SYST OSL(System)
#define OSL_MEDI OSL(Media)



#undef TAPPING_TERM
#define TAPPING_TERM 175

enum custom_keycodes {
    KC_P000 = SAFE_RANGE,
};

// enum dvorak_keycodes {
//     DV_BSLS = KC_BSLS,
//     DV_COLN = S(KC_Z),
//     DV_COMM = KC_W,
//     DV_DOT  = KC_E,
//     DV_DQUO = S(KC_Q),
//     DV_EQL  = KC_RBRC,
//     DV_LABK = S(KC_W),
//     DV_LBRC = KC_MINS,
//     DV_LCBR = KC_UNDS,
//     DV_MINS = KC_QUOT,
//     DV_PIPE = KC_PIPE,
//     DV_PLUS = KC_RCBR,
//     DV_QUES = KC_LCBR,
//     DV_QUOT = KC_Q,
//     DV_RABK = S(KC_E),
//     DV_RBRC = KC_EQL,
//     DV_RCBR = KC_PLUS,
//     DV_SCLN = KC_Z,
//     DV_SLSH = KC_LBRC,
//     DV_UNDS = KC_DQUO,
//     DV_A = KC_A,
//     DV_B = KC_N,
//     DV_C = KC_I,
//     DV_D = KC_H,
//     DV_E = KC_D,
//     DV_F = KC_Y,
//     DV_G = KC_U,
//     DV_H = KC_J,
//     DV_I = KC_G,
//     DV_J = KC_C,
//     DV_K = KC_V,
//     DV_L = KC_P,
//     DV_M = KC_M,
//     DV_N = KC_L,
//     DV_O = KC_S,
//     DV_P = KC_R,
//     DV_Q = KC_X,
//     DV_R = KC_O,
//     DV_S = KC_SCLN,
//     DV_T = KC_K,
//     DV_U = KC_F,
//     DV_V = KC_DOT,
//     DV_W = KC_COMM,
//     DV_X = KC_B,
//     DV_Y = KC_T,
//     DV_Z = KC_SLSH,
// };

enum layers {
    BASE,
    Symbols,
    Media,
    NumPad,
    System,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY Layer for DVORAK layout
 *
 *  ,--------------------------------------------------.                 ,--------------------------------------------------.
 *  |   GEsc |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                 |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   =    |
 *  |--------+------+------+------+------+-------------|                 |------+------+------+------+------+------+--------|
 *  |   Tab  |  '"  |  ,<  |  .>  |   P  |   Y  |  (   |                 |  )   |   F  |   G  |   C  |   R  |   L  |   /    |
 *  |--------+------+------+------+------+------|      |                 |      |------+------+------+------+------+--------|
 *  |    \   |   A  |   O  |   E  |   U  |   I  |------|                 |------|   D  |   H  |   T  |   N  |   S  |   -    |
 *  |--------+------+------+------+------+------|      |                 |      |------+------+------+------+------+--------|
 *  | LShft  |   ;  |   Q  |   J  |   K  |   X  |      |                 |      |   B  |   M  |   W  |   V  |   Z  | RShft  |
 *  `--------+------+------+------+------+-------------'                 `-------------+------+------+------+------+--------'
 *    | LCtrl|      |      | LGui | Media|                                             |   {  |   }  |   [  |   ]  | LCtrl|
 *    `----------------------------------'                                             `----------------------------------'
 *                                        ,-------------.               ,-------------.
 *                                        | Ins  |      |               |      |      |
 *                                 ,------|------|------|               |------+------+------.
 *                                 |      |      |      |               |      |      |      |
 *                                 | Spc  | Del  |------|               |------|BckSpc|Enter |
 *                                 |      |      | LAlt |               | Sym  |      |      |
 *                                 `--------------------'               `--------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
    QK_GESC,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,           KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   DV_EQL,
    KC_TAB,   DV_QUOT,  DV_COMM,  DV_DOT,   DV_P,     DV_Y,     DV_LPRN,         DV_RPRN,  DV_F,     DV_G,     DV_C,     DV_R,     DV_L,     DV_SLSH,
    DV_BSLS,  DV_A,     DV_O,     DV_E,     DV_U,     DV_I,                                DV_D,     DV_H,     DV_T,     DV_N,     DV_S,     DV_MINS,
    OSM_LSFT, DV_SCLN,  DV_Q,     DV_J,     DV_K,     DV_X,     XXXXXXX,         XXXXXXX,  DV_B,     DV_M,     DV_W,     DV_V,     DV_Z,     OSM_RSFT,
    OSM_LCTL, XXXXXXX,  XXXXXXX,  OSM_LGUI, OSL_MEDI,                                                DV_LCBR,  DV_RCBR,  DV_LBRC,  DV_RBRC,  OSM_RCTL,
                                                      KC_INS,   XXXXXXX,         XXXXXXX,  XXXXXXX,
                                                                XXXXXXX,         XXXXXXX,
                                            KC_SPC,   KC_DEL,   OSM_LALT,        OSL_SYMB,KC_BSPC,KC_ENT
),
/* Symbols Layer
 *
 *  ,--------------------------------------------------.           ,--------------------------------------------------.
 *  |        |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |           |  F19 |  F20 |  F21 |  F22 |  F23 |  F24 |        |
 *  |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 *  |   `    |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   (  |   )  |        |
 *  |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 *  |        |   1  |   2  |   3  |   4  |   5  |------|           |------|   6  |   7  |   8  |   9  |   0  |        |
 *  |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 *  |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 *  `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *    |      |      |      |      |      |                                       |      |      |      |      |      |
 *    `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.         ,-------------.
 *                                        |      |      |         |      |      |
 *                                 ,------|------|------|         |------+------+------.
 *                                 |      |      |      |         |      |      |      |
 *                                 |      |      |------|         |------|      |      |
 *                                 |      |      |      |         |      |      |      |
 *                                 `--------------------'         `--------------------'
 */
[Symbols] = LAYOUT_ergodox_pretty(
    XXXXXXX,  KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,        KC_F19,   KC_F20,   KC_F21,   KC_F22,   KC_F23,   KC_F24,   XXXXXXX,
    KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  XXXXXXX,       XXXXXXX,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  XXXXXXX,
    _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                              KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
    _______,  _______,  _______,  _______,  _______,                                               XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                                      _______,  _______,       _______,  _______,
                                                                _______,       _______,
                                            _______,  _______,  _______,       _______,  _______,  _______
),
/* Media
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |           |  F19 |  F20 |  F21 |  F22 |  F23 |  F24 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | Mute | Vol- | Vol+ | Pst  | Copy |      |           |      | PgUp | Home |  Up  | End  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Play | Stop | Prev | Next | Ins  |------|           |------| PgDn | Left | Down | Rght |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      | Del  |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[Media] = LAYOUT_ergodox_pretty(
    XXXXXXX,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPLY,  KC_MPRV,  KC_MNXT,       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PASTE, KC_COPY,  XXXXXXX,       XXXXXXX,  KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   XXXXXXX,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_UNDO,  KC_INS,                            KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_DEL,   XXXXXXX,       XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    _______,  _______,  _______,  _______,  _______,                                               XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                                      _______,  XXXXXXX,       XXXXXXX,  XXXXXXX,
                                                                XXXXXXX,       XXXXXXX,
                                            _______,  _______,  _______,       _______,  _______,  _______
),
/* NumPad & Arrows
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      | PrScr| ScLck| Break|      |      |           |      |  (   | NmLck|  /   |  *   |  -   |   (    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | Home |  Up  |  End | PgUp |      |           |      |  )   |  7   |  8   |  9   |  +   |   )    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      | Left | Down | Right| PgDn |------|           |------|      |  4   |  5   |  6   |  =   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |  1   |  2   |  3   |Enter |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   | 000  |  .   |  ,   |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NumPad] = LAYOUT_ergodox(
    XXXXXXX,    XXXXXXX,    KC_PSCR,    KC_SCRL,    KC_PAUS,    XXXXXXX,    XXXXXXX,       XXXXXXX,    KC_LPRN,    KC_NUM,     KC_PSLS,    KC_PAST,    KC_PMNS,    KC_LPRN,
    XXXXXXX,    XXXXXXX,    KC_HOME,    KC_UP,      KC_END,     KC_PGUP,    XXXXXXX,       XXXXXXX,    KC_RPRN,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_PPLS,    KC_RPRN,
    _______,    XXXXXXX,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGDN,                               XXXXXXX,    KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_PEQL,    XXXXXXX,
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,    XXXXXXX,    KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_PENT,    _______,
    _______,    _______,    _______,    _______,    _______,                                                       KC_KP_0,    KC_P000,    KC_PDOT,    KC_PCMM,    _______,
                                                                _______,    XXXXXXX,       XXXXXXX,    XXXXXXX,
                                                                            XXXXXXX,       XXXXXXX,
                                                    _______,    _______,    _______,       _______,    _______,    _______
),
/* System
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |Reboot|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|Debug |      |      |      |AtShft|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |BtLdr |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NumPad] = LAYOUT_ergodox(
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    QK_RBT,     XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                               DB_TOGG,    XXXXXXX,    XXXXXXX,    XXXXXXX,    AS_TOGG,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,    QK_BOOT,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                                                       XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                                XXXXXXX,    XXXXXXX,       XXXXXXX,    XXXXXXX,
                                                                            XXXXXXX,       XXXXXXX,
                                                    XXXXXXX,    XXXXXXX,    XXXXXXX,       XXXXXXX,    XXXXXXX,    XXXXXXX
),
};
// clang-format on

bool check_mods(uint8_t mods) {
    uint8_t current_mods = get_mods();
    if (!has_oneshot_mods_timed_out()) {
        current_mods |= get_oneshot_mods();
    }
    return (current_mods & mods) == mods;
};

bool is_any_mods_or_layers(void) {
    return (bool)(
        get_weak_mods() |
        get_oneshot_mods() |
        get_oneshot_locked_mods() |
        get_mods() |
        layer_state_is(Symbols) |
        layer_state_is(Media) |
        layer_state_is(NumPad)
    );
}

void clear_all_mods(void) {
    clear_weak_mods();
    clear_oneshot_mods();
    clear_oneshot_locked_mods();
    clear_mods();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_P000:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_KP_0) SS_TAP(X_KP_0) SS_TAP(X_KP_0));
            }
            return false;
        case KC_ESC:
            if (is_any_mods_or_layers()) {
                clear_all_mods();
                layer_off(Symbols);
                layer_off(Media);
                layer_off(NumPad);
                reset_oneshot_layer();
                return false;
            }
            break;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t mods = get_mods();
    if (!has_oneshot_mods_timed_out()) {
        mods |= get_oneshot_mods();
    }

    if (mods & MOD_BIT(KC_LSFT)) {
        ergodox_right_led_1_set(LED_BRIGHTNESS_HI);
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_set(LED_BRIGHTNESS_LO);
        ergodox_right_led_1_off();
    }

    if (mods & MOD_BIT(KC_LALT)) {
        ergodox_right_led_2_set(LED_BRIGHTNESS_HI);
        ergodox_right_led_2_on();
    } else {
        ergodox_right_led_2_set(LED_BRIGHTNESS_LO);
        ergodox_right_led_2_off();
    }

    if (mods & MOD_BIT(KC_LCTL)) {
        ergodox_right_led_3_set(LED_BRIGHTNESS_HI);
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_set(LED_BRIGHTNESS_LO);
        ergodox_right_led_3_off();
    }
};

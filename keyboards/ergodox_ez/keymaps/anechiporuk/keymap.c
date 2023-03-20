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

#define HOME_A LALT_T(DV_A)
#define HOME_O LGUI_T(DV_O)
#define HOME_E LSFT_T(DV_E)
#define HOME_U LCTL_T(DV_U)
#define HOME_H RCTL_T(DV_H)
#define HOME_T RSFT_T(DV_T)
#define HOME_N RGUI_T(DV_N)
#define HOME_S LALT_T(DV_S)

#undef TAPPING_TERM
#define TAPPING_TERM 175

enum layers {
    BASE,
    NUM,
    ARR,
    System,
};

tap_dance_action_t tap_dance_actions[] = {};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* QWERTY Layer for DVORAK layout
 *
 *  ,--------------------------------------------------.                 ,--------------------------------------------------.
 *  |   F1   |  F2  |  F3  |  F4  |  F5  |  F6  |  {   |                 |   }  |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
 *  |--------+------+------+------+------+-------------|                 |------+------+------+------+------+------+--------|
 *  |   Tab  |  '"  |  ,<  |  .>  |   P  |   Y  |  [   |                 |   ]  |   F  |   G  |   C  |   R  |   L  |   /    |
 *  |--------+------+------+------+------+------|      |                 |      |------+------+------+------+------+--------|
 *  |   Esc  | LA_A | LG_O | LC_E | LS_U |   I  |------|                 |------|   D  | RS_H | RC_T | RG_N | LA_S |   -    |
 *  |--------+------+------+------+------+------|  (   |                 |   )  |------+------+------+------+------+--------|
 *  |    =   |   ;  |   Q  |   J  |   K  |   X  |      |                 |      |   B  |   M  |   W  |   V  |   Z  |   \    |
 *  `--------+------+------+------+------+-------------'                 `-------------+------+------+------+------+--------'
 *    | LCtl |      |      |      |      |                                             |      |      |      |      | RCtl |
 *    `----------------------------------'                                             `----------------------------------'
 *                                        ,-------------.               ,-------------.
 *                                        |      |      |               |      |      |
 *                                 ,------|------|------|               |------+------+------.
 *                                 |      |      |      |               |      |      |      |
 *                                 | Spc  |      |------|               |------|BckSpc|Enter |
 *                                 |      |      |      |               |      |      |      |
 *                                 `--------------------'               `--------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    DV_LCBR,        DV_RCBR,  KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,
    KC_TAB,   DV_QUOT,  DV_COMM,  DV_DOT,   DV_P,     DV_Y,     DV_LBRC,        DV_RBRC,  DV_F,     DV_G,     DV_C,     DV_R,     DV_L,     DV_SLSH,
    KC_ESC,   HOME_A,   HOME_O,   HOME_E,   HOME_U,   DV_I,                               DV_D,     HOME_H,   HOME_T,   HOME_N,   HOME_S,   DV_MINS,
    DV_EQL,   DV_SCLN,  DV_Q,     DV_J,     DV_K,     DV_X,     KC_LPRN,        KC_RPRN,  DV_B,     DV_M,     DV_W,     DV_V,     DV_Z,     DV_BSLS,
    KC_LCTL,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_RCTL,
                                                      XXXXXXX,  XXXXXXX,        XXXXXXX,  XXXXXXX,
                                                                XXXXXXX,        XXXXXXX,
                                LT(NUM,KC_SPC),LT(ARR,XXXXXXX), XXXXXXX,        XXXXXXX,  LT(ARR,KC_BSPC),LT(NUM,KC_ENT)
),
/* Symbols Layer
 *
 *  ,--------------------------------------------------.           ,--------------------------------------------------.
 *  |  F13   |  F14 |  F15 |  F16 |  F17 |  F18 |      |           |      |  F19 |  F20 |  F21 |  F22 |  F23 |   F24  |
 *  |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 *  |        |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   (  |   )  |   ?    |
 *  |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 *  |        |   1  |   2  |   3  |   4  |   5  |------|           |------|   6  |   7  |   8  |   9  |   0  |   _    |
 *  |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 *  |    +   |   :  |   `  |   ~  |   {  |   [  |      |           |      |   ]  |   }  |      |      |      |   |    |
 *  `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *    |      |      |      |      |      |                                       |      |      |      |      |      |
 *    `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.         ,-------------.
 *                                        |      |      |         |      |      |
 *                                 ,------|------|------|         |------+------+------.
 *                                 |      |      |      |         |      |      |      |
 *                                 |      |      |------|         |------|  Del |      |
 *                                 |      |      |      |         |      |      |      |
 *                                 `--------------------'         `--------------------'
 */
[NUM] = LAYOUT_ergodox_pretty(
    KC_F13,   KC_F14,   KC_F15,   KC_F16,   KC_F17,   KC_F18,   _______,       _______,  KC_F19,   KC_F20,   KC_F21,   KC_F22,   KC_F23,   KC_F24,
    _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,  _______,       _______,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  DV_QUES,
    _______,LALT_T(KC_1),LGUI_T(KC_2),LSFT_T(KC_3),LCTL_T(KC_4), KC_5,            KC_6,RCTL_T(KC_7),RSFT_T(KC_8),RGUI_T(KC_9),LALT_T(KC_0),DV_UNDS,
    DV_PLUS,  DV_COLN,  DV_GRV,   DV_TILD,  DV_LCBR,  DV_LBRC,  _______,       _______,  DV_RBRC,  DV_RCBR,  XXXXXXX,  XXXXXXX,  XXXXXXX,  DV_PIPE,
    _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                                               XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  _______,
                                                      XXXXXXX,  XXXXXXX,       XXXXXXX,  XXXXXXX,
                                                                XXXXXXX,       XXXXXXX,
                                            _______,  _______,  XXXXXXX,       XXXXXXX,  KC_DEL,   _______
),
/* Media
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Mute  | Vol- | Vol+ |      |      |      |      |           |      |      |  Ins | PrScr| Del  |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | Play | Stop | Prev | Next |      |      |           |      | PgUp | Home |  Up  | End  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | LAlt | LWin | LSft | LCtl |      |------|           |------| PgDn | Left | Down | Rght |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | App  |      |      |      |      |        |
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
[ARR] = LAYOUT_ergodox_pretty(
    KC_MUTE,  KC_VOLD,  KC_VOLU,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,       XXXXXXX,  XXXXXXX,  KC_INS,   KC_PSCR,  KC_DEL,   XXXXXXX,  XXXXXXX,
    _______,  KC_MPLY,  KC_MSTP,  KC_MPRV,  KC_MNXT,  XXXXXXX,  XXXXXXX,       XXXXXXX,  KC_PGUP,  KC_HOME,  KC_UP,    KC_END,   XXXXXXX,  XXXXXXX,
    _______,  KC_LALT,  KC_LWIN,  KC_LSFT,  KC_LCTL,  XXXXXXX,                           KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_RGHT,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,       XXXXXXX,  KC_APP,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                                               XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
                                                      XXXXXXX,  XXXXXXX,       XXXXXXX,  XXXXXXX,
                                                                XXXXXXX,       XXXXXXX,
                                            _______,  _______,  XXXXXXX,       XXXXXXX,  _______,  _______
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
[System] = LAYOUT_ergodox(
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
    return (bool)(get_weak_mods() | get_oneshot_mods() | get_oneshot_locked_mods() | get_mods() | layer_state_is(NUM) | layer_state_is(ARR));
}

void clear_all_mods(void) {
    clear_weak_mods();
    clear_oneshot_mods();
    clear_oneshot_locked_mods();
    clear_mods();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ESC:
            if (is_any_mods_or_layers()) {
                clear_all_mods();
                layer_off(NUM);
                layer_off(ARR);
                reset_oneshot_layer();
                return false;
            }
            break;
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {}

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

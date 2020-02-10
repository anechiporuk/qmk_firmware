#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

enum {
  KC_P000 = SAFE_RANGE,
};

enum {
    TD_SCLN = 0,
    TD_LBRC,
    TD_RBRC,
    TD_GRV,
    TD_QUOT,
    TD_BSLS,
};
enum {
    DV_BSLS = KC_BSLS, 
    DV_COLN = S(KC_Z),    
    DV_COMM = KC_W,    
    DV_DOT  = KC_E,     
    DV_DQUO = S(KC_Q),
    DV_EQL  = KC_RBRC,    
    DV_LABK = S(KC_W),    
    DV_LBRC = KC_MINS,    
    DV_LCBR = KC_UNDS,    
    DV_MINS = KC_QUOT,
    DV_PIPE = KC_PIPE,
    DV_PLUS = KC_RCBR,
    DV_QUES = KC_LCBR, 
    DV_QUOT = KC_Q,  
    DV_RABK = S(KC_E),    
    DV_RBRC = KC_EQL,    
    DV_RCBR = KC_PLUS,    
    DV_SCLN = KC_Z,
    DV_SLSH = KC_LBRC,
    DV_UNDS = KC_DQUO,
};

enum {
    //DVORAK = 0,
    QWERTY=0,
    Symbols,
    NumPad,
    Numbers,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* DVORAK layer                                                          
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  BkSpc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |  '"  |  ,<  |  .>  |   P  |   Y  |  \|  |           |  /?  |   F  |   G  |   C  |   R  |   L  |   =+   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Symbols|   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |   _-   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |  ;:  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | Numbers|
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtrl|  Fn  |      | LGui | LAlt |                                       | Left | Down |  Up  | Right| LCtrl|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       | Ins  | Del  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | PgUp |      |      |   
 *                                 | Space|      |------|       |------|      |Enter |   
 *                                 |      |      |      |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
/*[DVORAK] = LAYOUT_ergodox(     
    // left hand               
    KC_ESC,         KC_F1,          KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,
    KC_TAB,         KC_QUOT,        KC_COMM,    KC_DOT,     KC_P,       KC_Y,       TD(TD_BSLS),
    XXXXXXX,        KC_A,           KC_O,       KC_E,       KC_U,       KC_I,
    OSM(MOD_LSFT),  TD(TD_SCLN),    KC_Q,       KC_J,       KC_K,       KC_X,       XXXXXXX,
    OSM(MOD_LCTL),  OSL(Fn),        OSL(NumPad),KC_LGUI,    OSM(MOD_LALT),
                                                                        XXXXXXX,    XXXXXXX,
                                                                                    XXXXXXX,
                                                            KC_SPC,     XXXXXXX,    XXXXXXX,
    // right hand
    KC_F7,          KC_F8,          KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_BSPC,
    KC_SLSH,        KC_F,           KC_G,       KC_C,       KC_R,       KC_L,       KC_EQL,
                    KC_D,           KC_H,       KC_T,       KC_N,       KC_S,       KC_MINS,
    XXXXXXX,        KC_B,           KC_M,       KC_W,       KC_V,       KC_Z,       OSM(MOD_LSFT),
                                    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    OSM(MOD_LCTL),
    KC_INS,         KC_DEL,
    KC_PGUP,
    KC_PGDN,        XXXXXXX,        KC_ENT
),*/ 
/* QWERTY Layer for DVORAK layout
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |  BkSpc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   Tab  |   Q  |   W  |   E  |   R  |   T  |  \|  |           |  /?  |   Y  |   U  |   I  |   O  |   P  |  =+    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   `~   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;:  |  -_    |
 * |--------+------+------+------+------+------|  (   |           |  )   |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |  ,<  |  .>  |  /?  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtrl|      |      | LGui | LAlt |                                       | Left | Down |  Up  | Right| RCtrl|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Ins  |  [   |       |  ]   | Del  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  {   |       |  }   |      |      |   
 *                                 | Space| Sym  |------|       |------| Sym  |Enter |   
 *                                 |      |      | Num  |       | Num  |      |      |
 *                                 `--------------------'       `--------------------'
 */
[QWERTY] = LAYOUT_ergodox(
    // left hand
    KC_ESC,         KC_F1,          KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,
    KC_TAB,         KC_Q,           KC_W,       KC_E,       KC_R,       KC_T,       KC_BSLS,
    KC_GRV,         KC_A,           KC_S,       KC_D,       KC_F,       KC_G,
    OSM(MOD_LSFT),  KC_Z,           KC_X,       KC_C,       KC_V,       KC_B,       KC_LPRN,
    OSM(MOD_LCTL),  XXXXXXX,        XXXXXXX,    OSM(MOD_LGUI),OSM(MOD_LALT),
                                                                        KC_INS,     DV_LBRC,
                                                                                    DV_LCBR,
                                                            KC_SPC,     OSL(Symbols),OSL(Numbers),
    // right hand
    KC_F7,          KC_F8,          KC_F9,      KC_F10,     KC_F11,     KC_F12,     KC_BSPC,
    DV_SLSH,        KC_Y,           KC_U,       KC_I,       KC_O,       KC_P,       DV_EQL,
                    KC_H,           KC_J,       KC_K,       KC_L,       KC_SCLN,    DV_MINS,
    KC_RPRN,        KC_N,           KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    OSM(MOD_RSFT),
                                    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    OSM(MOD_RCTL),
    DV_RBRC,        KC_DEL,
    DV_RCBR,
    OSL(Numbers),   OSL(Symbols),   KC_ENT
),
/* Symbols Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F13 |  F14 |  F15 |  F16 |  F17 |  F18 |           |  F19 |  F20 |  F21 |  F22 |  F23 |  F24 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   "  |   <  |   >  |      |      |  |   |           |  ?   |      |      |      |      |      |   +    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   ~    |  !   |   @  |   #  |   $  |   %  |------|           |------|   ^  |   &  |   *  |   (  |   )  |   _    |
 * |--------+------+------+------+------+------|  (   |           |  )   |------+------+------+------+------+--------|
 * |        |   :  |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Home | PgDn | PgUp | End  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |  [   |       |  ]   |      |  
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |  {   |       |  }   |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[Symbols] = LAYOUT_ergodox(
    // left hand
    _______,    KC_F13,     KC_F14,     KC_F15,     KC_F16,     KC_F17,     KC_F18,
    _______,    DV_DQUO,    DV_LABK,    DV_RABK,    XXXXXXX,    XXXXXXX,    DV_PIPE,
    KC_TILD,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,
    _______,    DV_COLN,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    KC_LPRN,
    _______,    _______,    _______,    _______,    _______,
                                                                _______,    DV_LBRC,
                                                                            DV_LCBR,
                                                    _______,    _______,    _______,
    // right hand
    KC_F19,     KC_F20,     KC_F21,     KC_F22,     KC_F23,     KC_F24,     _______,
    DV_QUES,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    DV_PLUS,
                KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    DV_UNDS,
    KC_RPRN,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
                            KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     _______,
    DV_RBRC,    _______,
    DV_RCBR,
    _______,    _______,    _______
),
/* NumPad & Arrows
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      | PrScr| ScLck| Break|      |      |           |      |      | NmLck|  /   |  *   |  -   |  Vol+  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        | Ins  | Home |  Up  |  End | PgUp |      |           |      |      |  7   |  8   |  9   |  +   |  Vol-  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Del  | Left | Down | Right| PgDn |------|           |------|      |  4   |  5   |  6   |  =   |  Mute  |
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
    // left hand      
    _______,    XXXXXXX,    KC_PSCR,    KC_SLCK,    KC_PAUS,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    KC_INS,     KC_HOME,    KC_UP,      KC_END,     KC_PGUP,    XXXXXXX,
    _______,    KC_DEL,     KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_PGDN,
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    _______,    _______,    _______,    _______,    _______,
                                                                _______,    _______,
                                                                            _______,
                                                    _______,    _______,    _______,
    // right hand 
    XXXXXXX,    XXXXXXX,    KC_NLCK,    KC_PSLS,    KC_PAST,    KC_PMNS,    KC_VOLU,
    XXXXXXX,    XXXXXXX,    KC_KP_7,    KC_KP_8,    KC_KP_9,    KC_PPLS,    KC_VOLD,
                XXXXXXX,    KC_KP_4,    KC_KP_5,    KC_KP_6,    KC_PEQL,    KC_MUTE,
    XXXXXXX,    XXXXXXX,    KC_KP_1,    KC_KP_2,    KC_KP_3,    KC_PENT,    _______,
                            KC_KP_0,    KC_P000,    KC_PDOT,    KC_PCMM,    _______,
    _______,    _______,
    _______,
    _______,    _______,    _______
),
/* Numbers
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  1   |  2   |  3   |  4   |  5   |------|           |------|  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Home | PgDn | PgUp | End  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[Numbers] = LAYOUT_ergodox(      
    // left hand      
    _______,    _______,    _______,    _______,    _______,    _______,    _______,
    _______,    _______,    _______,    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5, 
    _______,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    _______,    _______,    _______,    _______,    _______,
                                                                _______,    XXXXXXX,
                                                                            XXXXXXX,
                                                    _______,    _______,    _______,
    // right hand 
    _______,    _______,    _______,    _______,    _______,    _______,    _______,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
                KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    _______,
                            KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     _______,
    XXXXXXX,    _______,
    XXXXXXX,
    _______,    _______,    _______
),
};

bool check_mods(uint8_t mods)
{
    uint8_t current_mods = get_mods();
    if(!has_oneshot_mods_timed_out())
    {
        current_mods |= get_oneshot_mods();
    }
    return (current_mods & mods) == mods;
};

bool is_any_mods_or_layers(void)
{
    return (bool)(
        get_weak_mods() |
        get_macro_mods() |
        get_oneshot_mods() |
        get_oneshot_locked_mods() |
        get_mods() |
        layer_state_is(Symbols) |
        layer_state_is(Numbers)
    );
}

void clear_all_mods(void)
{
    clear_weak_mods();
    clear_macro_mods();
    clear_oneshot_mods();
    clear_oneshot_locked_mods();
    clear_mods();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
    case KC_P000:
        if (record->event.pressed) {
            SEND_STRING(SS_TAP(X_KP_0) SS_TAP(X_KP_0) SS_TAP(X_KP_0));
        }
        return false;
    case KC_ESC:
        if(is_any_mods_or_layers())
        {
            clear_all_mods();
            layer_off(Symbols);
            layer_off(Numbers);
            reset_oneshot_layer();
            return false;
        }
        break;
    /*case KC_EXLM:
    case KC_AT:
    case KC_HASH:
        if (record->event.pressed) {
            if(check_mods(MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT))) {
                switch(keycode) {
                case KC_EXLM:
                    SEND_STRING("3");
                    layer_off(Fn);
                    layer_off(NumPad);
                    layer_off(QWERTY);
                    break;
                case KC_AT:
                    SEND_STRING("2");
                    layer_off(Fn);
                    layer_off(NumPad);
                    layer_on(QWERTY);
                    break;
                case KC_HASH:
                    SEND_STRING("3");
                    layer_off(Fn);
                    layer_off(NumPad);
                    layer_on(QWERTY);
                    break;
                }
                return false;
            }
        }
        break;*/
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t mods = get_mods();
    if(!has_oneshot_mods_timed_out())
    {
        mods |= get_oneshot_mods();
    }

    if(mods & MOD_BIT(KC_LSFT)) {
        ergodox_right_led_1_set(LED_BRIGHTNESS_HI);
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_set(LED_BRIGHTNESS_LO);
        ergodox_right_led_1_off();
    }

    if(mods & MOD_BIT(KC_LALT)) {
        ergodox_right_led_2_set(LED_BRIGHTNESS_HI);
        ergodox_right_led_2_on();
    } else {
        ergodox_right_led_2_set(LED_BRIGHTNESS_LO);
        ergodox_right_led_2_off();
    }

    if(mods & MOD_BIT(KC_LCTRL)) {
        ergodox_right_led_3_set(LED_BRIGHTNESS_HI);
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_set(LED_BRIGHTNESS_LO);
        ergodox_right_led_3_off();
    }

};


qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
    [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
    [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
    [TD_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_GRV, KC_TILD),
    [TD_QUOT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DQUO),
    [TD_BSLS] = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_PIPE),
};

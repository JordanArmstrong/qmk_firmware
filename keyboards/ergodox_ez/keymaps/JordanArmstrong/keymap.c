#include QMK_KEYBOARD_H
#include "version.h"

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    /*
     * ,--------------------------------------------------.    ,--------------------------------------------------.
     * |    0   |   1  |   2  |   3  |   4  |   5  |  6   |    |  38  |  39  |  40  |  41  |  42  |  43  |   44   |
     * |--------+------+------+------+------+------+------|    |------+------+------+------+------+------+--------|
     * |    7   |   8  |   9  |  10  |  11  |  12  |  13  |    |  45  |  46  |  47  |  48  |  49  |  50  |   51   |
     * |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+--------|
     * |   14   |  15  |  16  |  17  |  18  |  19  |------|    |------|  52  |  53  |  54  |  55  |  56  |   57   |
     * |--------+------+------+------+------+------|  26  |    |  58  |------+------+------+------+------+--------|
     * |   20   |  21  |  22  |  23  |  24  |  25  |      |    |      |  59  |  60  |  61  |  62  |  63  |   64   |
     * `--------+------+------+------+------+-------------'    `-------------+------+------+------+------+--------'
     *   |  27  |  28  |  29  |  30  |  31  |                                |  65  |  66  |  67  |  68  |  69  |
     *   `----------------------------------'                                `----------------------------------'
     *                                       ,-------------.  ,-------------.
     *                                       |  32  |  33  |  |  70  |  71  |
     *                                ,------+------+------|  |------+------+------.
     *                                |      |      |  34  |  |  72  |      |      |
     *                                |  35  |  36  |------|  |------|  74  |  75  |
     *                                |      |      |  37  |  |  73  |      |      |
     *                                `--------------------'  `--------------------'
     */

[0] = LAYOUT_ergodox_pretty(
            KC_EQUAL,     KC_1,    KC_2,        KC_3,        KC_4,                        KC_5, KC_DELETE,      KC_INSERT    , KC_6     , KC_7    , KC_8    , KC_9  , KC_0                 , KC_MINUS             ,
 MT(MOD_LGUI,KC_TAB),     KC_Q,    KC_W,        KC_E,        KC_R,                        KC_T,     TG(1),      TG(1)        , KC_Y     , KC_U    , KC_I    , KC_O  , KC_P                 , KC_BSLS              ,
             KC_LCTL,     KC_A,    KC_S,        KC_D,        KC_F,                        KC_G,                                KC_H     , KC_J    , KC_K    , KC_L  , LT(2,KC_SCLN)        , MT(MOD_LGUI,KC_QUOTE),
             KC_LSFT,     KC_Z,    KC_X,        KC_C,        KC_V,                        KC_B,   KC_HYPR,      KC_MEH       , KC_N     , KC_M    , KC_COMMA, KC_DOT, MT(MOD_RCTL,KC_SLASH), KC_RSFT              ,
      LT(1,KC_GRAVE), KC_QUOTE, KC_LALT,     KC_LBRC,     KC_RBRC,                                                                        KC_LEFT , KC_DOWN , KC_UP , KC_RIGHT             , MO(1)                ,

                                                             MT(MOD_LALT,KC_APPLICATION),   KC_LGUI,      LSFT(KC_LALT), KC_ESCAPE,
                                                                                            KC_HOME,      KC_PGUP      ,
                                                   KC_SPACE,                     KC_BSPC,    KC_END,      KC_PGDN      , KC_TAB   , KC_ENTER
),

[1] = LAYOUT_ergodox_pretty(
_______,   KC_F1,   KC_F2,       KC_F3,       KC_F4,    KC_F5, _______,      _______, KC_F6  , KC_F7  , KC_F8 , KC_F9, KC_F10   , KC_F11 ,
_______, KC_EXLM,   KC_AT,     KC_LCBR,     KC_RCBR,  KC_PIPE, _______,      _______, KC_UP  , KC_7   , KC_8  , KC_9 , KC_ASTR  , KC_F12 ,
_______, KC_HASH,  KC_DLR,     KC_LPRN,     KC_RPRN, KC_GRAVE,                        KC_DOWN, KC_4   , KC_5  , KC_6 , _______  , _______,
_______, KC_PERC, KC_CIRC,     KC_LBRC,     KC_RBRC,  KC_TILD, _______,      _______, KC_AMPR, KC_1   , KC_2  , KC_3 , KC_BSLS  , _______,
_______, _______, _______,     _______,     _______,                                           _______, KC_DOT, KC_0 , KC_EQUAL , _______,

                                                      _______, _______,      _______, _______,
                                                               _______,      _______,
                                            _______,  _______, _______,      _______, _______, _______
),

[2] = LAYOUT_ergodox_pretty(
_______, _______,    _______,    _______,     _______, _______, _______,      QK_BOOT, _______, _______            , _______          , _______        , _______            , _______            ,
_______, _______,    _______,   KC_MS_UP,     _______, _______, _______,      _______, _______, _______            , _______          , _______        , _______            , _______            ,
_______, _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, _______,                        _______, _______            , _______          , _______        , _______            , KC_MEDIA_PLAY_PAUSE,
_______, _______,    _______,    _______,     _______, _______, _______,      _______, _______, _______            , _______          , _______        , _______            , _______            ,
_______, _______,    _______, KC_MS_BTN1,  KC_MS_BTN2,                                          KC_MEDIA_PREV_TRACK, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_MEDIA_NEXT_TRACK, KC_AUDIO_MUTE      ,

                                                       RGB_MOD, _______,      RGB_TOG, RGB_SLD,
                                                                _______,      _______,
                                              RGB_VAD, RGB_VAI, _______,      _______, RGB_HUD, RGB_HUI
)
};




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {

  uint8_t layer = biton32(state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};



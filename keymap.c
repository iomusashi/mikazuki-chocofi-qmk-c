/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2024 @iomusashi

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Left-hand mods for qwerty
#define SFT_A LSFT_T(KC_A)

// Left-hand mods
#define CTL_Z LCTL_T(KC_Z)
#define OPT_X LOPT_T(KC_X)

// Right-hand mods for qwerty
#define SFT_CLN RSFT_T(KC_SCLN)

// Right-hand mods for colemak-dh
#define SFT_O RSFT_T(KC_O)

// Right-hand mods
#define OPT_DOT LOPT_T(KC_DOT)
#define CTL_SLS RCTL_T(KC_SLSH)

// Right-hand layer mods
#define OPT_QOT LOPT_T(KC_QUOT)
#define CTL_BSL RCTL_T(KC_BSLS)

// Thumb-key mods
#define CMD_SPC LCMD_T(KC_SPC)
#define CMD_ENT RCMD_T(KC_ENT)
#define NUM_ESC LT(_NUMNAVI, KC_ESC)
#define SYM_BSP LT(_SYMBOLS, KC_BSPC)

// Base layer switches
#define QWERTY DF(_BASE)
#define COLEMDH DF(_CDH)

// Layers
enum layers {
    _BASE,
    _CDH,
    _NUMNAVI,
    _SYMBOLS,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   SFT_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, SFT_CLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   CTL_Z,   OPT_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM, OPT_DOT, CTL_SLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_TAB, NUM_ESC, CMD_SPC,    CMD_ENT, SYM_BSP,  KC_GRV
                                      //`--------------------------'  `--------------------------'

  ),

    [_CDH] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   SFT_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,   SFT_O, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   CTL_Z,   OPT_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM, OPT_DOT, CTL_SLS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           KC_TAB, NUM_ESC, CMD_SPC,    CMD_ENT, SYM_BSP,  KC_GRV
                                      //`--------------------------'  `--------------------------'

  ),

    [_NUMNAVI] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, KC_SLSH, KC_ASTR, KC_MINS, KC_PLUS,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, _______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, _______, KC_AMPR, KC_PIPE,  KC_DOT,                       KC_EQL, KC_UNDS, KC_MINS, OPT_QOT, CTL_BSL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, MO(_FN), _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_SYMBOLS] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_LPRN, KC_RPRN, KC_AMPR, KC_ASTR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______,   KC_LT, KC_MINS,   KC_GT, KC_AMPR,                      KC_UNDS, KC_LCBR, KC_RCBR, KC_DQUO, _______, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, _______, _______, KC_ASTR, KC_TILD, KC_PIPE,                       KC_EQL, KC_LBRC, KC_RBRC, OPT_QOT, CTL_BSL, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, MO(_FN), _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_FN] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,  QWERTY, XXXXXXX, KC_BRIU, KC_BRID, XXXXXXX,                      KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, COLEMDH, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MCTL, XXXXXXX,                      KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_SLEP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WAKE, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};


#ifdef BONGO_ENABLE
#include "bongo.h"
//
// Render left OLED display
//
static void render_status(void) {
    // keeb
    oled_write_P(PSTR("   "), false);
    oled_write_P(PSTR("Chocofi // NKC\n"), false);

    oled_write_P(PSTR("   "), false);
    oled_write_P(PSTR("@iomusashi\n"), false);

    // Layer indicator
    oled_write_P(PSTR("   layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case 4:
            oled_write_P(PSTR("FUNCTION  "), false);
            break;

        case 3:
            oled_write_P(PSTR("SYMBOLS   "), false);
            break;

        case 2:
            oled_write_P(PSTR("NUMBER NAV"), false);
            break;

        case 1:
            oled_write_P(PSTR("COLEMAK-DH"), false);
            break;

        // Layer 0
        default:
            oled_write_P(PSTR("BASE LAYER"), false);
            break;
    }
}

//
// Rotate OLED display
//
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	if (!is_keyboard_master()) return OLED_ROTATION_180;
    else return rotation;
}

//
// OLED display rendering
//
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // Left side
        render_status();
    } else {
        // Right side
        draw_bongo(true);
    }
	return 0;
}
#endif

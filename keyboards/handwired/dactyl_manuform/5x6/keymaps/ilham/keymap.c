#include QMK_KEYBOARD_H

enum layers {
    BASE,
    CURSOR,
    NUMBER,
    FUNCTION,
    SYMBOL,
    MOUSE,
    TERMINAL,
};

enum custom_keycodes {
    ALT_TAB = SAFE_RANGE,
    OS_MODE_TOG,   // Toggle OS mode override
    OA_COPY,       // OS-aware copy
    OA_PASTE,      // OS-aware paste
    OA_CUT,        // OS-aware cut
    OA_CLOSE,      // OS-aware close
    OA_CMD_PAL,    // OS-aware command palette
    OA_SELECT_ALL, // OS-aware select all
    OA_FIND,       // OS-aware find
    OA_FIND_NEXT,  // OS-aware find next
    OA_FIND_PREV,  // OS-aware find previous
    OA_RELOAD,     // OS-aware reload
    OA_SAVE,       // OS-aware save
    OA_BOOKMARK,   // OS-aware bookmark
    OA_FULLSCREEN, // OS-aware fullscreen
    OA_HELP,       // OS-aware help
    LEADER_TMUX,   // custom keycode for leader key to activate tmux-like behavior
    BSPC_WORD,
    MY_NAV_LEFT,
    MY_NAV_RIGHT,
    RALT_RSFT,
};

// Home row mods for QWERTY layer for windows and linux
#define QHOME_Z LGUI_T(KC_Z)
#define QHOME_X LALT_T(KC_X)
#define QHOME_C LCTL_T(KC_C)
#define QHOME_V LSFT_T(KC_V)

#define QHOME_M RSFT_T(KC_M)
#define QHOME_COMM CTL_T(KC_COMM)
#define QHOME_DOT ALT_T(KC_DOT)
#define QHOME_SCLN LGUI_T(KC_SCLN)

#define CAPS_WORD QK_CAPS_WORD_TOGGLE


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_5x6(
        KC_EQL,        KC_1, KC_2, KC_3, KC_4, KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,      KC_0,            KC_MINS,
        KC_TAB,        KC_Q, KC_W, KC_E, KC_R, KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,            KC_BSLS,
        MO(TERMINAL),  KC_A, KC_S, KC_D, KC_F, KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,      QHOME_SCLN,      KC_QUOT,
        OSM(MOD_LSFT), QHOME_Z, QHOME_X, QHOME_C, QHOME_V, KC_B,             KC_N, QHOME_M, QHOME_COMM, QHOME_DOT, HYPR_T(KC_SLSH), QK_REP,
            MO(NUMBER), MO(FUNCTION),                                                                   KC_LBRC, LT(MOUSE, KC_RBRC),
        MO(CURSOR), KC_BSPC,                                                                     KC_SPC, MO(SYMBOL),
        OS_MODE_TOG, KC_ESC,                                                                             KC_ENT, QK_BOOT,
        XXX, XXX,                                                                                XXX,  XXX
    ),

  [CURSOR] = LAYOUT_5x6(
        _______,   _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        KC_CAPS,   _______, C(KC_W), OA_COPY, OA_PASTE, OA_CUT,                                     BSPC_WORD,S(KC_TAB), KC_TAB, KC_DEL, _______, _______,
        CAPS_WORD, ALT_TAB,  G(KC_TILD), TG(NUMBER), LEADER_TMUX, C(KC_G),                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CAPS_WORD, _______,
        _______,  OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), OSM(MOD_HYPR),        KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______, _______,
                     _______, _______,                                                                     _______, _______,
                _______,          _______,                                                                     _______, _______,
        _______,          _______,                                                                 _______, _______,
        _______,          _______,                                                                     _______, _______
    ),

  /*
   * Symbol Layer
   *
   * ,-------------------------------------------.                             ,-------------------------------------------.
   * |  `   |  +   |  *   |  =   |  \   |  ~   |                               |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
   * |  &   |  !   |  @   |  {   |  }   |  ?   |                               | Bspc | S-Tab| Tab  | ATab | Cmd  |  |   |
   * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
   * |  #   |  ^   |  -   |  (   |  )   |  $   |                               | Left | Down |  Up  |Right |  :   |      |
   * |------+------+------+------+------+------|                               |------+------+------+------+------+------|
   * |  '   |  "   |  _   |  [   |  ]   |  %   |                               |A+RSft| RSft | RCtl | RAlt | RGui |      |
   * `-------------+------+------.                               .------+------+------+-------------'
   *               |      |      |                               |      |      |
   *               `------+------+                               +------+------'
   *                      |      |                               |      |
   *                      `------'                               `------'
   *                      |      |                               |      |
   *                      `------'                               `------'
   *                      |      |                               |      |
   *                      `------'                               `------'
   */
  [SYMBOL] = LAYOUT_5x6(
        KC_GRV,  KC_PLUS, KC_ASTR, KC_EQL,  KC_BSLS, KC_TILD,                           _______, _______, _______, _______, _______, _______,
        KC_AMPR, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_QUES,                           KC_BSPC, S(KC_TAB), KC_TAB, ALT_TAB, OA_CMD_PAL, KC_PIPE,
        KC_HASH, KC_CIRC, KC_MINS, KC_LPRN, KC_RPRN, KC_DLR,                            KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_COLN, _______,
        KC_QUOT, KC_DQUO, KC_UNDS, KC_LBRC, KC_RBRC, KC_PERC,                           HYPR(KC_SPC), OSM(MOD_RSFT), KC_RCTL, KC_RALT, KC_RGUI, _______,
             _______, _______,                                                                     _______, _______,
                _______, _______,                                                                  _______, _______,
                _______, _______,                                                                  _______, _______,
                _______, _______,                                                                  _______, _______
    ),

  [NUMBER] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,                              _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                              KC_X,    KC_7,   KC_8,   KC_9,   KC_ASTR, _______,
        _______, _______, _______, _______, LEADER_TMUX, _______,                          KC_MINS, KC_4,   KC_5,   KC_6,   KC_PLUS, _______,
        _______, KC_RGUI, KC_RALT, KC_RCTL, KC_RSFT, _______,                              KC_0,    KC_1,   KC_2,   KC_3,   KC_SLSH, _______,
                 _______, QK_LLCK,                                                                      _______, _______,
            KC_RGUI, KC_RCTL,                                                                             _______,_______,
            _______, _______,                                                                             _______,_______,
            _______, _______,                                                                             _______,_______
    ),


  [FUNCTION] = LAYOUT_5x6(
        _______, C(KC_PGUP), C(KC_PGDN), _______, _______, _______,                               KC_MSEL, KC_MPLY, KC_MPRV, KC_MNXT, KC_MSTP, KC_CIRC,
        _______, OA_CLOSE,OA_FIND, OA_FIND_NEXT, OA_RELOAD, _______,                            _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  OA_HELP,
        _______, OA_SELECT_ALL, OA_SAVE, OA_BOOKMARK, OA_FULLSCREEN, _______,                    _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_PSCR,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                               _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  KC_MUTE,
             _______, _______,                                                                      KC_VOLD, KC_VOLU,
             A(KC_1), A(KC_2),                                                                     A(KC_7), A(KC_6),
             _______, A(KC_3),                                                                     A(KC_8), _______,
             _______, _______,                                                                     _______, _______
    ),

  [MOUSE] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,                               _______, _______, _______, _______, _______, _______,
        _______, _______, MS_WHLL, MS_UP,   MS_WHLR, _______,                               _______, _______, _______, _______, _______, _______,
        _______, _______, MS_LEFT, MS_DOWN, MS_RGHT, _______,                               _______, MS_ACL0, MS_ACL1, MS_ACL2, _______, _______,
        _______, _______, _______, MS_WHLD, MS_WHLU, _______,                               _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
        MS_BTN4, MS_BTN5,                                                                                           _______, _______,
        _______, MS_BTN1,                                                                                           _______, _______,
        MS_BTN3, MS_BTN2,                                                                                           _______, _______,
        _______, _______,                                                                                           _______, _______
    ),

  [TERMINAL] = LAYOUT_5x6(
        _______, _______, _______, _______, _______,  _______,                                  _______, _______, _______, _______, _______, _______,
        _______, _______, C(KC_W), C(KC_E), C(KC_R),  C(KC_T),                                  _______, _______, _______, _______, C(KC_P), _______,
        _______, C(KC_A), C(KC_S), C(KC_D), C(KC_F),  _______,                                  C(KC_H), C(KC_J), C(KC_K), C(KC_L), _______, _______,
        _______, _______, C(KC_X), C(KC_C), C(KC_V), _______,                                   C(KC_N), _______, _______, _______, _______, _______,
                    _______,   _______,                                                                     MY_NAV_LEFT, MY_NAV_RIGHT,
        C(KC_TAB), C(S(KC_TAB)),                                                                                     _______, _______,
        _______,   _______,                                                                                     _______, _______,
        _______,   _______,                                                                                     _______, _______
    ),
};


#ifdef CAPS_WORD_ENABLE
bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
      add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_MINS:
    case KC_UNDS:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}
#endif  // CAPS_WORD_ENABLE

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QHOME_V:
    case QHOME_M:
      // Shift mod-taps benefit from a little more time so opposite-hand
      // capitals like V+I don't accidentally become "vi".
      return TAPPING_TERM + 35;
    default:
      return TAPPING_TERM;
  }
}

#ifdef FLOW_TAP_TERM
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record,
                           uint16_t prev_keycode) {
  // Only apply Flow Tap when following a letter key without hotkey mods.
  if (get_tap_keycode(prev_keycode) <= KC_Z &&
      (get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) == 0) {
    switch (keycode) {
      case QHOME_Z:
      case QHOME_X:
      case QHOME_C:
      case QHOME_SCLN:
      case QHOME_DOT:
      case QHOME_COMM:
        return FLOW_TAP_TERM;
      case QHOME_V:
      case QHOME_M:
        return FLOW_TAP_TERM - 25;
    }
  }
  return 0;
}
#endif  // FLOW_TAP_TERM

#ifdef CHORDAL_HOLD
bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
    // Exceptionally allow some one-handed chords for hotkeys.
    switch (tap_hold_keycode) {
        case QHOME_Z:
            if (other_keycode == KC_C || other_keycode == KC_V || other_keycode == KC_F) {
                return true;
            }
            break;

        case QHOME_SCLN:
            if (other_keycode == KC_N) {
                return true;
            }
            break;
    }
    // Otherwise defer to the opposite hands rule.
    return get_chordal_hold_default(tap_hold_record, other_record);
}
#endif  // CHORDAL_HOLD

#ifdef SPECULATIVE_HOLD
bool get_speculative_hold(uint16_t keycode, keyrecord_t* record) {
  return true;  // Enable for all mods.
}
#endif  // SPECULATIVE_HOLD

bool is_alt_tab_active = false;
bool is_mac_mode = true;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          if (is_mac_mode) {
            register_code(KC_LGUI);
          } else {
            register_code(KC_LALT);
          }
        }
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      return false;

    case KC_ENTER:
      if (record->event.pressed) {
        if (is_alt_tab_active) {
          if (is_mac_mode) {
            unregister_code(KC_LGUI);
          } else {
            unregister_code(KC_LALT);
          }
          is_alt_tab_active = false;
          return false;
        }
      }
      return true;

    case KC_ESCAPE:
        if (record->event.pressed) {
            if (is_alt_tab_active) {
                if (is_mac_mode) {
                    unregister_code(KC_LGUI);
                } else {
                    unregister_code(KC_LALT);
                }
                unregister_code(KC_TAB); // Ensure Tab is also released
                is_alt_tab_active = false;
                tap_code(KC_ESCAPE); // Send an actual ESC key press to the OS
                return false; // We handled it.
            }
        }
        return true;

    case OS_MODE_TOG:
      if (record->event.pressed) {
        // Toggle between macOS and Windows/Linux modes
        is_mac_mode = !is_mac_mode;
      }
      return false; // Skip all further processing of this key

    case OA_CMD_PAL:
        if (record->event.pressed) {
            tap_code16(is_mac_mode ? LGUI(KC_SPC) : LALT(KC_SPC));
        }
        return false; // Skip all further processing of this key

    case OA_SELECT_ALL:
        if (record->event.pressed) {
            tap_code16(is_mac_mode ? LGUI(KC_A) : LCTL(KC_A));
        }
        return false;

    case OA_FIND:
        if (record->event.pressed) {
            tap_code16(is_mac_mode ? LGUI(KC_F) : LCTL(KC_F));
        }
        return false;

    case OA_FIND_NEXT:
        if (record->event.pressed) {
            tap_code16(is_mac_mode ? LGUI(KC_G) : KC_F3);
        }
        return false;

    case OA_FIND_PREV:
        if (record->event.pressed) {
            tap_code16(is_mac_mode ? LGUI(S(KC_G)) : LSFT(KC_F3));
        }
        return false;

    case OA_RELOAD:
        if (record->event.pressed) {
            tap_code16(is_mac_mode ? LGUI(KC_R) : LCTL(KC_R));
        }
        return false;

    case OA_SAVE:
        if (record->event.pressed) {
            tap_code16(is_mac_mode ? LGUI(KC_S) : LCTL(KC_S));
        }
        return false;

    case OA_BOOKMARK:
        if (record->event.pressed) {
            tap_code16(is_mac_mode ? LGUI(KC_D) : LCTL(KC_D));
        }
        return false;

    case OA_FULLSCREEN:
        if (record->event.pressed) {
            tap_code16(is_mac_mode ? LGUI(LCTL(KC_F)) : KC_F11);
        }
        return false;

    case OA_HELP:
        if (record->event.pressed) {
            tap_code16(is_mac_mode ? LGUI(S(KC_SLSH)) : KC_F1);
        }
        return false;

    case OA_COPY:
        if (record->event.pressed) {
            tap_code16(is_mac_mode ? LGUI(KC_C) : LCTL(KC_C));
        }
        return false;

    case OA_PASTE:
        if (record->event.pressed) {
            tap_code16(is_mac_mode ? LGUI(KC_V) : LCTL(KC_V));
        }
        return false;

    case OA_CUT:
        if (record->event.pressed) {
            tap_code16(is_mac_mode ? LGUI(KC_X) : LCTL(KC_X));
        }
        return false; // Skip all further processing of this key

    case OA_CLOSE:
        if (record->event.pressed) {
            if (is_mac_mode) {
                tap_code16(LGUI(KC_Q));
            } else {
                tap_code16(LALT(KC_F4));
            }
        }
        return false; // Skip all further processing of this key

    case BSPC_WORD:
        if (record->event.pressed) {
            if (is_mac_mode) {
                // Mac: Option + Backspace
                tap_code16(LALT(KC_BSPC));
            } else {
                // Linux/Windows: Ctrl + Backspace
                tap_code16(LCTL(KC_BSPC));
            }
        }
        return false; // Skip all further processing of this key

    case LEADER_TMUX:
        if (record->event.pressed) {
            tap_code16(LCTL(KC_F)); // Send Ctrl + F to activate tmux-like behavior
         }
        return false;

    case MY_NAV_LEFT:
        if (record->event.pressed) {
            if (is_mac_mode) {
                // macOS: ctrl + Left Arrow
                tap_code16(LCTL(KC_LEFT));
            } else {
                 // Linux: ctrl + Left Arrow
                tap_code16(LCTL(KC_LEFT));
            }
       }
       return false; // Skip all further processing of this key

    case MY_NAV_RIGHT:
        if (record->event.pressed) {
            if (is_mac_mode) {
                // macOS: ctrl + Right Arrow
                tap_code16(LCTL(KC_RGHT));
            } else {
                 // Linux: ctrl + Right Arrow
                tap_code16(LCTL(KC_RGHT));
            }
       }
       return false; // Skip all further processing of this key

    case RALT_RSFT:
        if (record->event.pressed) {
            register_code(KC_RALT);
            register_code(KC_RSFT);
        } else {
            unregister_code(KC_RSFT);
            unregister_code(KC_RALT);
        }
        return false;

    default:
      return true;
  }
}

void matrix_scan_user(void) {
  if (IS_LAYER_OFF(CURSOR) && IS_LAYER_OFF(SYMBOL) && is_alt_tab_active) {
      if (is_mac_mode) {
        unregister_code(KC_LGUI);
      } else {
        unregister_code(KC_LALT);
      }
      is_alt_tab_active = false;
    }
}

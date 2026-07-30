#include QMK_KEYBOARD_H

enum layers {
    BASE,
    NAV,
    NUMBER,
    FUNCTION,
    SYMBOL,
    MOUSE,
    NAVWIN,
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
    OA_RELOAD,     // OS-aware reload
    OA_SAVE,       // OS-aware save
    OA_BOOKMARK,   // OS-aware bookmark
    OA_FULLSCREEN, // OS-aware fullscreen
    OA_HELP,       // OS-aware help
    LEADER_TMUX,   // custom keycode for leader key to activate tmux-like behavior
    KC_DWRD,
    MY_NAV_LEFT,
    MY_NAV_RIGHT,
    OA_REDO,       // OS-aware redo
    OA_NEW_TAB,    // OS-aware new tab
    OA_CLOSE_WIN,  // Close window (Cmd+W / Ctrl+W)
    SW_WIN,        // Window switcher within app (Cmd+`)
    PRV_TAB,       // Previous tab (Ctrl+Shift+Tab)
    NXT_TAB,       // Next tab (Ctrl+Tab)
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
        KC_EQL, KC_1, KC_2, KC_3, KC_4, KC_5,                                 KC_6,    KC_7,    KC_8,    KC_9,      KC_0,            KC_MINS,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                 KC_Y,    KC_U,    KC_I,    KC_O,      KC_P,            KC_BSLS,
        MO(NAVWIN),  KC_A, KC_S, KC_D, KC_F, KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,      QHOME_SCLN,      KC_QUOT,
        OSM(MOD_LSFT), QHOME_Z, QHOME_X, QHOME_C, QHOME_V, KC_B,              KC_N, QHOME_M, QHOME_COMM, QHOME_DOT, HYPR_T(KC_SLSH), KC_F18,
            MO(NUMBER), MO(FUNCTION),                                                              KC_LBRC, KC_RBRC,
        MO(NAV), LT(MOUSE,KC_BSPC),                                                              KC_SPC, MO(SYMBOL),
        QK_BOOT, KC_ESC,                                                                             KC_ENT, QK_REP,
        XXX, OSM(MOD_LSFT),                                                                      G(A(KC_SPC)),  XXX
    ),

  [NAV] = LAYOUT_5x6(
        _______,   _______,  _______,  _______,  OA_REDO, _______,                                    _______, _______, _______, _______, _______, _______,
        KC_CAPS,   _______,  C(KC_W),  OA_COPY, OA_PASTE, OA_CUT,                                     KC_DWRD,  S(KC_TAB), KC_TAB, KC_DEL, _______, _______,
        CAPS_WORD, ALT_TAB,  SW_WIN,  KC_F18, LEADER_TMUX, NXT_TAB,                                  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CAPS_WORD, _______,
        OSL(NAVWIN),   OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), OSL(FUNCTION),         KC_HOME, KC_PGDN, KC_PGUP, KC_END,   _______, _______,
                     KC_ENT, KC_SPC,                                                                    MY_NAV_LEFT, MY_NAV_RIGHT,
                _______,          _______,                                                                     _______, _______,
        _______,          _______,                                                                 _______, _______,
        _______,          _______,                                                                     _______, _______
    ),

  [NAVWIN] = LAYOUT_5x6(
        _______,  _______,  _______,  _______,  _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______,  HYPR(KC_Q),    HYPR(KC_W), HYPR(KC_F), HYPR(KC_P), HYPR(KC_B),                       A(KC_J), A(KC_7), A(KC_8), A(KC_9), A(KC_QUOT), _______,
        _______,  HYPR(KC_A),    HYPR(KC_S), HYPR(KC_D), HYPR(KC_F), HYPR(KC_V),                       A(KC_M), A(KC_4), A(KC_5), A(KC_6),    A(KC_O), _______,
        _______,  OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), _______,                 A(KC_0), A(KC_1), A(KC_2), A(KC_3), A(KC_SLSH), _______,
                    _______, _______,                                                       _______, _______,
              _______,          _______,                                                       _______, _______,
              _______,          _______,                                                       _______, _______,
              _______,          _______,                                                       _______, _______
    ),

  [SYMBOL] = LAYOUT_5x6(
        KC_GRV,  KC_PLUS, KC_ASTR, KC_EQL,  KC_BSLS, KC_TILD,                           _______, _______, _______, _______, _______, G(C(S(KC_I))),
        KC_AMPR, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_QUES,                           KC_BSPC, S(KC_TAB), KC_TAB, ALT_TAB, OA_CMD_PAL, HYPR(KC_7),
        KC_HASH, KC_CIRC, KC_MINS, KC_LPRN, KC_RPRN, KC_DLR,                            KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_COLN, HYPR(KC_8),
        KC_QUOT, KC_DQUO, KC_UNDS, KC_LBRC, KC_RBRC, KC_PERC,                           _______, OSM(MOD_RSFT), KC_RCTL, KC_RALT, KC_RGUI, HYPR(KC_9),
             _______, _______,                                                                     _______, _______,
                _______, KC_DEL,                                                                  _______, _______,
                OS_MODE_TOG, _______,                                                                  _______, _______,
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
        _______, C(KC_PGUP), C(KC_PGDN), _______, _______, _______,                             KC_MSEL, KC_MPLY, KC_MPRV, KC_MNXT, KC_MSTP, KC_CIRC,
        _______, OA_CLOSE, OA_CLOSE_WIN, OA_FIND_NEXT, OA_RELOAD, OA_NEW_TAB,                            _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  OA_HELP,
        _______, OA_SELECT_ALL, OA_SAVE, OA_BOOKMARK, OA_FIND, OA_FULLSCREEN,                   _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,  KC_PSCR,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                                   _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,  KC_MUTE,
             _______, _______,                                                                      KC_VOLD, KC_VOLU,
             A(KC_1), A(KC_2),                                                                     A(KC_7), A(KC_6),
             _______, A(KC_3),                                                                     A(KC_8), _______,
             _______, _______,                                                                     _______, _______
    ),

  [MOUSE] = LAYOUT_5x6(
        _______, _______, _______, _______, _______, _______,                               _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                               _______, _______, _______, _______, _______, _______,
        _______, _______, MS_BTN2, MS_BTN3, MS_BTN1, LSFT(MS_BTN1),                         _______, MS_ACL0, MS_ACL1, MS_ACL2, _______, _______,
        _______, _______, OA_COPY, MS_BTN4, MS_BTN5, LGUI(MS_BTN1),                         _______, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, _______,
        _______, _______,                                                                                           _______, _______,
        _______, _______,                                                                                           _______, _______,
        _______, _______,                                                                                           _______, _______,
        _______, _______,                                                                                           _______, _______
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
      return TAPPING_TERM + 20;
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
bool is_sw_win_active = false;
bool is_tab_nav_active = false;
bool is_mac_mode = true;

// Sends `mac_code` on macOS, `win_code` on Windows (register/unregister).
void send_mac_or_win(uint16_t mac_code, uint16_t win_code, bool is_pressed) {
    uint16_t code = is_mac_mode ? mac_code : win_code;
    if (is_pressed) {
        register_code16(code);
    } else {
        unregister_code16(code);
    }
}

// Taps `mac_code` on macOS, `win_code` on Windows (one-shot).
void tap_mac_or_win(uint16_t mac_code, uint16_t win_code) {
    tap_code16(is_mac_mode ? mac_code : win_code);
}

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
        if (is_sw_win_active) {
          unregister_code(KC_LGUI);
          is_sw_win_active = false;
          return false;
        }
        if (is_tab_nav_active) {
          unregister_code(KC_LCTL);
          is_tab_nav_active = false;
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
            if (is_sw_win_active) {
                unregister_code(KC_LGUI);
                unregister_code(KC_GRV);
                is_sw_win_active = false;
                return false;
            }
            if (is_tab_nav_active) {
                unregister_code(KC_LCTL);
                is_tab_nav_active = false;
                return false;
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
            tap_mac_or_win(G(KC_SPC), A(KC_SPC));
        }
        return false; // Skip all further processing of this key

    case OA_SELECT_ALL:
        if (record->event.pressed) {
            tap_mac_or_win(G(KC_A), C(KC_A));
        }
        return false;

    case OA_FIND:
        if (record->event.pressed) {
            tap_mac_or_win(G(KC_F), C(KC_F));
        }
        return false;

    case OA_FIND_NEXT:
        if (record->event.pressed) {
            tap_mac_or_win(G(KC_G), KC_F3);
        }
        return false;

    case OA_RELOAD:
        if (record->event.pressed) {
            tap_mac_or_win(G(KC_R), C(KC_R));
        }
        return false;

    case OA_SAVE:
        if (record->event.pressed) {
            tap_mac_or_win(G(KC_S), C(KC_S));
        }
        return false;

    case OA_BOOKMARK:
        if (record->event.pressed) {
            tap_mac_or_win(G(KC_D), C(KC_D));
        }
        return false;

    case OA_FULLSCREEN:
        if (record->event.pressed) {
            tap_mac_or_win(G(C(KC_F)), KC_F11);
        }
        return false;

    case OA_HELP:
        if (record->event.pressed) {
            tap_mac_or_win(G(S(KC_SLSH)), KC_F1);
        }
        return false;

    case OA_COPY:
        send_mac_or_win(G(KC_C), C(KC_C), record->event.pressed);
        return false;

    case OA_PASTE:
        send_mac_or_win(G(KC_V), C(KC_V), record->event.pressed);
        return false;

    case OA_CUT:
        send_mac_or_win(G(KC_X), C(KC_X), record->event.pressed);
        return false;

    case OA_CLOSE:
        if (record->event.pressed) {
            tap_mac_or_win(G(KC_Q), A(KC_F4));
        }
        return false; // Skip all further processing of this key

    // Delete the previous word (hold to repeat)
    case KC_DWRD:
        send_mac_or_win(A(KC_BSPC), C(KC_BSPC), record->event.pressed);
        return false;

    case LEADER_TMUX:
        if (record->event.pressed) {
            tap_code16(LCTL(KC_F)); // Send Ctrl + F to activate tmux-like behavior
         }
        return false;

    case MY_NAV_LEFT:
        if (record->event.pressed) {
            tap_code16(C(KC_LEFT));
        }
        return false; // Skip all further processing of this key

    case MY_NAV_RIGHT:
        if (record->event.pressed) {
            tap_code16(C(KC_RGHT));
        }
        return false; // Skip all further processing of this key

    case OA_REDO:
        send_mac_or_win(G(S(KC_Z)), C(KC_Y), record->event.pressed);
        return false;

    case OA_NEW_TAB:
        send_mac_or_win(G(KC_T), C(KC_T), record->event.pressed);
        return false;

    case OA_CLOSE_WIN:
        send_mac_or_win(G(KC_W), C(KC_W), record->event.pressed);
        return false;

    case SW_WIN:
        if (record->event.pressed) {
            if (!is_sw_win_active) {
                is_sw_win_active = true;
                register_code(KC_LGUI);
            }
            register_code(KC_GRV);
        } else {
            unregister_code(KC_GRV);
        }
        return false;

    case PRV_TAB:
        if (record->event.pressed) {
            if (!is_tab_nav_active) {
                is_tab_nav_active = true;
                register_code(KC_LCTL);
            }
            register_code(KC_LSFT);
            register_code(KC_TAB);
        } else {
            unregister_code(KC_TAB);
            unregister_code(KC_LSFT);
        }
        return false;

    case NXT_TAB:
        if (record->event.pressed) {
            if (!is_tab_nav_active) {
                is_tab_nav_active = true;
                register_code(KC_LCTL);
            }
            register_code(KC_TAB);
        } else {
            unregister_code(KC_TAB);
        }
        return false;

    default:
      return true;
  }
}

void matrix_scan_user(void) {
  if (IS_LAYER_OFF(NAV)) {
    if (IS_LAYER_OFF(SYMBOL) && is_alt_tab_active) {
      if (is_mac_mode) {
        unregister_code(KC_LGUI);
      } else {
        unregister_code(KC_LALT);
      }
      is_alt_tab_active = false;
    }
    if (is_sw_win_active) {
      unregister_code(KC_LGUI);
      is_sw_win_active = false;
    }
    if (is_tab_nav_active) {
      unregister_code(KC_LCTL);
      is_tab_nav_active = false;
    }
  }
}

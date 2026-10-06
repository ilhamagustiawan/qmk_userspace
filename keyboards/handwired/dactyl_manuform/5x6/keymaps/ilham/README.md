# Ilham's Dactyl keymap: Super Leader

[Super Leader documentation](https://getreuer.info/posts/keyboards/super-leader/index.html)

## Usage

Tap and release `LEADER` (the leftmost home-row key on BASE, immediately
left of A), then tap the sequence keys in order. These are sequences, not
chords: you do not need to hold LEADER.

| Keys after LEADER | Action |
| --- | --- |
| C | Copy |
| V | Paste |
| X | Cut |
| S | Save |
| F | Find |
| U | Undo |
| R | Redo |
| A | Select all |
| T, N / T, C | New tab / close tab (Cmd/Ctrl+W) |
| T, J / T, K | Next / previous tab (Ctrl+Tab / Ctrl+Shift+Tab) |
| E, P | Command palette |
| E, N | Find next |
| E, H | Help |
| B, O | Send Hyper+B to open browser (requires an OS/launcher binding) |
| B, R / B, B | Reload / bookmark |
| W, F | Toggle fullscreen |
| P | Type `()` and put the cursor between the parentheses |
| D, B / D, C | Type `[]` / `{}` with the cursor inside |
| D, Q / D, S | Type double / single quotes with the cursor inside |

Shortcuts reuse the existing `OA_*` custom keycodes. Mac mode is the default;
`OS_MODE_TOG` on SYMBOL switches between Mac and Windows/Linux shortcuts.
The separate `LEADER_TMUX` key still sends Ctrl+F; it is unrelated to Super Leader.

All sequences resolve immediately on completion. T (tabs), E (editor),
B (browser), W (window), and D (delimiters) are group prefixes, not standalone
actions. Tab navigation uses non-sticky shortcuts rather than the NAV layer's
`PRV_TAB` / `NXT_TAB` handlers. Actual shortcut behavior depends on the app. The timeout is
1000 ms **between keys**, not a delay before running each action. If you add
both `(KC_T)` and `(KC_T, KC_N)`, T becomes ambiguous: the module waits for
more input or timeout before deciding which action to run. On a mismatch or
timeout, it executes the longest valid match and replays leftover keys.
There is no empty-sequence fallback here: LEADER alone produces no output.

Tap-hold inputs are matched by their tap keycodes by default, so your home-row
mods can be used as sequence letters. Tap them rather than holding them.

## Files and customization

- `keymap.json` enables `getreuer/super_leader`.
- `super_leader.def` contains your sequences; edit this to add/remove actions.
- `config.h` sets `SUPER_LEADER_TIMEOUT`.
- `rules.mk` keeps QMK's built-in `LEADER_ENABLE = no`. Keep
  `REPEAT_KEY_ENABLE = yes` (or enable Combos); the module needs the keycode
  field that these features provide.
- The dependency is pinned as the Git submodule `modules/getreuer` at the
  userspace root. QMK wires up its hooks automatically; no manual include or
  `process_record_user()` call is needed.

Example additions in `super_leader.def`:

```c
// First argument: unique C identifier. Second: parenthesized input keys.
// Third: output. No semicolon is needed.
SEQ_KEY(line_start, (KC_L), KC_HOME)
SEQ_STR(email, (KC_M, KC_E), "replace-with-your-email@example.com")
```

Other output types are `SEQ_FUN` for a custom `void callback(void*)` function
in `keymap.c`, and `SEQ_UNI` for Unicode text (requires additional QMK Unicode
configuration). The default maximum sequence length is five keys, excluding
LEADER. Avoid prefix overlap when you want instant actions.

String macros assume a matching host keyboard layout (QMK defaults to US).
Test the parentheses macro in a scratch text editor if your host layout differs.
Do not store passwords or other secrets in firmware macros.

## Build and flash

From the userspace root, initialize dependencies after cloning:

```sh
git submodule update --init --recursive
```

This machine's QMK checkout is `~/Developer/git/qmk_firmware`. The following
commands use it without changing global QMK configuration:

```sh
QMK_HOME="$HOME/Developer/git/qmk_firmware" \
  qmk compile -kb handwired/dactyl_manuform/5x6 -km ilham

# Run only when ready to flash; reset the connected half into its bootloader
# when prompted. Flash both halves with the same firmware.
QMK_HOME="$HOME/Developer/git/qmk_firmware" \
  qmk flash -kb handwired/dactyl_manuform/5x6 -km ilham
```

The build produces `handwired_dactyl_manuform_5x6_ilham.hex` in the userspace
root. Compilation was verified locally; flashing and hardware behavior still
need testing.

After flashing, test LEADER, P in a scratch editor, then copy/paste and the OS
mode toggle. Make sure ordinary C/V/X typing and home-row mods still work.

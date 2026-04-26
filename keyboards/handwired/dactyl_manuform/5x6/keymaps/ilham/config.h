#pragma once

#define MASTER_LEFT

// Unfortunately, some applications drop or misorder fast key events. This is a
// partial fix to slow down the rate at which macros are sent.
#define TAP_CODE_DELAY 5

// Tap-hold configuration for home row mods.
#define TAPPING_TERM 240
#define TAPPING_TERM_PER_KEY
#define FLOW_TAP_TERM 100
#define CHORDAL_HOLD
#define SPECULATIVE_HOLD
#define QUICK_TAP_TERM 0
#define QUICK_TAP_TERM_PER_KEY

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// Use Left Ctrl + Right Ctrl to activate the Command feature.
#define IS_COMMAND() (get_mods() == MOD_MASK_CTRL)

// Holding Shift while Caps Word is active inverts the shift state.
#define CAPS_WORD_INVERT_ON_SHIFT
// When idle, turn off Caps Word after 5 seconds.
#define CAPS_WORD_IDLE_TIMEOUT 5000

#define SELECT_WORD_TIMEOUT 2000 // When idle, clear state after 2 seconds.

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
#define LAYER_STATE_8BIT

#define LAYER_LOCK_IDLE_TIMEOUT \
    60000 // Turn off after 60 seconds.
          //
// Set the mouse settings to a comfortable speed/accuracy trade-off,
// assuming a screen refresh rate of 60 Htz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16

// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 40

// The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 100

// It makes sense to use the same delay for the mouseweel
#undef MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 100

// The default is 100
// This is the time between wheel ticks.
#define MOUSEKEY_WHEEL_INTERVAL 50

// The default is 40
#undef MOUSEKEY_WHEEL_TIME_TO_MAX
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100

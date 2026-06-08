#pragma once

// =====================================================
// config.h — NeoNix Display Engine + Snake Game
// No FastLED dependency — pure Arduino
// =====================================================

// ── Hardware ──────────────────────────────────────
#define NEONIX_DATA_PIN         10      // WS2812B data pin

// ── Grid Dimensions ───────────────────────────────
#define NEONIX_GRID_WIDTH       16
#define NEONIX_GRID_HEIGHT      16
#define NEONIX_NUM_LEDS         (NEONIX_GRID_WIDTH * NEONIX_GRID_HEIGHT)

// ── Display ───────────────────────────────────────
#define NEONIX_BRIGHTNESS       64      // 0-255 global brightness

// ── Serial ────────────────────────────────────────
#define NEONIX_SERIAL_BAUD      115200

// ── Drawing Defaults ──────────────────────────────
#define NEONIX_DEFAULT_FG_R     255
#define NEONIX_DEFAULT_FG_G     255
#define NEONIX_DEFAULT_FG_B     255
#define NEONIX_DEFAULT_BG_R     0
#define NEONIX_DEFAULT_BG_G     0
#define NEONIX_DEFAULT_BG_B     0

// ── Font ──────────────────────────────────────────
#define NEONIX_FONT_W           4       // glyph width  (pixels)
#define NEONIX_FONT_H           6       // glyph height (pixels)
#define NEONIX_FONT_SPACING     1       // gap between characters

// ── Sprite ────────────────────────────────────────
#define NEONIX_MAX_SPRITE_W     16
#define NEONIX_MAX_SPRITE_H     16

// ── Generic bit-bang NOP tuning (non-AVR, non-ESP32) ──
// Increase if T0H/T1H pulses are too short for your CPU speed
// #define NEONIX_NOP_T0H  2
// #define NEONIX_NOP_T1H  6

// =====================================================
// Snake Game Configuration
// =====================================================

// ── Controller 1 pin map ──────────────────────────
#define SNAKE_BTN_UP        5
#define SNAKE_BTN_LEFT      6
#define SNAKE_BTN_RIGHT     7
#define SNAKE_BTN_DOWN      12
#define SNAKE_BTN_MENU      4

// ── Buzzer ────────────────────────────────────────
#define SNAKE_BUZZER_PIN    11

// ── OLED (I2C) ────────────────────────────────────
#define SNAKE_OLED_WIDTH    128
#define SNAKE_OLED_HEIGHT   64
#define SNAKE_OLED_RESET    -1      // shared Arduino reset
#define SNAKE_OLED_ADDR     0x3C    // I2C address (try 0x3D if 0x3C fails)

// ── Game tuning ───────────────────────────────────
#define SNAKE_INITIAL_LENGTH    3
#define SNAKE_SPEED_MS          200   // ms per tick (lower = faster)
#define SNAKE_MAX_LENGTH        (NEONIX_GRID_WIDTH * NEONIX_GRID_HEIGHT)

// ── Snake LED colors (R, G, B) ────────────────────
#define SNAKE_COL_HEAD_R    0
#define SNAKE_COL_HEAD_G    255
#define SNAKE_COL_HEAD_B    50

#define SNAKE_COL_FOOD_R    255
#define SNAKE_COL_FOOD_G    60
#define SNAKE_COL_FOOD_B    0

// Body brightness is gradient: tail=BODY_DIM → neck=BODY_BRIGHT
#define SNAKE_BODY_BRIGHT   180     // green brightness near head
#define SNAKE_BODY_DIM      60      // green brightness at tail

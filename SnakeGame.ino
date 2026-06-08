// =====================================================
// SnakeGame.ino — NeoNix Snake — Arduino entry point
//
// File layout:
//   SnakeGame.ino   ← this file (setup + loop only)
//   SnakeGame.h     ← class declaration
//   SnakeGame.cpp   ← full game logic
//   config.h        ← ALL pin & tuning constants
//   NeoNixDisplay.h/.cpp  ← LED matrix driver
//   NeoNixDriver.h/.cpp   ← WS2812B low-level driver
//   NeoNixColor.h         ← CRGB type
//   NeoNixFont.h          ← 4×6 bitmap font
//   NeoNixSprite.h/.cpp   ← sprite helpers
//   CommandParser.h/.cpp  ← (unused in game, keep in folder)
//
// Libraries required (Arduino IDE Library Manager):
//   • Adafruit SSD1306
//   • Adafruit GFX Library
// =====================================================

#include "config.h"
#include "NeoNixDisplay.h"
#include "SnakeGame.h"

// ── Shared hardware objects ───────────────────────
NeoNixDisplay   display;
Adafruit_SH1106G oled(
    SNAKE_OLED_WIDTH,
    SNAKE_OLED_HEIGHT,
    &Wire,
    SNAKE_OLED_RESET
);

// ── Game instance ─────────────────────────────────
SnakeGame game(display, oled);

// =====================================================
void setup()
{
    Serial.begin(NEONIX_SERIAL_BAUD);

    // Initialise LED matrix
    display.begin();
    display.clearDisplay();
    display.show();

    // Initialise OLED
    Wire.begin(8, 9);
    Wire.setClock(100000);
    if (!oled.begin(SNAKE_OLED_ADDR, true))
    {
        Serial.println(F("OLED not found — check wiring & SNAKE_OLED_ADDR in config.h"));
        // Game continues without OLED
    }
    else
    {
        oled.clearDisplay();
        oled.display();
    }

    // Start game (shows title screens)
    game.begin();
}

// =====================================================
void loop()
{
    game.update();
}

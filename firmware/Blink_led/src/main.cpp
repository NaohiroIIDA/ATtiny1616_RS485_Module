#include <Arduino.h>

// ATtiny1616 RS485 Module - Blink_led
// 状態LED（PB0）を500msごとに点滅させる

#define LED      PIN_PB0   // 状態LED（1kΩ経由）
#define RS485_DE PIN_PB4   // RS485 DE / RE#（Highで送信）

#define BLINK_INTERVAL_MS 500

void setup() {
  // RS485ドライバは無効（受信状態）にしておき、バスを駆動しない
  pinMode(RS485_DE, OUTPUT);
  digitalWrite(RS485_DE, LOW);

  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(BLINK_INTERVAL_MS);
  digitalWrite(LED, LOW);
  delay(BLINK_INTERVAL_MS);
}

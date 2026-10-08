# Blink_led

ATtiny1616 RS485モジュールの状態LED（PB0）を500ms間隔で点滅させるサンプルです。
RS485のDE/RE#（PB4）はLowにして、バスを駆動しないようにしています。

## ビルドと書き込み

このフォルダ（`firmware/Blink_led`）で実行します。

```bash
# ビルド
pio run

# ヒューズ書き込み（20MHz設定など。初回のみ）
pio run -t fuses --upload-port /dev/cu.usbserial-120

# 書き込み
pio run -t upload --upload-port /dev/cu.usbserial-120
```

ポート名は `pio device list` で確認してください（Windowsなら `COM4` など）。
書き込みはSerialUPDI（U9コネクタ）で行います。

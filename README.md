# ATtiny1616_RS485_Module

ATtiny1616マイコンとRS485トランシーバを搭載した小型の基板モジュールです。

## 概要

- **MCU**: ATtiny1616（tinyAVR 1-series）
- **通信**: RS485（半二重）
- **設計ツール**: EasyEDA Pro

<!-- TODO: 基板写真を docs/images/ に置いて貼る -->

## ハードウェア仕様

| 項目 | 内容 |
|---|---|
| MCU | ATtiny1616 |
| RS485トランシーバ | TODO |
| 電源電圧 | TODO |
| 基板サイズ | TODO |
| コネクタ | TODO |
| 書込み | UPDI |

### ピンアサイン

| ATtiny1616ピン | 機能 |
|---|---|
| TODO | RS485 TX |
| TODO | RS485 RX |
| TODO | RS485 DE/RE |
| PA0 | UPDI |

## リポジトリ構成

```
hardware/
  schematic/   回路図（PDF）
  pcb/         EasyEDA Proプロジェクト（.eprj2）、PCB図面
  gerber/      製造用Gerberファイル
  bom/         部品表（BOM）、部品配置（CPL）
  3d/          3Dモデル（STEP）
firmware/      サンプルファームウェア
docs/          ドキュメント、写真
```

## EasyEDA Proからエクスポートするファイル

| ファイル | エクスポート先 |
|---|---|
| 回路図PDF | `hardware/schematic/` |
| PCB図面PDF | `hardware/pcb/` |
| プロジェクト（.eprj2） | `hardware/pcb/` |
| Gerber（zip） | `hardware/gerber/` |
| BOM / ピック＆プレース（CPL） | `hardware/bom/` |
| 3Dモデル（STEP） | `hardware/3d/` |

## 使用例

このモジュールは以下のプロジェクトで使っています。

- [KER_TLE_V3_Module](https://github.com/NaohiroIIDA/KER_TLE_V3_Module)：TLE5012B磁気角度センサーモジュール

## 作者

Naohiro IIDA

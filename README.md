# ATtiny1616_RS485_Module

ATtiny1616マイコンとRS485トランシーバを搭載した小型の基板モジュールです。

## 概要

ATtiny1616とRS485トランシーバ（H485EIDQ）を13×22mmの基板に載せたモジュールです。
4ピンのJST SHコネクタで、複数台をRS485バスに数珠つなぎにできます。
空いているGPIOはすべて2.54mmピッチのピンヘッダに出してあります。

- **MCU**: ATtiny1616-MNR（QFN-20、tinyAVR 1-series）
- **通信**: RS485（半二重）
- **設計ツール**: EasyEDA Pro

![ATtiny1616 RS485 Module](docs/images/board.jpg)

*左：組み立て済みの基板。右：UPDIライタにつないで書き込んでいるところ*

## ハードウェア仕様

| 項目 | 内容 |
|---|---|
| MCU | ATtiny1616-MNR |
| RS485トランシーバ | H485EIDQ/TR（DFN-8） |
| 電源電圧 | 5V |
| 終端抵抗 | 120Ω（R6、裏面。標準では未実装） |
| 基板サイズ | 約13.2×21.8mm |
| RS485コネクタ | JST SM04B-SRSS-TB（SH 1.0mm 4ピン）。表面のU6と、裏面のU11（標準では未実装） |
| 書込みコネクタ | JST SM03B-SRSS-TB（SH 1.0mm 3ピン、UPDI）（U9） |
| GPIO | 2.54mmピッチ 8ピンヘッダ×2（H1・H2） |
| 状態LED | PB0（1kΩ経由） |

### 裏面部品の実装（R6・U11）

裏面のR6（120Ω終端抵抗）とU11（2つ目のRS485コネクタ）は標準では未実装です。バス上のどこに置くかで、どちらか一方を実装します。

| 位置 | 実装する部品 |
|---|---|
| バスの末端 | R6（120Ω終端抵抗） |
| バスの途中（次のデバイスへつなぐ） | U11（コネクタ） |

```
[マスター]──U6[モジュール]U11──U6[モジュール]U11──U6[モジュール]R6
              （途中）              （途中）              （末端）
```

### MCUのピン割り当て

| ATtiny1616 | 機能 |
|---|---|
| PB2（TXD） | RS485 DI（送信） |
| PB3（RXD） | RS485 RO（受信） |
| PB4 | RS485 DE / RE#（送信イネーブル。Highで送信） |
| PB0 | LED |
| PA0 | UPDI |

RS485にはUSART0のデフォルトピン（PB2/PB3）を使っています。

### コネクタ

**RS485（U6・U11、2つとも同じピン配置）**

| ピン | 信号 |
|---|---|
| 1 | VCC |
| 2 | A |
| 3 | B |
| 4 | GND |

**UPDI（U9）**

| ピン | 信号 |
|---|---|
| 1 | UPDI |
| 2 | GND |
| 3 | VCC |

**H1**

| ピン | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|---|---|---|---|---|---|---|---|---|
| 信号 | GND | VCC | PA4 | PA5 | PA6 | PA7 | PB5 | PB1 |

**H2**

| ピン | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
|---|---|---|---|---|---|---|---|---|
| 信号 | PA3 | PA2 | PA1 | UPDI | PC3 | PC2 | PC1 | PC0 |

## リポジトリ構成

```
hardware/
  schematic/   回路図（PDF）
  pcb/         EasyEDA Proプロジェクト（.epro2）、PCB図面
  gerber/      製造用Gerberファイル
  bom/         部品表（BOM）、部品配置（CPL）
  3d/          3Dモデル（STEP）
firmware/      サンプルファームウェア
docs/          ドキュメント、写真
```

## 基板データ

| ファイル | 置き場所 |
|---|---|
| 回路図PDF | `hardware/schematic/` |
| PCB図面PDF | `hardware/pcb/` |
| EasyEDA Proプロジェクト（.epro2） | `hardware/pcb/` |
| Gerber（zip） | `hardware/gerber/` |
| BOM（xlsx・csv） | `hardware/bom/` |
| 3Dモデル（STEP） | `hardware/3d/` |

.epro2は、EasyEDA Proの「ファイル → インポート」で開けます。

## 使用例

このモジュールは以下のプロジェクトで使っています。

- [KER_TLE_V3_Module](https://github.com/NaohiroIIDA/KER_TLE_V3_Module)：TLE5012B磁気角度センサーモジュール

## ライセンス

[MIT License](LICENSE)

回路図・基板データ・ファームウェアを含め、このリポジトリのすべてのファイルが対象です。著作権表示を残せば、商用・非商用を問わず自由に使用・改変・再配布できます。

## 作者

Naohiro IIDA

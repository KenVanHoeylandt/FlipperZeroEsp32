# Flipper Zero for ESP32

**WARNING: THIS IS A WIP! NOT A FINISHED PROJECT!**

This project is created from code at:
- [Flipper Zero Firmware](https://github.com/flipperdevices/flipperzero-firmware/)
- [Flpr by EstebanFuentealba](https://github.com/EstebanFuentealba/flpr/)
- [Flippulator from Milk-Cool](https://github.com/Milk-Cool/flippulator/)
- more (see `components/`)

## Notes for developers

- Install esp-idf 5.1 from https://docs.espressif.com/projects/esp-idf/en/v5.1.2/esp32/get-started/index.html
- Ensure you clone the repository with submodules: `git clone --recurse-submodules`
- Run `idf.py build` for building
- Run `idf.py flash monitor` to build, flash and then monitor
- There are tons of `// TODO esp` in the code. Look out for those when debugging issues.

## Hardware 

### ESP32

To run Jetpack, you need an ESP32 dev board (e.g. Wemos D1 Mini, ESP32-WROVER Kit) or ESP32 core board (e.g. ESP32-DevKitC).
The ESP32 must have `4 MB` of SPI flash memory on board.

### Display

You can connect a `128 x 64 pixel` OLED display driven by an `SSD1306` chip.
We currently support only support `i2c` protocol.

Display to ESP32 connections:
- `GND` to `GND`
- `VDD` to `3.3V`
- `SCK` to `GPIO 22`
- `SDA` to `GPIO 21`

## License

[GNU General Public License Version 3](LICENSE.md)

Third party licenses can be found in their respective folders in `components/`.
The original Flipper firmware license is also LGPL V3.
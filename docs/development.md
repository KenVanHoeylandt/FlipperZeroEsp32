# Development

## Checking out this repository

Make sure you clone with submodules:

```bash
git clone --recurse-submodules {URL}
```

## Preparing your environment

Install [ESP-IDF SDK v5.1](https://docs.espressif.com/projects/esp-idf/en/v5.1/esp32/get-started/index.html).

## Building and testing

### Compile the project

```bash
idf.py build
```

### Flash the ROM to the ESP32

```bash
idf.py -p $DEVICE flash
```

Where `$DEVICE` looks something like:
- (macOS) `/dev/tty.SLAB_USBtoUART`
- (Linux) `/dev/ttyUSB0`

### Monitor the application

```bash
idf.py -p $DEVICE monitor
```

### Build, flash and monitor

You can run all the above actions in series with 1 command:

```bash
idf.py -p $DEVICE build flash monitor
```

You can exit the monitor screen by pressing `CTRL` + `]`.

### Stacktrace analysis

```bash
xtensa-esp32-elf-addr2line -pfiaC -e build/FlipperZeroEsp.elf {ADDRESSES}
```

Where `{ADDRESSES}` is the series of hex addresses of the stack trace, after "Backtrace:" in the log.

## Configure the firmware project

**NOTE: `./sdkconfig` is checked and is configured correctly.
The items below are just a reference.**

From the project directory, run `idf.py menuconfig` to start configuring your ESP32.

In the `Serial flasher config` menu:

* `Flash Size` must be set to `4 MB` (make sure your ESP32 has 4MB of ROM!)
* Uncheck `Detect flash size when flashing bootloader`

In the `Partition Table` menu:

* Select `Custom partition CSV file` and pick `partitions.csv`


# JTAG Debugging

The currently recommended means is by using an `FT232H` board like this:
[https://github.com/amirgon/ESP32-JTAG](https://github.com/amirgon/ESP32-JTAG)

You may use other boards if you are experienced in using them.

## FT232H Wiring

| ESP32 | FT232H |
|-------|--------|
|  TCK  |  AD0   |
|  TDI  |  AD1   |
|  TDO  |  AD2   |
|  TMS  |  AD3   |
|  GND  |  GND   |

# Steps

```bash
openocd -f ft232h.cfg --search openocd-esp32/tcl
```

## Troubleshooting

Check your wiring. Did you confuse `AD*` with `AC*`?

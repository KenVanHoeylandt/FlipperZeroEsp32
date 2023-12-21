idf_component_register(
    SRC_DIRS "furi" "furi/core" "furi-hal-esp32/src-esp32"
    INCLUDE_DIRS "furi" "furi-hal" "furi-hal-config" "furi-hal-esp32/src-esp32"
    REQUIRES mlib cmsis_core applications toolbox
)

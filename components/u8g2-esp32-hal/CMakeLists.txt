idf_component_register(
    SRCS "u8g2_esp32_hal.c"
    INCLUDE_DIRS "."
    REQUIRES driver freertos u8g2
)
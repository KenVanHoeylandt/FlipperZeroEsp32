idf_component_register(
    SRC_DIRS "src/"
    INCLUDE_DIRS "."
)

set(ASSETS_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/assets")
spiffs_create_partition_image(assets ${ASSETS_SRC_DIR} FLASH_IN_PROJECT)

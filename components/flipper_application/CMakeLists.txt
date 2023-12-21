idf_component_register(
    SRC_DIRS "flipper_application"
        "flipper_application/api_hashtable"
        "flipper_application/elf"
        "flipper_application/plugins"
    INCLUDE_DIRS "."
    REQUIRES furi applications toolbox
)
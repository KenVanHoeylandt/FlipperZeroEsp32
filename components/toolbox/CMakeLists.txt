idf_component_register(
    SRCS "toolbox/args.c"
        "toolbox/bit_buffer.c"
        "toolbox/buffer_stream.c"
        "toolbox/compress.c"
        "toolbox/float_tools.c"
        "toolbox/hex.c"
        "toolbox/path.c"
        "toolbox/saved_struct.c"
        "toolbox/version.c"
        "toolbox/stream/stream.c"
        "toolbox/stream/string_stream.c"
        "toolbox/stream/file_stream.c"
        "toolbox/stream/buffered_file_stream.c"
    INCLUDE_DIRS "."
    REQUIRES furi heatshrink microtar
)

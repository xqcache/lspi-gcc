file(GLOB_RECURSE PRIVATE_SOURCES
    "*.c" "*.cpp" "*.h" "*.s"
)

target_sources(${TARGET_NAME} PRIVATE ${PRIVATE_SOURCES})
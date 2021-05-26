set(HEADER_FILES
        HelloWorld.h
)

set(SOURCE_FILES
        HelloWorld.cpp
)

link_directories(${EXE_NAME} ${NUTTX_PATH}/libs)

add_executable(${EXE_NAME} ${SOURCE_FILES} main.cpp ${HEADER_FILES})

add_custom_command(
        TARGET ${EXE_NAME}
        POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} ARGS -S -O binary ${CMAKE_BINARY_DIR}/src/${EXE_NAME}.elf ${CMAKE_BINARY_DIR}/${EXE_NAME}.bin
)

set(LIBM_CMD "${TOOLCHAIN_PREFIX}-gcc --print-file-name=libm.a")
execute_process(COMMAND ${LIBM_CMD} OUTPUT_VARIABLE LIBMA)

set(LIBGCC_CMD "${TOOLCHAIN_PREFIX}-gcc --print-libgcc-file-name")
execute_process(COMMAND ${LIBGCC_CMD} OUTPUT_VARIABLE LIBGCC)


target_link_libraries(${EXE_NAME} --start-group)

target_link_libraries(${EXE_NAME} ${NUTTX_PATH}/nuttx/libs/libapps.a)
target_link_libraries(${EXE_NAME} ${NUTTX_PATH}/nuttx/libs/libnuttx.a)

target_link_libraries(${EXE_NAME} ${LIBMA})
target_link_libraries(${EXE_NAME} ${LIBGCC})

target_link_libraries(${EXE_NAME} --end-group)
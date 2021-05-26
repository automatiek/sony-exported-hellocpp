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

set(CFLAGS
	"-DCONFIG_WCHAR_BUILTIN"
	"-DCONFIG_HAVE_DOUBLE"
	"-Dmain=spresense_main"
	"-D_estack=__stack"
	"-c"
	"-pipe"
	"-std=gnu11"
	"-mcpu=cortex-m4"
	"-mthumb"
	"-mfpu=fpv4-sp-d16"
	"-mfloat-abi=hard"
	"-mabi=aapcs"
	"-fno-builtin"
	"-fno-strict-aliasing"
	"-fno-strength-reduce"
	"-fomit-frame-pointer"
	"-ffunction-sections"
	"-fdata-sections"
	"-Wall")

set(LIBM_CMD "${TOOLCHAIN_PREFIX}-gcc")
execute_process(COMMAND ${LIBM_CMD} ${CFLAGS} "--print-file-name=libm.a" OUTPUT_VARIABLE LIBMA OUTPUT_STRIP_TRAILING_WHITESPACE)

set(LIBGCC_CMD "${TOOLCHAIN_PREFIX}-gcc")
execute_process(COMMAND ${LIBGCC_CMD} ${CFLAGS} "--print-libgcc-file-name" OUTPUT_VARIABLE LIBGCC OUTPUT_STRIP_TRAILING_WHITESPACE)


target_link_libraries(${EXE_NAME} --start-group)

target_link_libraries(${EXE_NAME} ${NUTTX_PATH}/nuttx/libs/libapps.a)
target_link_libraries(${EXE_NAME} ${NUTTX_PATH}/nuttx/libs/libnuttx.a)

target_link_libraries(${EXE_NAME} ${LIBMA})
target_link_libraries(${EXE_NAME} ${LIBGCC})

target_link_libraries(${EXE_NAME} --end-group)
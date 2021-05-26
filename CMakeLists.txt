cmake_minimum_required(VERSION 3.2...3.15)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_LIST_DIR}/cmake/spresense.cmake)

project(HelloCpp
        VERSION 1.0
        DESCRIPTION "Hello world C++ Nuttx"
)

# include(cmake/spresense.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_C_STANDARD 99)

set(NUTTX_PATH "${CMAKE_SOURCE_DIR}/spresense-exported-sdk")

set(AC_COMMON_FLAGS "${AC_COMMON_FLAGS} -fno-builtin -Wall -Wshadow -Wundef -fno-strict-aliasing -fno-strength-reduce -fomit-frame-pointer -Os")
set(AC_COMMON_FLAGS "${AC_COMMON_FLAGS} -D_DEBUG -D_LIBCPP_BUILD_STATIC -D_LIBCPP_NO_EXCEPTIONS ")
set(AC_COMMON_FLAGS "${AC_COMMON_FLAGS} -fno-exceptions -fcheck-new -fno-rtti -pedantic ")
set(AC_COMMON_FLAGS "${AC_COMMON_FLAGS} -nostdinc++")

set(AC_DEFINES "${AC_DEFINES} -DCONFIG_WCHAR_BUILTIN")

include_directories(
        src
        ${NUTTX_PATH}/include
        ${NUTTX_PATH}/include/libcxx
        ${NUTTX_PATH}/arch/chip
        ${NUTTX_PATH}/nuttx/include
)

set(EXE_NAME hellocpp)


set(CMAKE_CXX_FLAGS     "${AC_HW_FLAGS} ${AC_DEFINES} ${AC_COMMON_FLAGS} ${AC_CXX_EXTRA_FLAGS}")
if (PARAM_DEBUG)
    set(CMAKE_CXX_FLAGS     "${CMAKE_CXX_FLAGS} -g")
endif()

set(CMAKE_SKIP_RPATH ON)

set(CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_LINKER} ${AC_LINKER_FLAGS} -o ${EXE_NAME}.elf <OBJECTS> <LINK_LIBRARIES>")

set(BUILD_SHARED_LIBS OFF)

# include_directories(/usr/lib/arm-none-eabi/include/c++/9.2.1)
# include_directories(/usr/lib/arm-none-eabi/include/c++/9.2.1/arm-none-eabi)

add_subdirectory(src)

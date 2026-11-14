cmake_minimum_required(VERSION 3.23)

# Select target architecture: PICO (RP2040) or LINUX
set(BUILD_TARGET "LINUX" CACHE STRING "Target architecture: PICO or LINUX")
set_property(CACHE BUILD_TARGET PROPERTY STRINGS "PICO" "LINUX")

if(BUILD_TARGET STREQUAL "PICO")
    set(PICO_BOARD pico_w)
    set(PICO_SDK_PATH "${CMAKE_CURRENT_SOURCE_DIR}/pico-sdk")
    include("${PICO_SDK_PATH}/external/pico_sdk_import.cmake")

    project(monorepo_pico C CXX ASM)
    set(CMAKE_C_STANDARD 11)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    pico_sdk_init()

    add_subdirectory(common)
    add_subdirectory(rfbox)
    add_subdirectory(user)

elseif(BUILD_TARGET STREQUAL "LINUX")
    project(monorepo_linux CXX)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    add_subdirectory(common)
    add_subdirectory(pad)

else()
    message(FATAL_ERROR "Invalid BUILD_TARGET: ${BUILD_TARGET}. Must be PICO or LINUX.")
endif()

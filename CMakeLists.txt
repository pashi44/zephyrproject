cmake_minimum_required(VERSION 3.20.0)

set(BOARD esp32_devkitc_wroom/esp32/procpu)
set(DTC_OVERLAY_FILE ${CMAKE_CURRENT_SOURCE_DIR}/boards/esp32_common.overlay)


list(APPEND ZEPHYR_EXTRA_MODULES ${CMAKE_CURRENT_SOURCE_DIR}/pwmle)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})


project(apps VERSION 0.1.0 LANGUAGES C CXX)

target_sources(app PRIVATE src/Main.c)

# Add PWMLE module
# add_subdirectory(pwmle)

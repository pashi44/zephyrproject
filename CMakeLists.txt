cmake_minimum_required(VERSION 3.20.0)
set(KCONFIG_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/Kconfig)

set(BOARD_ROOT ${CMAKE_CURRENT_LIST_DIR})  # <— discover boards/*

# set(BOARD esp32_devkitc/esp32/procpu)
# set(DTC_OVERLAY_FILE ${CMAKE_CURRENT_SOURCE_DIR}/boards/espressif/esp32/esp32_common.overlay)
set(CMAKE_CXX_STANDARD  17)
set(CMAKE_CXX_STANDARD_REQUIRED  ON)
list(APPEND ZEPHYR_EXTRA_MODULES
# ${CMAKE_CURRENT_SOURCE_DIR}/gpio
${CMAKE_CURRENT_SOURCE_DIR}/interrupt
${CMAKE_CURRENT_SOURCE_DIR}/mytimers

${CMAKE_CURRENT_SOURCE_DIR}/drivers/drivOne
${CMAKE_CURRENT_SOURCE_DIR}/drivers/i2c
${CMAKE_CURRENT_SOURCE_DIR}/drivers/blue


)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})




project(apps VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)



target_sources(app PRIVATE src/main.cpp)

# Add PWMLE module


# add_subdirectory(gpio)

zephyr_library()
zephyr_include_directories(include)


if(CONFIG_LED_CUSTOM)

  zephyr_library_sources(driveOne.c)
endif()

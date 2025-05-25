zephyr_library()


if(CONFIG_DRIVE_ONE)

zephyr_library_sources(driveOne.c)
endif()
zephyr_include_directories(include)


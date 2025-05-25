zephyr_library()

zephyr_include_directories(include)

if(CONFIG_DRIVE_ONE)
zephyr_library_sources_ifdef(CONFIG_DRIVE_ONE driveOne.c)

zephyr_library_sources(driveOne.c)
endif()


zephyr_library()
zephyr_include_directories(include)
if(CONFIG_MANUAL_DRIVER)

  zephyr_library_sources(drivOne.c)
endif()

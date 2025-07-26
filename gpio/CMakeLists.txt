zephyr_library()

# Include directory for headers
zephyr_include_directories(include)

# Add sources conditionally
if(CONFIG_GPIO_ENABLE)
  zephyr_library_sources(led17.c)
endif()

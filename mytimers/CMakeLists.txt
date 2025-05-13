zephyr_library()

# Include directory for headers
zephyr_include_directories(include)

# Add sources conditionally
if(CONFIG_MANUAL_XTAL_TIMER)
  zephyr_library_sources(tim.c)
endif()


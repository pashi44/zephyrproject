zephyr_library()

# Include directory for headers
zephyr_include_directories(include)

# Add sources conditionally
if(CONFIG_PWMLE_ENABLE)
  zephyr_library_sources(./first.c)
endif()

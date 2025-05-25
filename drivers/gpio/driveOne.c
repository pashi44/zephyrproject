

#define DT_DRV_COMPAT custom_driveOne


#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include "driveOne.h"
#include <zephyr/logging/log.h>

// #if defined(CONFIG_DRIVE_ONE)


struct drive_one_config {
    int pin;
};

static  const int drive_one_init(const struct device *dev) {
    const struct drive_one_config *cfg = dev->config;
    printk("DriveOne init with pin: %d\n", cfg->pin);
    // Example: Configure the pin (use GPIO API if needed)
    return 0;
}



// Extract config from DT
#define DRIVE_ONE_INIT(n) \
static const struct drive_one_config drive_one_cfg_##n = { \
    .pin = DT_INST_PROP(n, pin), \
}; \
DEVICE_DT_INST_DEFINE(n, \
    drive_one_init, \
    NULL, \
    NULL, \
    &drive_one_cfg_##n, \
    POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT, \
    NULL);

DT_INST_FOREACH_STATUS_OKAY(DRIVE_ONE_INIT)


// #endif

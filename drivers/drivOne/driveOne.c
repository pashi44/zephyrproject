



#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include "driveOne.h"
#include <zephyr/logging/log.h>

#if defined(CONFIG_DRIVE_ONE)

#define DT_DRV_COMPAT custom_driveOne

struct drive_one_config {
    int pin;
};

 static inline int drive_one_init( const   struct device *dev) {
    const struct drive_one_config *cfg =  dev->config;
    printk("DriveOne init with pin: %d\n", cfg->pin);
    return 0;
}



#define DRIVE_ONE_INIT(inst)                                              \
    static struct drive_one_data drive_one_data_##inst;                   \
    static const struct drive_one_config drive_one_config_##inst = {     \
        .pin = DT_INST_PROP(inst, pin),                                   \
    };                                                                    \
    DEVICE_DT_INST_DEFINE(inst,                                           \
                          drive_one_init,                                 \
                          NULL,                                           \
                          &drive_one_data_##inst,                         \
                          &drive_one_config_##inst,                       \
                          POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEVICE, NULL);
#endif

#include <zephyr/logging/log.h>
#include "driveOne.h"

#define DT_DRV_COMPAT custom_drivone

LOG_MODULE_REGISTER(driveOne);

struct driveone_config {
    const struct device *gpio_dev;
    gpio_pin_t pin;
    gpio_flags_t flags;
};

struct driveone_data {
    /* Add runtime data here if needed */
};

/* Private init function */
static int driveone_init(const struct device *dev)
{
    const struct driveone_config *cfg = dev->config;
    int ret;

    ret = gpio_pin_configure(cfg->gpio_dev, cfg->pin, cfg->flags | GPIO_OUTPUT);
    if (ret != 0) {
        LOG_ERR("Failed to configure GPIO pin %d (err %d)", cfg->pin, ret);
        return ret;
    }
    LOG_INF("driveOne initialized on pin %d", cfg->pin);
    return 0;
}

/* Public API functions */
int inline  driveone_set(const struct device *dev, int value)
{
    const struct driveone_config *cfg = (    const struct driveone_config *)dev->config;
    int ret;

 ret  =  gpio_pin_set(cfg->gpio_dev, cfg->pin, value);
 if(ret ==0 )  return 0;
 else return ret;
}

int driveone_get(const struct device *dev)
{
    const struct driveone_config *cfg = (     const struct driveone_config *)dev->config;
return    gpio_pin_get(cfg->gpio_dev, cfg->pin);
}

/* API struct to expose public functions */
static const struct driveone_api driveone_driver_api = {
    .set = driveone_set,
    .get = driveone_get,
};

/* Device instance init macro */
#define DRIVEONE_INIT(inst) \
    static struct driveone_data driveone_data_##inst; \
    static const struct driveone_config driveone_config_##inst = { \
        .gpio_dev = DEVICE_DT_GET(DT_GPIO_CTLR(DT_DRV_INST(inst), gpios)), \
        .pin = DT_GPIO_PIN(DT_DRV_INST(inst), gpios), \
        .flags = DT_GPIO_FLAGS(DT_DRV_INST(inst), gpios), \
    }; \
    DEVICE_DT_INST_DEFINE(inst, \
                          driveone_init, \
                          NULL, \
                          &driveone_data_##inst, \
                          &driveone_config_##inst, \
   POST_KERNEL, \
                          CONFIG_KERNEL_INIT_PRIORITY_DEVICE, \
                          &driveone_driver_api);

DT_INST_FOREACH_STATUS_OKAY(DRIVEONE_INIT)

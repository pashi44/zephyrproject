#define DT_DRV_COMPAT custom_gpio_i2c


#include "itwoc.h"

LOG_MODULE_REGISTER(gpio_i2c, CONFIG_GPIO_LOG_LEVEL);



static int gpio_i2c_configure(const struct device *dev,
                              gpio_pin_t pin, gpio_flags_t flags) {
    ARG_UNUSED(flags);
    if (pin > 7) {
        return -EINVAL;
    }
    return 0; // Assume all pins are output-only for this example
}

static int gpio_i2c_port_set_bits_raw(const struct device *dev, gpio_port_value_t mask) {
    struct gpio_i2c_data *data = dev->data;
    const struct gpio_i2c_config *cfg = dev->config;

    data->output_state |= mask;
    return i2c_write(cfg->i2c_bus, &data->output_state, 1, cfg->i2c_addr);
}

static int gpio_i2c_port_clear_bits_raw(const struct device *dev, gpio_port_value_t mask) {
    struct gpio_i2c_data *data = dev->data;
    const struct gpio_i2c_config *cfg = dev->config;

    data->output_state &= ~mask;
    return i2c_write(cfg->i2c_bus, &data->output_state, 1, cfg->i2c_addr);
}

static const struct gpio_driver_api gpio_i2c_api = {
    .pin_configure = gpio_i2c_configure,
    .port_set_bits_raw = gpio_i2c_port_set_bits_raw,
    .port_clear_bits_raw = gpio_i2c_port_clear_bits_raw,
};

static int gpio_i2c_init(const struct device *dev) {
    const struct gpio_i2c_config *cfg = dev->config;

    if (!device_is_ready(cfg->i2c_bus)) {
        return -ENODEV;
    }

    return 0;
}

#define GPIO_I2C_INIT(inst)                                              \
    static struct gpio_i2c_data gpio_i2c_data_##inst;                    \
                                                                         \
    static const struct gpio_i2c_config gpio_i2c_cfg_##inst = {         \
        .i2c_bus = DEVICE_DT_GET(DT_INST_BUS(inst)),                     \
        .i2c_addr = DT_INST_REG_ADDR(inst),                              \
        .ngpios = DT_INST_PROP(inst, ngpios),                            \
    };                                                                   \
                                                                         \
    DEVICE_DT_INST_DEFINE(inst,                                          \
                          gpio_i2c_init,                                 \
                          NULL,                                          \
                          &gpio_i2c_data_##inst,                         \
                          &gpio_i2c_cfg_##inst,                          \
                          POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEVICE, \
                          &gpio_i2c_api);

DT_INST_FOREACH_STATUS_OKAY(GPIO_I2C_INIT)

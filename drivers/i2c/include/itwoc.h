#ifndef   __ITWOC_H__
#define   __ITWOC_H__


#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/device.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/util.h>
#include <zephyr/logging/log.h>





struct gpio_i2c_config {
    const struct device *i2c_bus;
    uint16_t i2c_addr;    // 7-bit I2C address
    int ngpios;
    int freq;
};

struct gpio_i2c_data {
    uint8_t output_state;
};

#endif

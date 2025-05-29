#ifndef __DRIVEONE_H_
#define __DRIVEONE_H_

#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#ifdef __cplusplus
extern "C" {
#endif

// public apo  that has collection of function  signatures

struct gpio_api {
	int (*get)(const struct device *dev, uint8_t *state);
	int (*set)(const struct device *dev, uint8_t state);
};

// my custom driver config
struct my_custom_driver_config {

	struct gpio_dt_spec pin;
	uint8_t instance_id;
};

#ifdef __cplusplus
}
#endif

#endif

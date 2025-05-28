#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <zephyr/logging/log.h>
#include "driveOne.h"


LOG_MODULE_REGISTER(drive_one);

#define DT_DRV_COMPAT custom_driveOne

struct drive_one_config {
	const struct gpio_dt_spec gpio;
};

struct drive_one_data {
	bool state;
};

 int drive_one_set(const struct device *dev, bool state)
{
	const struct drive_one_config *cfg = dev->config;
	int ret = gpio_pin_set_dt(&cfg->gpio, state);
	if (ret == 0) {
		LOG_INF("%s set to %d", dev->name, state);
	}
	return ret;
}

static int drive_one_init(const struct device *dev)
{
	const struct drive_one_config *cfg = dev->config;
	int ret = gpio_pin_configure_dt(&cfg->gpio, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		LOG_ERR("GPIO config failed (%d)", ret);
		return ret;
	}
	return 0;
}

#define DRIVE_ONE_INIT(inst)                                             \
	static struct drive_one_data drive_one_data_##inst;             \
	static const struct drive_one_config drive_one_config_##inst = { \
		.gpio = GPIO_DT_SPEC_INST_GET(inst, gpios),                \
	};                                                              \
	DEVICE_DT_INST_DEFINE(inst,                                     \
			      drive_one_init,                              \
			      NULL,                                       \
			      &drive_one_data_##inst,                       \
			      &drive_one_config_##inst,                     \
			      POST_KERNEL,                                 \
			      CONFIG_KERNEL_INIT_PRIORITY_DEFAULT,         \
			      NULL);

DT_INST_FOREACH_STATUS_OKAY(DRIVE_ONE_INIT)

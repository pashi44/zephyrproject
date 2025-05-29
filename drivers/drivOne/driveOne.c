#include "driveOne.h"
#include <zephyr/kernel.h>
#include <errno.h>
#include <zephyr/logging/log.h>

#define DT_DRV_COMPAT custom_driveOne

LOG_MODULE_REGISTER(driveOne);

/* Device config and data instances generated from devicetree */

#define DRIVEONE_NODE DT_NODELABEL(mynode)

static int my_custom_gpio_init(const struct device *dev);
static int get_custom_gpio_state(const struct device *dev, uint8_t *state);

static int my_custom_gpio_init(const struct device *dev)
{
	const struct my_custom_driver_config *device =
		(const struct my_custom_driver_config *)dev->config;
	const struct gpio_dt_spec *pin = &device->pin;

	LOG_DBG("Instantiating instance%u \n\r", device->instance_id);

	if (!gpio_is_ready_dt(pin)) {
		LOG_ERR("cucstom _gpio_device is not ready \nr\n");
		return -ENODEV;
	}
	int ret;
	ret = gpio_pin_configure_dt(pin, GPIO_ACTIVE_LOW);
	if (ret < 0) {
		LOG_ERR("cucstom _gpio_driver is not ready \nr\n");
		return -ENODEV;
	}
	return 0;
}

static int set_custom_gpio_state(const struct device *dev, uint8_t state)
{
	const struct my_custom_driver_config *device =
		(const struct my_custom_driver_config *)dev->config;
	const struct gpio_dt_spec *pin = &device->pin;

	int ret = gpio_pin_set_dt(pin, state);
	if (ret < 0) {
		LOG_ERR("couldn't set pin state\n\r");
		return ret;
	}

	return 0;
}
// public function
static int get_custom_gpio_state(const struct device *dev, uint8_t *state)
{
	int ret;
	const struct my_custom_driver_config *device =
		(const struct my_custom_driver_config *)dev->config;

	const struct gpio_dt_spec *pin = &device->pin;

	ret = gpio_pin_get_dt(pin);
	// / get the state

	if (ret < 0) {

		LOG_ERR("could nt get  the state of the pin \n\r ");
		return ret;

	} else {
		*state = ret;
	}

	return 0;
}

// device tree handling

// public facing api  that  defined in our header file exposes to  all  the drivers

static const struct gpio_api gpio_api_funcs = {

	.get = get_custom_gpio_state,

	.set = set_custom_gpio_state,

};
#define GPIO_CUSTOM_DRIVER_INIT(inst)                                                              \
                                                                                                   \
	static const struct my_custom_driver_config custom_gpio_##inst = {                         \
		.pin = GPIO_DT_SPEC_GET(DT_PHANDLE(DT_INST(inst, custom_driveOne), gpios), gpios), \
		.instance_id = inst,                                                               \
	};                                                                                         \
                                                                                                   \
	DEVICE_DT_INST_DEFINE(inst, my_custom_gpio_init, NULL, NULL, &custom_gpio_##inst,          \
			      POST_KERNEL, CONFIG_GPIO_INT_PRIORITY, &gpio_api_funcs);

DT_INST_FOREACH_STATUS_OKAY(GPIO_CUSTOM_DRIVER_INIT);

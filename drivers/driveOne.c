#define DT_DRV_COMPAT   espressif_esp32_gpio
// DT_DRV_COMPAT is a macro used in Zephyr's device drivers
// to link the driver source file to a specific device type defined in the Device Tree.

#include <errno.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/logging/log.h>
#include "driveOne.h"

#if defined(CONFIG_LED_CUSTOM)

LOG_MODULE_REGISTER(gpio_esp32, CONFIG_GPIO_LOG_LEVEL);

// Private function
static int button_init(const struct device *dev)
{
	int ret;
	const struct button_cfg *cfg = (const struct button_cfg *)dev->config;
	const struct gpio_dt_spec *button = &cfg->button;

	LOG_DBG("button_init: %u\r\n", cfg->id);

	if (!gpio_is_ready_dt(button)) {
		LOG_ERR("button %u: device not ready\n", cfg->id);
		return -ENODEV;
	}

	ret = gpio_pin_configure_dt(button, GPIO_INPUT | GPIO_PULL_UP);
	if (ret < 0) {
		LOG_ERR("button %u: failed to configure pin %d\n", cfg->id, button->pin);
		return -ENODEV;
	}

	return 0;
}

static int button_get(const struct device *dev, uint8_t *state)
{
	int ret;
	struct button_cfg *cfg = (struct button_cfg *)dev->config;
	struct gpio_dt_spec *button = &cfg->button;

	ret = gpio_pin_get_dt(button);
	if (ret < 0) {
		LOG_ERR("button %u: failed to get pin %d\n", cfg->id, button->pin);
		LOG_ERR("button %d\n", ret);
		return ret;
	} else {
		*state = ret;
	}

	return 0;
}

// Public facing API
static const struct button_driver_api button_api_funcs_instance = {
	.get = button_get,
};

// Macro basics with device tree instances
#define BUTTON_DEFINE(instance)                                                                          \
	\
    static struct button_cfg button_cfg_##instance = {                                                   \
		.button = GPIO_DT_SPEC_GET(DT_PATH(DT_INST(id, gpio_leds)), gpios),              \
		.id = insatnces,                                                                          \
	};                                                                                         \
	DEVICE_DT_INST_DEFINE(instance,
		 button_init,
		  NULL, NULL, &button_cfg_##istance, POST_KERNEL,          \
			      CONFIG_KERNEL_INIT_PRIORITY_DEVICE, &button_api_funcs_instance);

DT_INST_FOREACH_STATUS_OKAY(BUTTON_DEFINE)

#endif // CONFIG_MANUAL_DRIVER

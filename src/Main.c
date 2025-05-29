// #include   "led17.h"
#include "gpintrr.h"
#include "driveOne.h"

#include <zephyr/kernel.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/dac.h>
#include <errno.h>

#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/sys/printk.h>

K_KERNEL_STACK_DEFINE(gpio_stack_area, 1024);

static const struct device *driveone = DEVICE_DT_GET(driveone0);
static const struct device *drivetwo = DEVICE_DT_GET(driveone1);

int main(int argc, char **argv)
{

	int ret;
	uint8_t state_1;
	uint8_t state_2;
	if (!(device_is_ready(driveone) && device_is_ready(drivetwo))) {

		printk("devices are not ready\r\n");
		return 0;
	}

	const struct gpio_api *gpio_ap = (const struct gpio_api *)driveone->api;

	while (1) {
		ret = gpio_ap->get(&driveone, &state_1);
		if (ret < 0) {
			printk(" error %d driveone", ret);
			continue;
		}
		ret = gpio_ap->get(&drivetwo, &state_2);
		if (ret < 0) {
			printk(" error %d driveone", ret);
			continue;
		}

		k_msleep(1000);
	}

	return 0;
	// int ret;
	// uint8_t state;
	// bool toggle = false;

	// if (!device_is_ready(driveone)) {
	// 	printk("driveone not ready\n");
	// 	return 0;
	// }

	// const struct gpio_api *gpio_ap = (const struct gpio_api *)driveone->api;

	// while (1) {
	// 	toggle = !toggle;
	// 	ret = gpio_ap->set(driveone, toggle);
	// 	if (ret < 0) {
	// 		printk("Error setting LED state: %d\n", ret);
	// 	}
	// 	k_msleep(500);
	// }
	// return 0;
}

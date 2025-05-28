	// #include   "led17.h"
	#include   "gpintrr.h"
	#include "driveOne.h"

	#include <zephyr/kernel.h>
	#include <zephyr/drivers/adc.h>
	#include <zephyr/drivers/gpio.h>
	#include <zephyr/drivers/dac.h>
	#include<errno.h>

	#include <zephyr/device.h>
	#include <zephyr/devicetree.h>
#include <zephyr/sys/printk.h>

K_KERNEL_STACK_DEFINE(gpio_stack_area, 1024);


 int main(int argc, char** argv)
{






	const struct device *drive0 = DEVICE_DT_INST_GET(0);
	const struct device *drive1 = DEVICE_DT_INST_GET(1);

	if (!device_is_ready(drive0) || !device_is_ready(drive1)) {
		return  0;
	}

	while (1) {
		drive_one_set(drive0, true);
		drive_one_set(drive1, false);
		k_sleep(K_MSEC(500));
		drive_one_set(drive0, false);
		drive_one_set(drive1, true);
		k_sleep(K_MSEC(500));
	}

return 0;
}

// #include   "led17.h"
#include "driveOne.h"

#include <zephyr/kernel.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/dac.h>
#include <errno.h>

#include <zephyr/logging/log.h>


#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/sys/printk.h>


K_KERNEL_STACK_DEFINE(gpio_stack_area, 1024);


static const struct device *driveone0 =  DEVICE_DT_GET(DT_NODELABEL(driveone0));

int main(int argc, char **argv)
{


	if (!device_is_ready(driveone0  )) {
		printk("DriveOne device not ready\n");
		return;
	    }


	    int k ;
	/* Blink loop */
	while (1) {
k=	    driveone_set(driveone0, 1);

	    k_sleep(K_MSEC(500));
	    k=driveone_set(driveone0, 0);

	    k_sleep(K_MSEC(500));
	}

  return 0;


}

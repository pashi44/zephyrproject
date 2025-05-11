extern "C" {
#include   "led17.h"
#include   "gpintrr.h"
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/dac.h>

#include <zephyr/devicetree.h>
#include <zephyr/sys/printk.h>


}
K_KERNEL_STACK_DEFINE(gpio_stack_area, 1024);


 static struct k_thread gpio_thread_handler;
extern "C" int main(int argc, char** argv)
{

k_tid_t gpio_thread_id=	k_thread_create(&gpio_thread_handler, gpio_stack_area,
			K_KERNEL_STACK_SIZEOF(gpio_stack_area),
			gpio_thread_entry, NULL, NULL, NULL,
			7, 0, K_NO_WAIT);








	while (1) {
		k_msleep(2000); // Delay for 1 second

	}


			return 0;
		}



extern "C" {
#include   "led17.h"
#include   "gpintrr.h"

// #include "driveOne.h"
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/dac.h>

#include <zephyr/devicetree.h>
#include <zephyr/sys/printk.h>


}
K_KERNEL_STACK_DEFINE(gpio_stack_area, 1024);



 extern "C" int main(int argc, char** argv)
 {

	 static struct k_thread gpio_thread_handler;


	 struct k_thread gpio_thread_handler_one;
	 k_tid_t gpio_thread_id = k_thread_create(
		 &gpio_thread_handler, gpio_stack_area, K_KERNEL_STACK_SIZEOF(gpio_stack_area),
		 gpio_thread_entry, NULL, NULL, NULL, 7, 0, K_NO_WAIT);

	 while (1) {


		printk("adasdasdasd  %p \n\r", &gpio_thread_handler);

		 printk("adasdasdasd  %p \n\r", &gpio_thread_handler_one);

		 k_msleep(2000);

	[&gpio_thread_handler]{}();

		}




const struct  device* spidev =  DEVICE_DT_GET(DT_NODELABEL(spi2));

return 0;


		}



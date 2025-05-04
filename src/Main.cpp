extern "C" {
#include   "led17.h"

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/dac.h>

#include <zephyr/devicetree.h>
#include <zephyr/sys/printk.h>


}


using namespace std;
extern "C" int main(int argc, char** argv)
{
	int err;

err  =  led17_init();
	if(err !=0 ){ printk("led d driver failed from  main");  return 0;}






	while (1) {
		gpio_pin_toggle_dt(&led17);
		k_msleep(200); // Delay for 1 second
		gpio_pin_set_dt(&led17, 0); // Turn off LED




		k_msleep(500); // Delay for 1 second

	}


			return 0;
		}



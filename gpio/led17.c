#include "led17.h"

// #if defined(CONFIG_GPIO_ENABLE) && defined(CONFIG_GPIOPIN_ENABLE)

#define LED_NODE DT_NODELABEL(led17)
 const struct gpio_dt_spec led17 = GPIO_DT_SPEC_GET(LED_NODE, gpios);

int led17_init(){
	if (!device_is_ready(led17.port)) {
		printk("gpio driveri is  not ready \n\r");

	}
	return gpio_pin_configure_dt(&led17, GPIO_OUTPUT_ACTIVE);
}





#include "led17.h"

#define LED_NODE   DT_PATH(leds, led_17)

 const struct gpio_dt_spec led17 = GPIO_DT_SPEC_GET(LED_NODE, gpios);

int led17_init(){
	if (!device_is_ready(led17.port)) {
		printk("gpio driveri is  not ready \n\r");

	}
	return gpio_pin_configure_dt(&led17, GPIO_OUTPUT_LOW);
}


// struct k_sem gpio_sem;



 void  gpio_thread_entry(void *p1, void *p2, void *p3)
 {
	 led17_init();

uint8_t  counter=0;
	 while (1) {

		 if(counter == 0xff){

// k_sem_take(&gpio_sem, K_MSEC(200));

		 gpio_pin_toggle_dt(&led17);
		 k_msleep(200);
gpio_pin_set_dt(&led17, 0);
k_yield();

// k_sem_give(&gpio_sem);

}


		 ++counter;
		 k_msleep(200);

		 printk("led17 is on  with %d\n\r", counter);
	 }
 }



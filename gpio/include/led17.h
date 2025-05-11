#ifndef LED17_H
#define LED17_H

#include <zephyr/kernel.h>
#include <zephyr/devicetree.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(CONFIG_GPIO_ENABLE) && defined(CONFIG_GPIOPIN_PARAMETER)

extern const  struct gpio_dt_spec led17;
extern int led17_init();
extern  void gpio_thread_entry(void *p1, void *p2, void *p3);


#endif

#ifdef __cplusplus
}
#endif

#endif


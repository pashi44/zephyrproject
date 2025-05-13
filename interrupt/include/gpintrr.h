#ifndef __GPINTRR_H__
#define __GPINTRR_H__
#include <stdint.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>

#define MY_DEV_IRQ 24

#define MY_DEV_PRIO 7

#if defined(CONFIG_MANUAL_GPIO_INTRR )






// #define  MY_ISR_ARG  DEVICE_GET(mydevice)
extern  const struct device *mydevice;
extern  void isr_handler(void *arg);

extern  void isr_init(void);
#endif //kconfig GPIO inter


#endif

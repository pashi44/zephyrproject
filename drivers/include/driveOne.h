	#ifndef __DRIVEONE_H__
	#define __DRIVEONE_H__
	#include <stdint.h>
	#include <zephyr/kernel.h>
	#include <zephyr/device.h>
	#include <zephyr/devicetree_generated.h>

	#include <zephyr/drivers/gpio.h>



	//pulblic geberic  driver interface or a subsystem
struct button_driver_api

{

	int (*get)(const struct device *dev, uint8_t *state);
};


struct button_cfg{
struct gpio_dt_spec button;
 uint8_t id	;
};



// extern "C" int button_init(const struct device *dev);
// extern  "C" int button_get(const struct device *dev, uint8_t *state);
#endif



#ifndef __DACONE__
#define __DACONE__

#include <zephyr/kernel.h>
#include <zephyr/devicetree.h>
#include <zephyr/device.h>
#include <zephyr/drivers/dac.h>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(CONFIG_DAC_ENABLE)

#define DAC_NODE DT_NODELABEL(dac)

extern const  struct device* dac_driver;
extern   const struct dac_channel_cfg dac_config;
int init_dac(void);

#endif

#ifdef __cplusplus
}
#endif

#endif // __DACONE__

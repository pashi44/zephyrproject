#ifndef ZEPHYR_DRIVEONE_H_
#define ZEPHYR_DRIVEONE_H_

#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <errno.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef int (*driveone_api_set_t)(const struct device *dev, int value);
typedef int (*driveone_api_get_t)(const struct device *dev);

struct driveone_api {
    driveone_api_set_t set;
    driveone_api_get_t get;
};

/* Public API */
int driveone_set(const struct device *dev, int value);
int driveone_get(const struct device *dev);

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_DRIVEONE_H_ */

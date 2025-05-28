#pragma once

#include <zephyr/device.h>

#ifdef __cplusplus
extern "C" {
#endif

int drive_one_set(const struct device *dev, bool state);

#ifdef __cplusplus
}
#endif

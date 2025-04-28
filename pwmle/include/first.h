#ifndef FIRST_H
#define FIRST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <zephyr/kernel.h>

#ifdef CONFIG_PWMLE_ENABLE
void first(void);
#endif /* CONFIG_PWMLE_ENABLE */

#ifdef __cplusplus
}
#endif

#endif /* FIRST_H */

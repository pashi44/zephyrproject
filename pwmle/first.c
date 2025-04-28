#include "first.h"
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

void first(void)
{
    printk("Hello from first.c\n");
}

// #include   "led17.h"

#include <zephyr/kernel.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/dac.h>
#include <zephyr/drivers/i2c.h>
#include <errno.h>
#include  "itwoc.h"

#include <zephyr/logging/log.h>




#define I2C_DEV_NODE  DT_BUS(DT_ALIAS(my_i2c_dev))
#define I2C_DEV       DEVICE_DT_GET(I2C_DEV_NODE)
#define I2C_ADDR      DT_REG_ADDR(DT_ALIAS(my_i2c_dev))

#define I2C_DEV_LABEL   DT_LABEL(DT_NODELABEL(i2c0))
#define SLAVE_ADDR      0x55

const struct device *i2c_dev;

int main(void)
{
    char  tx_buf[2] = {  'A',   'B'};
      char  rx_buf[2];
i2c_dev=  I2C_DEV;


    if (!device_is_ready(i2c_dev)) {
        printk("Failed to get I2C device binding!\n");
        return;
    }

    else printk("I2C device initialized\n");

// int     ret = i2c_read(i2c_dev, rx_buf, sizeof(rx_buf), SLAVE_ADDR);
//     if (ret != 0) {
        // printk("I2C read failed: %d\n", ret);
//     } else {
        // printk("I2C read success: 0x%02X 0x%02X\n", rx_buf[0], rx_buf[1]);
//     }

int ret=0;
while(1){



    ret = i2c_write(i2c_dev, tx_buf, sizeof(tx_buf), SLAVE_ADDR);

    if (ret != 0) {

        printk("I2C write failed: %d\n\r", ret);

    } else {

        printk("I2C write success\n\r");

    }




	k_msleep(100
	);
}



return 0;
}

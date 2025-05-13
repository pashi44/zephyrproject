#include "gpintrr.h"

#define ADC_NODE DT_NODELABEL(adc0)



// const struct  device*  mydevice = DEVICE_DT_GET(ADC_NODE);

void isr_handler(void *arg)
{


printk("from the IRQ handler \n\r");
}

void isr_init(void)
{


IRQ_CONNECT(MY_DEV_IRQ, MY_DEV_PRIO,isr_handler,


DEVICE_DT_GET(ADC_NODE), 0


); // an assembly directiv ve that maspo

// IRQ_DIRECT_CONNECT() //for real time fast harware Interrupt  ahdling without adding context switching
irq_enable(MY_DEV_IRQ); // enable the interrupt

// irq_connect_dynamic(MY_DEV_IRQ, MY_DEV_PRIO, my_isr, MY_ISR_ARG, MY_IRQ_FLAGS);
}

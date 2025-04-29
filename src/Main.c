#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/devicetree.h>
#include <zephyr/sys/printk.h>

#define ADC_NODE DT_NODELABEL(adc0)
static const struct device *const adc_dev = DEVICE_DT_GET(ADC_NODE);
static const struct gpio_dt_spec led17 = GPIO_DT_SPEC_GET(DT_NODELABEL(led17), gpios);

static const struct adc_dt_spec adc_ch0 = {
	.dev = adc_dev,
	.channel_id = DT_PROP(DT_CHILD(ADC_NODE, channel_0), reg),
	.channel_cfg_dt_node_exists = true,
	.channel_cfg =
		{
			.gain = DT_STRING_TOKEN(DT_NODELABEL(adc0_ch0), zephyr_gain),
			.reference =
				DT_STRING_TOKEN(DT_CHILD(ADC_NODE, channel_0), zephyr_reference),
			.acquisition_time =
				DT_PROP(DT_CHILD(ADC_NODE, channel_0), zephyr_acquisition_time),
		},
	.vref_mv = DT_PROP(DT_CHILD(ADC_NODE, channel_0), zephyr_vref_mv),
	.resolution = DT_PROP(DT_CHILD(ADC_NODE, channel_0), zephyr_resolution),
	.oversampling = 0,
};

int main()
{
	int err;
	static int16_t adc_sample_buffer;

	if (!device_is_ready(adc_ch0.dev) || !device_is_ready(led17.port)) {
		printk("ADC or LED device not ready!\n");
		return -1;
	}

	err = adc_channel_setup(adc_ch0.dev, &adc_ch0.channel_cfg);
	if (err) {
		printk("Failed to setup ADC channel 0 (err %d)\n", err);
		return err;
	}

	err = gpio_pin_configure_dt(&led17, GPIO_OUTPUT_ACTIVE);
	if (err < 0) {
		printk("Failed to configure LED (err %d)\n", err);
		return err;
	}

	struct adc_sequence sequence = {
		.channels = BIT(adc_ch0.channel_id),
		.buffer = &adc_sample_buffer,
		.buffer_size = sizeof(adc_sample_buffer),
		.resolution = adc_ch0.resolution,
	};

	while (1) {
		err = adc_read(adc_ch0.dev, &sequence);
		if (err < 0) {
			printk("ADC read failed (err %d)\n", err);
		} else if (adc_sample_buffer <= 1000) {
			gpio_pin_set_dt(&led17, (0 << 1));
			printk("ADC value: %d \n\r", adc_sample_buffer);
		} else {
			gpio_pin_toggle_dt(&led17);
			printk("ADC value: %d (LED TOGGLED)\n\r", adc_sample_buffer);
		}

		k_msleep(200);
	}

	return 0;
}

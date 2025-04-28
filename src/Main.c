#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/devicetree.h>
#include <zephyr/sys/printk.h>


#define ADC_NODE DT_NODELABEL(adc0)
static const struct device  *const adc_dev = DEVICE_DT_GET(ADC_NODE);

static const struct adc_dt_spec adc_ch0 = {
	.dev = adc_dev,
	.channel_id = DT_PROP(DT_CHILD(ADC_NODE,channel_0 ), reg),
	.channel_cfg_dt_node_exists = true,
	.channel_cfg =
		{
			.gain = DT_STRING_TOKEN(DT_NODELABEL(adc0_ch0), zephyr_gain),
			.reference = DT_STRING_TOKEN(DT_CHILD(ADC_NODE, channel_0), zephyr_reference),
			.acquisition_time =
				DT_PROP(DT_CHILD(ADC_NODE, channel_0), zephyr_acquisition_time),

		},
	.vref_mv = DT_PROP(DT_CHILD(ADC_NODE, channel_0

				    ),
			   zephyr_vref_mv),
	.resolution = DT_PROP(DT_CHILD(ADC_NODE, channel_0), zephyr_resolution),
	.oversampling = 0,
};

	// static const struct adc_dt_spec adc_chan1 =
		// ADC_DT_SPEC_GET_BY_NAME(ADC_NODE,  adc0_ch1); // Channel 1

	int main()
	{

		int err;
		static int16_t adc_sample_buffer;

		if (!device_is_ready(adc_ch0.dev)) {

			printk("adc_device* os not readn\n\r");
			return -1;
		}

		err = adc_channel_setup(adc_ch0.dev, &adc_ch0.channel_cfg);
		if (err) {
			printk("Failed to setup channel 0 (err %d)\n", err);
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
			if (err) {
				printk("ADC read failed (err %d)\n", err);
			} else {
				printk("Channel 0 raw value: %d\n", adc_sample_buffer);
			}

			k_sleep(K_MSEC(1000));
		}

		printk("ADC channels setup done!\n");

		return 0;
	}

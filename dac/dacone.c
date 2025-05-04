#include "dacone.h"

#ifdef __cplusplsu
extern "C"{
#endif



#if defined(CONFIG_DAC_ENABLE)
const struct device* dac_driver =  DEVICE_DT_GET(DAC_NODE);
const struct dac_channel_cfg dac_config = {
	//
	.channel_id = 0,
	// .resolution = 8,

};

int init_dac(){



	return dac_channel_setup(dac_driver, 0);


}

#endif


#ifdef __cplusplus
}
#endif




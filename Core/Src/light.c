#include "adc.h"
#include "light.h"



uint32_t Light_Get(void)
{
	uint32_t val;
	
	HAL_ADC_Start(&hadc1);     // 启动 ADC1
	
	HAL_ADC_PollForConversion(&hadc1, 5);   // 等待 ADC1 转换完成，等待超时时间为 5ms，超迿 5ms 不在等待直接继续向下运行
	
	val = HAL_ADC_GetValue(&hadc1);        // 读取 ADC1 的转换结果数据
	
	HAL_ADC_Stop(&hadc1);      // 停止 ADC1

	return val;
}

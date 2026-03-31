#include "i2c.h"
#include "eeprom.h"



// 


// 向 EEPROM 字节写
uint8_t EEPROM_Write_Byte(uint8_t addr, uint8_t data)
{
	
	// 方式 1
//	uint8_t send_data[2] = {addr, data};

//	if(HAL_OK == HAL_I2C_Master_Transmit(&hi2c1, CAT24C02_ADDR, send_data, sizeof(send_data), 1000))
//		return 0;  // 成功返回 0
	
	
	// 方式 2
	if(HAL_OK == HAL_I2C_Mem_Write(&hi2c1, CAT24C02_ADDR, addr, I2C_MEMADD_SIZE_8BIT, &data, 1, 1000))
		return 0;  // 成功返回 0
	
	return 1; // 失败返回 1
}



// 从 EEPROM 字节读
uint8_t EEPROM_Read_Byte(uint8_t addr , uint8_t *data)
{
	
	// 方式1
//	if(HAL_OK != HAL_I2C_Master_Transmit(&hi2c1, CAT24C02_ADDR, &addr, sizeof(addr), 1000))
//		return 1;  // 失败返回 1
//	
//	if(HAL_OK != HAL_I2C_Master_Receive(&hi2c1, CAT24C02_ADDR, data, 1, 1000))
//		return 2;  // 失败返回 2
//	
	
	
	// 方式2
	if(HAL_OK != HAL_I2C_Mem_Read(&hi2c1, CAT24C02_ADDR, addr, I2C_MEMADD_SIZE_8BIT, data, 1, 1000))
		return 1;  // 失败返回 1
	
	return 0;  // 成功返回 0
}

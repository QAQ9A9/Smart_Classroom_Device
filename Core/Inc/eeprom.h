#ifndef _EEPROM_H_
#define _EEPROM_H_


#include <stdint.h>


#define CAT24C02_ADDR 0xA0



uint8_t EEPROM_Write_Byte(uint8_t adddr, uint8_t data);
uint8_t EEPROM_Read_Byte(uint8_t addr , uint8_t *data);



#endif

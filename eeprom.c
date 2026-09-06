#include<lpc21xx.h> 
#include"header.h" 
void eeprom_store_password(char *password) 
{
	u8 i; 
	for(i=0; password[i]!='\0'; i++) 
	{
		i2c_write(0xA0,i,password[i]);
		delay_ms(10);
	} 
	i2c_write(0xA0,i,'\0'); 
	delay_ms(10);
} 
void eeprom_store_datetime(u8 sec,u8 min,u8 hour,u8 am_pm, u8 date,u8 month,u8 year)
{ 
	i2c_write(0xA0,0x10,sec);
	delay_ms(10);
	i2c_write(0xA0,0x11,min);
	delay_ms(10); 
	i2c_write(0xA0,0x12,hour);
	delay_ms(10);
	i2c_write(0xA0,0x13,am_pm); 
	delay_ms(10); 
	i2c_write(0xA0,0x14,date);
	delay_ms(10); 
	i2c_write(0xA0,0x15,month);
	delay_ms(10);
	i2c_write(0xA0,0x16,year);
	delay_ms(10);
}

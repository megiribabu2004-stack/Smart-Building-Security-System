#include<lpc21xx.h>
#include<string.h>
#include"header.h"
char k[20];
char h[]="4900C8FDDCA0";
char r[13]={0};
char *s="1234";
int t[6];
int i,f1=0,f2=0,f=0;
CAN tx;
u8 am_pm;
int main()
{
	can_ini();
	uart0_init(9600);
	while(1)
	{
		uart0_tx_string("waiting\n\r");
		delay_ms(100);
		if((1))
		{
			delay_ms(100);

			if(((IOPIN0|PIR)&1))
			{

				uart0_tx_string("motion detected\r\n");
				uart0_tx_string("enter rfid\r\n");
				//uart0_tx_string("wait\r\n");
				uart0_rx_string(r,12);
				uart0_tx_string("printing\r\n");
				uart0_tx_string(r);
				uart0_tx_string("\r\n");

				if(strcmp(h,r)==0)
				{
					f1=1;
					uart0_tx_string("successfully done");
					rtc_write();
					read(t);
					PWMMR2=1500;
					PWMLER=(1<<2);
					delay_sec(2);
					PWMMR2=1000;
					PWMLER=(1<<2);
					uart0_tx_string("door opened\r\n");
					if(t[2]<12)
						am_pm='A';
					else
						am_pm='P';

					eeprom_store_password(h);
					eeprom_store_datetime(t[0],t[1],t[2],am_pm,t[3],t[4],t[5]);
					uart0_tx_string("Data stored\r\n");
				}

				else
				{
					f2=1;
					uart0_tx_string("RFID card is not matched\r\n");
					uart0_tx_string("enter the key\r\n");
					for(i=0;i<4;i++)
					{
						k[i]=key();
						uart0_tx(k[i]);
					}


					uart0_tx('\n');

					if((strcmp(k,s))==0)
					{
						uart0_tx_string("password is correct\r\n");
						rtc_write();
						read(t);
						uart0_tx_string("DOOr opened\r\n");

						PWMMR2=1500;
						PWMLER=(1<<2);
						delay_sec(2);
						PWMMR2=1000;
						PWMLER=(1<<2);

						if(t[2]<12)
							am_pm='A';
						else
							am_pm='P';

						eeprom_store_password(s);
						//eeprom_store_datetime(t[0],t[1],t[2],am_pm,`t[3],t[4],t[5]);
						eeprom_store_datetime(t[0],t[1],t[2],am_pm,t[3],t[4],t[5]);
						uart0_tx_string("Data stored\r\n");
					}

					else
						uart0_tx_string("not correct\n");
				}


				tx.id=0x100;
				tx.rtr=0;
				tx.dlc=4;
				if(f1)
				{
					f1=0;
					//tx.id=0x100;
					//tx.rtr=0;
					//tx.dlc=4;
					tx.byteA=123456789 ;
					can_tx(tx);
				}
				else if(f2)
				{
					f2=0;
					tx.byteA=1234;
					can_tx(tx);
				}
				else
					uart0_tx_string("MOTION not detected\r\n");
			}
		}
	}
}

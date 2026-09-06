#include<lpc21xx.h> 
#include"header.h" 
extern u8 h,m,s,D,M,Y; 
void rtc_write() 
{ 
	i2c_init();
	uart0_init(9600);
	// uart0_tx_string("ext rtc testing\r\n"); 
	/*Set 11:59:55 PM in rtc*/
	i2c_write(0xD0,0x2,0x23);//set hrs
	i2c_write(0xD0,0x1,0x59);//set mins
	i2c_write(0xD0,0x0,0x55);//set secs
	i2c_write(0xD0,0x4,0x11);//set secs
	i2c_write(0xD0,0x5,0x08);//set secs
	i2c_write(0xD0,0x6,0x26);//set secs
} 
/*read & display rtc time on lcd*/ 
void read(int a[]) 
{ 
	a[0]=i2c_read(0xD1,0x2);//read hrs
	a[1]=i2c_read(0xD1,0x1);//read mins
	a[2]=i2c_read(0xD1,0x0);//read secs
	a[3]=i2c_read(0xD1,0x4);//read hrs
	a[4]=i2c_read(0xD1,0x5);//read mins 
	a[5]=i2c_read(0xD1,0x6); 
	//am_pm=(h>>5)&1; 
	uart0_tx((a[0]/16)+48); 
	uart0_tx((a[0]%16)+48);
	uart0_tx(':');
	uart0_tx((a[1]/16)+48);
	uart0_tx((a[1]%16)+48);
	uart0_tx(':');
	uart0_tx((a[2]/16)+48);
	uart0_tx((a[2]%16)+48); 
	uart0_tx('\r');
	uart0_tx((a[3]/16)+48); 
	uart0_tx((a[3]%16)+48);
	uart0_tx(':');
	uart0_tx((a[4]/16)+48);
	uart0_tx((a[4]%16)+48);
	uart0_tx(':');
	uart0_tx((a[5]/16)+48); 
	uart0_tx((a[5]%16)+48);
	uart0_tx('\r');
	//if(flag==1){ 
	//	flag=0;
	//do t & d settings
	}
}

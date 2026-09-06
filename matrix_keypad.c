#include<lpc21xx.h>
#include<string.h>
#include"header.h"
unsigned char key(void)
{
	PINSEL1|=0X00000000;
	// PINSEL1|=0X00000000;
	IODIR1|=(r1|r2|r3|r4);
	IODIR1&=~(c1|c2|c3|c4);
	IODIR0&=~PIR;
	PINSEL0|=(2<<14);
	PWMTCR=(1<<1);
	PWMPR=14;
	PWMMR0=20000;

	PWMMCR=(1<<1);
	PWMPCR=(1<<10);
	PWMLER=(1<<0);
	PWMTCR=(1<<0)|(1<<3);
	while(1)
	{
		IOCLR1=(r1|r2|r3|r4);
		IOSET1=(r2|r3|r4);
		if(!(IOPIN1&c1)){delay_ms(200);return '1';}
		if(!(IOPIN1&c2)){delay_ms(200);return '2';}
		if(!(IOPIN1&c3)){delay_ms(200);return '3';}
		if(!(IOPIN1&c4)){delay_ms(200);return 'A';}
		IOCLR1=(r1|r2|r3|r4);
		IOSET1=(r1|r3|r4);
		if(!(IOPIN1&c1)){delay_ms(200);return '4';}
		if(!(IOPIN1&c2)){delay_ms(200);return '5';}
		if(!(IOPIN1&c3)){delay_ms(200);return '6';}
		if(!(IOPIN1&c4)){delay_ms(200);return 'B';}
		IOCLR1=(r1|r2|r3|r4);
		IOSET1=(r1|r2|r4);
		if(!(IOPIN1&c1)){delay_ms(200);return '7';}
		if(!(IOPIN1&c2)){delay_ms(200);return '8';}
		if(!(IOPIN1&c3)){delay_ms(200);return '9';}
		if(!(IOPIN1&c4)){delay_ms(200);return 'C';}
		IOCLR1=(r1|r2|r3|r4);
		IOSET1=(r1|r2|r3);
		if(!(IOPIN1&c1)){delay_ms(200);return '*';}
		if(!(IOPIN1&c2)){delay_ms(200);return '0';}
		if(!(IOPIN1&c3)){delay_ms(200);return '#';}
		if(!(IOPIN1&c4)){delay_ms(200);return 'D';}
	}
} 

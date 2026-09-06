#include<lpc21xx.h>
#include"header.h"
void uart0_init(unsigned int baud)
{
	int pclk,result=0;
	if(VPBDIV==0)
		pclk=15000000;
	else if(VPBDIV==1)
		pclk=6000000;
	else if(VPBDIV==2)
		pclk=3000000;
	result=pclk/(16*baud);
	PINSEL0|=0x05 ;
	U0LCR=0x83;
	U0DLL=(result&0xff);
	U0DLM=(result>>8)&0xff;
	U0LCR=0x03;
}

#define THRE ((U0LSR>>5)&1)
void uart0_tx(unsigned char data)
{
	U0THR=data;
	while(THRE==0);
}

#define RDR (U0LSR&1)
unsigned char uart0_rx()
{
	while(RDR==0);
	return U0RBR;
}

void uart0_tx_string(char *p)
{
	while(*p!=0)
	{
		uart0_tx(*p);
		++p;
	}
}

void uart0_binary(int num)
{
	int pos,temp;
	for(pos=7;pos>=0;pos--)
	{
		temp=num>>pos;
		uart0_tx(temp+48);
	}
}

void uart0_int(int num )
{
	if(num>10)
		uart0_int(num/10);

	uart0_tx((num%10)+48);
}


void uart0_hex(char num)
{
	char n;
	uart0_tx_string("0x");
	n=((num&0xf0)>>4);
	if(n>9)
		uart0_tx('A'+(n-10));
	else
		uart0_tx(n+48);
	n=(num&0x0f);
	if(n>9)
		uart0_tx('A'+(n-10));
	else
		uart0_tx(n+48);

}

void uart0_rx_string(char*p,int max)
{
	int i;
	for(i=0;i<max;i++)
	{
		while(RDR==0);
		p[i]=U0RBR;
		uart0_tx(p[i]);
		if(p[i]=='\r' || p[i]=='\n' )
		{      p[i]='\0';
			break;
		}
	}
}

void uart0_float(float f)
{
	int num;
	num=f;
	uart0_int(num);
	num=(f-num)*1000000;
	uart0_int(num);
}

void uart0_time_div(char t)
{
	uart0_tx((t/16)+48);
	uart0_tx((t%16)+48);
}

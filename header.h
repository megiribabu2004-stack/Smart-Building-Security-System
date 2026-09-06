#define u8 unsigned int
#define u32 unsigned int
extern void delay_ms(unsigned int ms);
extern void delay_sec(unsigned int sec);
extern unsigned char key(void);
extern void uart0_init(unsigned int baud);
extern void uart0_tx(unsigned char data);    
extern void uart0_tx_string(char *p);
extern void uart0_rx_string(char*p,int max);
#define c1 (1<<16)
#define c2 (1<<17)
#define c3 (1<<18)
#define c4 (1<<19)
#define r1 (1<<20)
#define r2 (1<<21)
#define r3 (1<<22)
#define r4 (1<<23)
#define PIR (1<<6)
typedef struct can
{
	unsigned int id;
	unsigned int byteA;
	unsigned int byteB;
	int rtr;
	int dlc;
	int ff;
}CAN;
extern void can_tx(CAN);
extern void can_ini(void);
extern void can_rx(CAN *);
extern void lcd_data(unsigned char data);
extern void lcd_cmd(unsigned char cmd);
extern void lcd_init(void) ;
extern void lcd_int(int num);
extern int bcd_to_int(char rtc);
extern void time_div1(char t) ;
extern unsigned int min(void);
extern void dmy(void);
extern void lcd_string(char *p);
extern void i2c_init(void);
extern void i2c_write(u8 sa,u8 mr, u8 data);
extern unsigned int i2c_read(u8 sa,u8 mr);
extern void config_ext(void);
extern void uart0_time_div(char s);
extern unsigned int min(void);
extern void dmy(void);
extern void rtc_write(void);
extern void read(int a[]);
//typedef unsigned char u8;
//typedef unsigned int u32;
void i2c_init(void);
void i2c_write(u8 sa, u8 mr, u8 data);
u8 i2c_read(u8 sa, u8 mr);
void eeprom_store_password(char *password);
void eeprom_read_password(char *password);
void eeprom_store_datetime(u8 sec,u8 min,u8 hour,u8 am_pm,u8 date,u8 month,u8 year);
void eeprom_read_datetime(u8 *sec,u8 *min,u8 *hour,u8 *am_pm,u8 *date,u8 *month,u8 *year);

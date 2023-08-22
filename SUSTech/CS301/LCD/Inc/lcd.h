#ifndef __LCD_H
#define __LCD_H
#include "sys.h"
#include "stdlib.h"
//////////////////////////////////////////////////////////////////////////////////
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK MiniSTM32F103开发板
//2.4寸/2.8寸/3.5寸/4.3寸/7寸 TFT液晶驱动
//支持驱动IC型号包括:ILI9341/ILI9325/RM68042/RM68021/ILI9320/ILI9328/LGDP4531/LGDP4535/
//                  SPFD5408/1505/B505/C505/NT35310/NT35510/SSD1963等
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2010/7/4
//版本：V3.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved
//********************************************************************************
//V1.2修改说明
//支持了SPFD5408的驱动,另外把液晶ID直接打印成HEX格式.方便查看LCD驱动IC.
//V1.3
//加入了快速IO的支持
//修改了背光控制的极性（适用于V1.8及以后的开发板版本）
//对于1.8版本之前(不包括1.8)的液晶模块,请修改LCD_Init函数的LCD_LED=1;为LCD_LED=1;
//V1.4
//修改了LCD_ShowChar函数，使用画点功能画字符。
//加入了横竖屏显示的支持
//V1.5 20110730
//1,修改了B505液晶读颜色有误的bug.
//2,修改了快速IO及横竖屏的设置方式.
//V1.6 20111116
//1,加入对LGDP4535液晶的驱动支持
//V1.7 20120713
//1,增加LCD_RD_DATA函数
//2,增加对ILI9341的支持
//3,增加ILI9325的独立驱动代码
//4,增加LCD_Scan_Dir函数(慎重使用)
//6,另外修改了部分原来的函数,以适应9341的操作
//V1.8 20120905
//1,加入LCD重要参数设置结构体lcddev
//2,加入LCD_Display_Dir函数,支持在线横竖屏切换
//V1.9 20120911
//1,新增RM68042驱动（ID:6804），但是6804不支持横屏显示！！原因：改变扫描方式，
//导致6804坐标设置失效，试过很多方法都不行，暂时无解。
//V2.0 20120924
//在不硬件复位的情况下,ILI9341的ID读取会被误读成9300,修改LCD_Init,将无法识别
//的情况（读到ID为9300/非法ID）,强制指定驱动IC为ILI9341，执行9341的初始化。
//V2.1 20120930
//修正ILI9325读颜色的bug。
//V2.2 20121007
//修正LCD_Scan_Dir的bug。
//V2.3 20130120
//新增6804支持横屏显示
//V2.4 20131120
//1,新增NT35310（ID:5310）驱动器的支持
//2,新增LCD_Set_Window函数,用于设置窗口,对快速填充,比较有用,但是该函数在横屏时,不支持6804.
//V2.5 20140211
//1,新增NT35510（ID:5510）驱动器的支持
//V2.6 20140504
//1,新增ASCII 24*24字体的支持(更多字体用户可以自行添加)
//2,修改部分函数参数,以支持MDK -O2优化
//3,针对9341/35310/35510,写时间设置为最快,尽可能的提高速度
//4,去掉了SSD1289的支持,因为1289实在是太慢了,读周期要1us...简直奇葩.不适合F4使用
//5,修正68042及C505等IC的读颜色函数的bug.
//V2.7 20140710
//1,修正LCD_Color_Fill函数的一个bug.
//2,修正LCD_Scan_Dir函数的一个bug.
//V2.8 20140721
//1,解决MDK使用-O2优化时LCD_ReadPoint函数读点失效的问题.
//2,修正LCD_Scan_Dir横屏时设置的扫描方式显示不全的bug.
//V2.9 20141130
//1,新增对SSD1963 LCD的支持.
//2,新增LCD_SSD_BackLightSet函数
//3,取消ILI93XX的Rxx寄存器定义
//V3.0 20150423
//修改SSD1963 LCD屏的驱动参数.
//////////////////////////////////////////////////////////////////////////////////


//LCD重要参数集
typedef struct
{
	uint16_t width;			//LCD 宽度
	uint16_t height;			//LCD 高度
	uint16_t id;				//LCD ID
	uint8_t  dir;			//横屏还是竖屏控制：0，竖屏；1，横屏。
	uint16_t	wramcmd;		//开始写gram指令
	uint16_t setxcmd;		//设置x坐标指令
	uint16_t  setycmd;		//设置y坐标指令
}_lcd_dev;

//LCD参数
extern _lcd_dev lcddev;	//管理LCD重要参数
//LCD的画笔颜色和背景色
extern uint16_t  POINT_COLOR;//默认红色
extern uint16_t  BACK_COLOR; //背景颜色.默认为白色

////////////////////////////////////////////////////////////////////
//-----------------LCD端口定义----------------
#define	LCD_LED PCout(10) 				//LCD背光    	PC10

#define	LCD_CS_SET  GPIOC->BSRR=1<<9    //片选端口  		PC9
#define	LCD_RS_SET	GPIOC->BSRR=1<<8    //数据/命令 		PC8
#define	LCD_WR_SET	GPIOC->BSRR=1<<7    //写数据			PC7
#define	LCD_RD_SET	GPIOC->BSRR=1<<6    //读数据			PC6

#define	LCD_CS_CLR  GPIOC->BRR=1<<9     //片选端口  		PC9
#define	LCD_RS_CLR	GPIOC->BRR=1<<8     //数据/命令		PC8
#define	LCD_WR_CLR	GPIOC->BRR=1<<7     //写数据			PC7
#define	LCD_RD_CLR	GPIOC->BRR=1<<6     //读数据			PC6


//PB0~15,作为数据线
#define DATAOUT(x) GPIOB->ODR=x; //数据输出
#define DATAIN     GPIOB->IDR;   //数据输入


//////////////////////////////////////////////////////////////////////
//扫描方向定义
#define L2R_U2D  0 //从左到右,从上到下
#define L2R_D2U  1 //从左到右,从下到上
#define R2L_U2D  2 //从右到左,从上到下
#define R2L_D2U  3 //从右到左,从下到上

#define U2D_L2R  4 //从上到下,从左到右
#define U2D_R2L  5 //从上到下,从右到左
#define D2U_L2R  6 //从下到上,从左到右
#define D2U_R2L  7 //从下到上,从右到左

#define DFT_SCAN_DIR  L2R_U2D  //默认的扫描方向

//扫描方向定义
#define L2R_U2D  0 //从左到右,从上到下
#define L2R_D2U  1 //从左到右,从下到上
#define R2L_U2D  2 //从右到左,从上到下
#define R2L_D2U  3 //从右到左,从下到上

#define U2D_L2R  4 //从上到下,从左到右
#define U2D_R2L  5 //从上到下,从右到左
#define D2U_L2R  6 //从下到上,从左到右
#define D2U_R2L  7 //从下到上,从右到左

#define DFT_SCAN_DIR  L2R_U2D  //默认的扫描方向

//画笔颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000
#define BLUE         	 0x001F
#define BRED             0XF81F
#define GRED 			 0XFFE0
#define GBLUE			 0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			 0XBC40 //棕色
#define BRRED 			 0XFC07 //棕红色
#define GRAY  			 0X8430 //灰色
//GUI颜色

#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色
#define GRAYBLUE       	 0X5458 //灰蓝色
//以上三色为PANEL的颜色

#define LIGHTGREEN     	 0X841F //浅绿色
#define LGRAY 			 0XC618 //浅灰色(PANNEL),窗体背景色

#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)

void LCD_Init(void);													   	//初始化
void LCD_DisplayOn(void);													//开显示
void LCD_DisplayOff(void);													//关显示
void LCD_Clear(uint16_t Color);	 												//清屏
void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos);										//设置光标
void LCD_DrawPoint(uint16_t x,uint16_t y);											//画点
void LCD_Fast_DrawPoint(uint16_t x,uint16_t y,uint16_t color);								//快速画点
uint16_t  LCD_ReadPoint(uint16_t x,uint16_t y); 											//读点
void LCD_Draw_Circle(uint16_t x0,uint16_t y0,uint8_t r);					    			//画圆
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);							//画线
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2);		   				//画矩形
void LCD_Fill(uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,uint16_t color);		   				//填充单色
void LCD_Color_Fill(uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,uint16_t *color);				//填充指定颜色
void LCD_ShowChar(uint16_t x,uint16_t y,uint8_t num,uint8_t size,uint8_t mode);						//显示一个字符
void LCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size);  						//显示一个数字
void LCD_ShowxNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size,uint8_t mode);				//显示 数字
void LCD_ShowString(uint16_t x,uint16_t y,uint16_t width,uint16_t height,uint8_t size,uint8_t *p);		//显示一个字符串,12/16字体

void LCD_WriteReg(uint16_t LCD_Reg, uint16_t LCD_RegValue);
uint16_t LCD_ReadReg(uint16_t LCD_Reg);
void LCD_WriteRAM_Prepare(void);
void LCD_WriteRAM(uint16_t RGB_Code);
void LCD_Scan_Dir(uint8_t dir);									//设置屏扫描方向
void LCD_Display_Dir(uint8_t dir);								//设置屏幕显示方向
void LCD_Set_Window(uint16_t sx,uint16_t sy,uint16_t width,uint16_t height);	//设置窗口

//写数据函数
#define LCD_WR_DATA(data){\
LCD_RS_SET;\
LCD_CS_CLR;\
DATAOUT(data);\
LCD_WR_CLR;\
LCD_WR_SET;\
LCD_CS_SET;\
}

//LCD分辨率设置
#define SSD_HOR_RESOLUTION		800		//LCD水平分辨率
#define SSD_VER_RESOLUTION		480		//LCD垂直分辨率
//LCD驱动参数设置
#define SSD_HOR_PULSE_WIDTH		1		//水平脉宽
#define SSD_HOR_BACK_PORCH		46		//水平前廊
#define SSD_HOR_FRONT_PORCH		210		//水平后廊

#define SSD_VER_PULSE_WIDTH		1		//垂直脉宽
#define SSD_VER_BACK_PORCH		23		//垂直前廊
#define SSD_VER_FRONT_PORCH		22		//垂直前廊
//如下几个参数，自动计算
#define SSD_HT	(SSD_HOR_RESOLUTION+SSD_HOR_BACK_PORCH+SSD_HOR_FRONT_PORCH)
#define SSD_HPS	(SSD_HOR_BACK_PORCH)
#define SSD_VT 	(SSD_VER_RESOLUTION+SSD_VER_BACK_PORCH+SSD_VER_FRONT_PORCH)
#define SSD_VPS (SSD_VER_BACK_PORCH)

#endif














#include <reg52.h>
#include <intrins.h>

sbit s2 = P3^0;
sbit flag = P3^7; 	//为外部中断输入下降沿

void delay(unsigned int z)	//延时函数
{

	unsigned int x,y;
	for(x = z; x > 0; x--)	
		for(y = 114; y > 0 ; y--);
}


void int1intl()
{
	EA = 1;		//开启总中断
	EX0 = 1;		//外部中断0允许
	IT0 = 1;	//外部中断0下降沿中断

}

void int1() interrupt 0
{
	P1 = ~P1;	   //led灯状态改变
}

void main()
{
	int1intl();	  //中断初始化
	if(s2 == 0)
	{   
	    delay(5);
		if(s2 == 0)
		{
			flag = 1;
			flag = 0;	//产生下降沿
			delay(5);
			while( s2 == 0 );	 //松手检测
		}
	}
}
/* 做一个呼吸灯，利用开发板上的发光二极管和中断的功能实现*/
#include <reg52.h>
#include <intrins.h>

sbit LED1 = P1^0;

int PWM_t;
int PWM_max = 455;
int PWM_light ; //数字越小灯越亮

void delay(unsigned int z)	//延时函数
{

	unsigned int x,y;
	for(x = z; x > 0; x--)	
		for(y = 114; y > 0 ; y--);
}


void timer0init()	 //初始化timer0
{
   EA = 1;	//开启总中断
   ET0 = 1; //允许T0中断
   TR0 = 1; //允许TR0开始计数
   TMOD = 0x02; //设置工作模式为8位自动重装

   TH0 = 0xDC;
   TL0 = 0xDC; //设置每38us溢出一次

}

void timer0Int() interrupt 1
{
	TH0 = 230;
	TL0 = 230; 
	PWM_t++;
	if(PWM_t == PWM_max)
	{
		PWM_t = 0; //从0开始进入周期
		LED1 = 1;  //灭LED灯
	}
	if(PWM_light == PWM_t)
		LED1 = 0; //当进入进入亮灯环节，则让LED灯点亮
}	

void main()
{
	timer0init(); //定时器0初始化
	while(1)
	{
		int i,j;
		PWM_light = 400;
		for(i = 0 ; i<PWM_max; i++)
		{
			PWM_light--;
			delay(1);
			if(PWM_light == 0)
			{
				for(j = 0; j<PWM_max ; j--)
				{
					delay(1);
					PWM_light++;
					if(PWM_light == PWM_max)
						break;
				}
			}
		}

	}
}

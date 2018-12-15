/* ��һ�������ƣ����ÿ������ϵķ�������ܺ��жϵĹ���ʵ��*/
#include <reg52.h>
#include <intrins.h>

sbit LED1 = P1^0;

int PWM_t;
int PWM_max = 455;
int PWM_light ; //����ԽС��Խ��

void delay(unsigned int z)	//��ʱ����
{

	unsigned int x,y;
	for(x = z; x > 0; x--)	
		for(y = 114; y > 0 ; y--);
}


void timer0init()	 //��ʼ��timer0
{
   EA = 1;	//�������ж�
   ET0 = 1; //����T0�ж�
   TR0 = 1; //����TR0��ʼ����
   TMOD = 0x02; //���ù���ģʽΪ8λ�Զ���װ

   TH0 = 0xDC;
   TL0 = 0xDC; //����ÿ38us���һ��

}

void timer0Int() interrupt 1
{
	TH0 = 230;
	TL0 = 230; 
	PWM_t++;
	if(PWM_t == PWM_max)
	{
		PWM_t = 0; //��0��ʼ��������
		LED1 = 1;  //��LED��
	}
	if(PWM_light == PWM_t)
		LED1 = 0; //������������ƻ��ڣ�����LED�Ƶ���
}	

void main()
{
	timer0init(); //��ʱ��0��ʼ��
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

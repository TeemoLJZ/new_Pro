#include <reg52.h>
#include <intrins.h>

sbit s2 = P3^0;
sbit flag = P3^7; 	//Ϊ�ⲿ�ж������½���

void delay(unsigned int z)	//��ʱ����
{

	unsigned int x,y;
	for(x = z; x > 0; x--)	
		for(y = 114; y > 0 ; y--);
}


void int1intl()
{
	EA = 1;		//�������ж�
	EX0 = 1;		//�ⲿ�ж�0����
	IT0 = 1;	//�ⲿ�ж�0�½����ж�

}

void int1() interrupt 0
{
	P1 = ~P1;	   //led��״̬�ı�
}

void main()
{
	int1intl();	  //�жϳ�ʼ��
	if(s2 == 0)
	{   
	    delay(5);
		if(s2 == 0)
		{
			flag = 1;
			flag = 0;	//�����½���
			delay(5);
			while( s2 == 0 );	 //���ּ��
		}
	}
}
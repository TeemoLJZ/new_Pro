#include <reg52.h>
#include <intrins.h>

unsigned char temp;

void delay(void)   //Îó²î -0.000000000023us
{
    unsigned char a,b;
    for(b=221;b>0;b--)
        for(a=207;a>0;a--);
}

void main(){
	temp = 0xfe;
	while(1){
		 P1 = temp;
		 delay();
		 temp = _crol_(temp,1);
	 }

}
#include <8052.h>


__sbit __at (0x90) I1 ;
__sbit __at (0x91) I2 ;
__sbit __at (0x92) I3 ;
__sbit __at (0x93) I4 ;

void Timer0_Init();
void Timer0_Routine() __interrupt(1);
void CarForward ();
void CarBackward ();
void CarStop ();
void CarLeftForward ();
void CarRightForward ();
void CarRightStop ();
void CarLeftStop ();

void Delay(unsigned int time)		//@11.0592MHz
{
	unsigned int a = 1;
	while (a <= time)
	{
		unsigned char i, j;

		i = 2;
		j = 199;
		do {
			while (--j);
		} while (--i);
		a++;
	}
}



int main()
{
    unsigned int Line = 0;
	Timer0_Init();
    while (1)
    {
        if (P1_7 == 0)
        {
			P1_6 = 0;
			break;
		}
	}
    CarForward();
	while (1)
	{
		if (I1==1 && I2==1 && I3==1 && I4==1)
		{
			P1_6 = 1;
			Delay(70);
			break;
		}

	}
    while (1)
    {
		if (I1==0 && I2==0 && I3==0 && I4==0)
        {
            CarForward();
        }

        if ((I1==0 && I2==1 && I3==0 && I4==0) || (I1==1 && I2==0 && I3==0 && I4==0))  //小车偏左，小车向右移动
        {
			CarRightStop();
		}

        if ((I1==0 && I2==0 && I3==1 && I4==0) || (I1==0 && I2==0 && I3==0 && I4==1))  //小车偏右，小车向左移动
        {
	        CarLeftStop();
		}

        if ((I1==0 && I2==0 && I3==1 && I4==1) || (I1==0 && I2==1 && I3==1 && I4==1)) //直角左拐
        {
            CarForward();
			Delay(180);
			CarLeftStop();
			while (1)
			{
				if (I3 == 1)
				{
					Delay(10);
					break;
				}
			}
			Line++;
        }

        if ((I1==1 && I2==1 && I3==0 && I4==0) || (I1==1 && I2==1 && I3==1 && I4==0)) //直角右拐
        {
	        CarForward();
	        Delay(180);
			CarRightStop();
	        while (1)
	        {
		        if (I2 == 1)
		        {
					Delay(10);
			        break;
				}
			}
			Line++;
        }

		if (Line == 4)
		{
			break;
		}
    }

	while (1)
	{
		if (I1==0 && I2==0 && I3==0 && I4==0)
		{
			CarForward();
		}

		if ((I1==0 && I2==1 && I3==0 && I4==0) || (I1==1 && I2==0 && I3==0 && I4==0))  //小车偏左，小车向右移动
		{
			CarRightStop();
		}

		if ((I1==0 && I2==0 && I3==1 && I4==0) || (I1==0 && I2==0 && I3==0 && I4==1))  //小车偏右，小车向左移动
		{
			CarLeftStop();
		}

		if ((I1==1 && I2==1 && I3==1 && I4==1) || (I1==0 && I2==0 && I3==1 && I4==1) || (I1==0 && I2==1 && I3==1 && I4==1) || (I1==1 && I2==1 && I3==0 && I4==0) || (I1==1 && I2==1 && I3==1 && I4==0))
		{
			unsigned int a = 0;
			CarForward();
			Delay(180);
			CarRightStop();
			Delay(800);
			while (1)
	        {
		        if (I2 == 1)
		        {
					Delay(10);
			        break;
				}
			}
			break;
		}
	}

	while (1)
	{
		if (I1 == 0 && I2 == 0 && I3 == 0 && I4 == 0)
		{
			CarBackward();
		}

		if ((I1==1 && I2==1 && I3==1 && I4==1) || (I1==0 && I2==0 && I3==1 && I4==1) || (I1==0 && I2==1 && I3==1 && I4==1) || (I1==1 && I2==1 && I3==0 && I4==0) || (I1==1 && I2==1 && I3==1 && I4==0))
		{
			P1_6 = 0;
			break;
		}
	}
	CarStop();
	Delay(10);
	P1_6 = 1;
	while (1);
}

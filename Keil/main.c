#include <STC/STC89C5xRC.H>

sbit I1 = P1^0;
sbit I2 = P1^1;
sbit I3 = P1^2;
sbit I4 = P1^3;

void Timer0_Init();
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
        if (P17 == 0)
        {
			P16 = 0;
			break;
		}
	}
    CarForward();
	while (1)
	{
		if (I1==1 && I2==1 && I3==1 && I4==1)
		{
			P16 = 1;
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

        if ((I1==0 && I2==1 && I3==0 && I4==0) || (I1==1 && I2==0 && I3==0 && I4==0))
        {
			CarRightStop();
		}

        if ((I1==0 && I2==0 && I3==1 && I4==0) || (I1==0 && I2==0 && I3==0 && I4==1))
        {
	        CarLeftStop();
		}

        if ((I1==0 && I2==0 && I3==1 && I4==1) || (I1==0 && I2==1 && I3==1 && I4==1))
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

        if ((I1==1 && I2==1 && I3==0 && I4==0) || (I1==1 && I2==1 && I3==1 && I4==0))
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

		if ((I1==0 && I2==1 && I3==0 && I4==0) || (I1==1 && I2==0 && I3==0 && I4==0))
		{
			CarRightStop();
		}

		if ((I1==0 && I2==0 && I3==1 && I4==0) || (I1==0 && I2==0 && I3==0 && I4==1))
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
			P16 = 0;
			break;
		}
	}
	CarStop();
	Delay(10);
	P16 = 1;
	while (1);
}

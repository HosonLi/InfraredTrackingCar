#include <STC/STC89C5xRC.H>


sbit PWM_Right = P2^7;
sbit PWM_Left = P2^6;

void RightForward();
void RightBackward();
void RightStop();
void LeftForward();
void LeftBackward();
void LeftStop();


unsigned char SpeedLeft, SpeedRight;


void Timer0_Init()
{
	TMOD &= 0xF0;
	TMOD |= 0x01;
	TL0 = 0xA4;
	TH0 = 0xFF;
	TF0 = 0;
	TR0 = 1;
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}

void Timer0_Routine() interrupt 1
{
	static unsigned int Counter;

	TL0 = 0xA4;
	TH0 = 0xFF;

	Counter++;
	if (Counter >= 100)
	{
		Counter = 0;
	}
	if (Counter < SpeedRight)
	{
		PWM_Right = 1;
	}
	else
	{
		PWM_Right = 0;
	}
	if (Counter < SpeedLeft)
	{
		PWM_Left = 1;
	}
	else
	{
		PWM_Left = 0;
	}
}


void CarForward ()
{
	SpeedRight = 100;
	SpeedLeft = 100;
	RightForward();
    LeftForward();
}

void CarBackward ()
{
	SpeedRight = 100;
	SpeedLeft = 100;
	RightBackward();
    LeftBackward();
}

void CarStop ()
{
	SpeedLeft = 0;
	SpeedRight = 0;
	RightStop();
    LeftStop();
}

void CarLeftForward ()
{
	SpeedRight = 100;
	SpeedLeft = 0;
    RightForward();
	LeftStop();
}

void CarRightForward ()
{
	SpeedLeft = 100;
	SpeedRight = 0;
	LeftForward();
	RightStop();
}

void CarRightStop ()
{
	SpeedRight = 100;
	SpeedLeft = 100;
	LeftForward();
	RightBackward();
}

void CarLeftStop ()
{
	SpeedRight = 100;
	SpeedLeft = 100;
	LeftBackward();
	RightForward();
}
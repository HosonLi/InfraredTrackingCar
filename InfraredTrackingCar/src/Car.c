#include <8052.h>


__sbit __at (0xA7) PWM_Right;
__sbit __at (0xA6) PWM_Left;

void RightForward();
void RightBackward();
void RightStop();
void LeftForward();
void LeftBackward();
void LeftStop();


unsigned char SpeedLeft, SpeedRight;	//计数值和比较值，用于输出PWM


void Timer0_Init()		//100微秒@11.0592MHz
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0xA4;		//设置定时初始值
	TH0 = 0xFF;		//设置定时初始值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}

void Timer0_Routine() __interrupt(1)  //中断函数
{
	static unsigned int Counter;

	TL0 = 0xA4;		//设置定时初始值
	TH0 = 0xFF;		//设置定时初始值

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


void CarForward ()        //小车向前直行
{
	SpeedRight = 100;
	SpeedLeft = 100;
	RightForward();
    LeftForward();
}

void CarBackward ()      //小车向后直行
{
	SpeedRight = 100;
	SpeedLeft = 100;
	RightBackward();
    LeftBackward();
}

void CarStop ()      //小车停止
{
	SpeedLeft = 0;
	SpeedRight = 0;
	RightStop();
    LeftStop();
}

void CarLeftForward ()    //小车向前左拐
{
	SpeedRight = 100;
	SpeedLeft = 0;
    RightForward();
	LeftStop();
}

void CarRightForward ()   //小车向前右拐
{
	SpeedLeft = 100;
	SpeedRight = 0;
	LeftForward();
	RightStop();
}

void CarRightStop () //小车原地右拐
{
	SpeedRight = 100;
	SpeedLeft = 100;
	LeftForward();
	RightBackward();
}

void CarLeftStop () //小车原地左拐
{
	SpeedRight = 100;
	SpeedLeft = 100;
	LeftBackward();
	RightForward();
}
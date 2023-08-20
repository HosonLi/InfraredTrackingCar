#include <8052.h>


__sbit __at (0xA7) PWM_Right;
__sbit __at (0xA6) PWM_Left;

void RightForward();
void RightBackward();
void RightStop();
void LeftForward();
void LeftBackward();
void LeftStop();


unsigned char SpeedLeft, SpeedRight;	//����ֵ�ͱȽ�ֵ���������PWM


void Timer0_Init()		//100΢��@11.0592MHz
{
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0xA4;		//���ö�ʱ��ʼֵ
	TH0 = 0xFF;		//���ö�ʱ��ʼֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	ET0 = 1;
	EA = 1;
	PT0 = 0;
}

void Timer0_Routine() __interrupt(1)  //�жϺ���
{
	static unsigned int Counter;

	TL0 = 0xA4;		//���ö�ʱ��ʼֵ
	TH0 = 0xFF;		//���ö�ʱ��ʼֵ

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


void CarForward ()        //С����ǰֱ��
{
	SpeedRight = 100;
	SpeedLeft = 100;
	RightForward();
    LeftForward();
}

void CarBackward ()      //С�����ֱ��
{
	SpeedRight = 100;
	SpeedLeft = 100;
	RightBackward();
    LeftBackward();
}

void CarStop ()      //С��ֹͣ
{
	SpeedLeft = 0;
	SpeedRight = 0;
	RightStop();
    LeftStop();
}

void CarLeftForward ()    //С����ǰ���
{
	SpeedRight = 100;
	SpeedLeft = 0;
    RightForward();
	LeftStop();
}

void CarRightForward ()   //С����ǰ�ҹ�
{
	SpeedLeft = 100;
	SpeedRight = 0;
	LeftForward();
	RightStop();
}

void CarRightStop () //С��ԭ���ҹ�
{
	SpeedRight = 100;
	SpeedLeft = 100;
	LeftForward();
	RightBackward();
}

void CarLeftStop () //С��ԭ�����
{
	SpeedRight = 100;
	SpeedLeft = 100;
	LeftBackward();
	RightForward();
}
#include <8052.h>


__sbit __at (0x80) Right1;
__sbit __at (0x81) Right2;
__sbit __at (0x82) Left1;
__sbit __at (0x83) Left2;


void RightForward()
{
    Right1 = 0;
    Right2 = 1;
}

void RightBackward()
{
    Right1 = 1;
    Right2 = 0;
}

void RightStop()
{
    Right1 = 1;
    Right2 = 1;
}

void LeftForward()
{
    Left1 = 0;
    Left2 = 1;
}

void LeftBackward()
{
    Left1 = 1;
    Left2 = 0;
}

void LeftStop()
{
    Left1 = 1;
    Left2 = 1;
}
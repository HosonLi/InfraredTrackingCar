#include <STC/STC89C5xRC.H>


sbit Right1 = P0^0;
sbit Right2 = P0^1;
sbit Left1 = P0^2;
sbit Left2 = P0^3;


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
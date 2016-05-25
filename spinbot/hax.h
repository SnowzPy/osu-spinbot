#pragma once
#define SPEEDRAND 30 // random shapes 
#define RADIUS 350 // spin radius. higher number, bigger spins
#define SPEED 0.100 // 0.10 and above = 477 // 0.100 will outspin almost everything
#define TITLE "Steam"

enum Direction
{
	Clockwise,
	CounterClockwise
};

Direction dir = Clockwise; // modify if you want

void Start(void *cancer);

int MoveMouseTo(long x, long y)
{
	INPUT InputData;
	InputData.type = INPUT_MOUSE;
	InputData.mi.dwExtraInfo = NULL;
	InputData.mi.dwFlags = MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE;
	InputData.mi.time = NULL;
	InputData.mi.dx = x * (65535 / GetSystemMetrics(SM_CXSCREEN));
	InputData.mi.dy = y * (65535 / GetSystemMetrics(SM_CYSCREEN));

	return SendInput(1, &InputData, sizeof(InputData));
}

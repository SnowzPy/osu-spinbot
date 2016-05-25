#pragma once
#define SPEEDRAND 30
#define RADIUS 390
#define SPEED 0.30 // 0.42 and above = 477 // 130 will outspin EVERYTHING
#define TITLE "Steam"

void Start(void *cancer);

int MoveMouseTo(int x, int y)
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

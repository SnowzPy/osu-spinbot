#pragma once
#define SPEEDRAND 30
#define RADIUS 390
#define SPEED 0.410 // 0.42 and above = 477
#define TITLE "Steam"

void Start(void *cancer);

int SendMouse(int x, int y)
{
	INPUT InputData;
	InputData.type = INPUT_MOUSE;
	InputData.mi.dx = x;
	InputData.mi.dy = y;
	InputData.mi.mouseData = NULL;
	InputData.mi.dwFlags = MOUSEEVENTF_MOVE;
	InputData.mi.time = NULL;
	InputData.mi.dwExtraInfo = GetMessageExtraInfo();

	return SendInput(1, &InputData, sizeof(InputData));
}
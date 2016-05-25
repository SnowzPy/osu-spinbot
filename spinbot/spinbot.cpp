// spinbot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "hax.h"

// #define DEBUG

using namespace std;

mt19937 gRNG;

int GetRandomInt(int min, int max)
{
	uniform_int_distribution<mt19937::result_type>dist6(min, max);

	return dist6(gRNG);
}

int main()
{
	SetConsoleTitle(TEXT(TITLE)); // recompile with something else to get a different MD5 hash

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 11); // cyan

#if defined DEBUG
	cout << GetSystemMetrics(SM_CXSCREEN) / 2 << endl << GetSystemMetrics(SM_CYSCREEN) / 2 << endl;
#endif

	gRNG.seed(random_device()());

	_beginthread(Start, 0, NULL);

	cout << "Hold SPACE to spin" << endl << "Turn raw input ON!";
	
	while(true)
	{
		Sleep(1000); // don't exit the program
	}

	return 0;
}

void Spin()
{
	static int rad = RADIUS;
	static double angle = 0;
	
	switch(dir)
	{
		case Clockwise: angle += SPEED; break;
		case CounterClockwise: angle -= SPEED; break;
	}

	double iRadius = rad - SPEEDRAND + GetRandomInt(0, (int)(SPEEDRAND * 1.2));

	double x = cos(angle) * iRadius;
	double y = sin(angle) * iRadius;

	if((int)angle % 50 == 0)
	{
		rad = (int)((RADIUS * 0.80)) + GetRandomInt(0, RADIUS / 10);
	}

	x += GetSystemMetrics(SM_CXSCREEN) / 2;
	y += GetSystemMetrics(SM_CYSCREEN) / 2;

	MoveMouseTo((long)(x), (long)(y + 25));
}

void Start(void *cancer)
{
	while(true)
	{
		if(GetAsyncKeyState(VK_SPACE) & (1 << 15))
		{
			Spin();
		}

		Sleep(1);
	}
}


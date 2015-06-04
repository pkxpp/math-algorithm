// CpuEffeciencyMake.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include "stdlib.h"
#include "math.h"

const int SAMPLING_COUNT = 200;
const double PI = 3.1415926535;
const int TOTAL_AMPLITUDE = 300;

int _tmain(int argc, _TCHAR* argv[])
{
	// 方法1
	/*for (;;)
	{
		for (int i = 0; i < 1320000000; i++)
			;
		Sleep(1000);
	}*/

	/*
	const DWORD busyTime = 3000;
	const DWORD idleTime = busyTime;

	INT64 startTime = 0;
	while (true)
	{
		DWORD startTime = GetTickCount();
		while ((GetTickCount() - startTime) <= busyTime);

		Sleep(3000);
	}*/

	//4. sin
	DWORD busySpan[SAMPLING_COUNT];
	int amplitude = TOTAL_AMPLITUDE / 2;
	double radian = 0.0;
	double radianIncrement = 2.0 / (double)SAMPLING_COUNT;
	for (int i = 0; i < SAMPLING_COUNT; i++)
	{
		busySpan[i] = (DWORD)(amplitude + (sin(PI * radian) * amplitude));			//	正弦曲线
		//busySpan[i] = (DWORD)(TOTAL_AMPLITUDE * sqrt(1 - pow((1 - radian), 2)));			// 半圆
		//busySpan[i] = (DWORD)(TOTAL_AMPLITUDE * (1 + sqrt(1 - pow((1 - radian), 2)) ) );	// 画不了圆形：x对应两个y值，做不了
		//busySpan[i] = (DWORD)(TOTAL_AMPLITUDE * (sqrt(pow((radian), 2))) + sqrt( 1- pow((radian), 2)) );			// 心形:同圆形也是做不了
		radian += radianIncrement;
		//printf("%d\t%d\n", busySpan[i], TOTAL_AMPLITUDE - busySpan[i]);
	}

	DWORD startTime = 0;
	for (int j = 0;; j = (j + 1) % SAMPLING_COUNT)
	{
		startTime = GetTickCount();
		while ((GetTickCount() - startTime) <= busySpan[j])
			;
		Sleep(TOTAL_AMPLITUDE - busySpan[j]);
	}
	

	//getchar();
	return 0;
}


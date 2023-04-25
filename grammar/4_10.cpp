#include "main.h"

void chapter_4_10()
{
	int rowNum = 15;
	int colNum = 15;
	int interval = 50;

	int width = (colNum + 1) * interval;
	int height = (rowNum + 1) * interval;
	initgraph(width, height);
	setfillcolor(GREEN);
	setlinecolor(BLACK);
	BeginBatchDraw();

	float timeCount = 0;
	while (1)
	{
		cleardevice();
		timeCount += 0.01;
		for (int y = interval; y < height; y += interval)
		{
			for (int x = interval; x < width; x += interval)
			{
				float scale = sin(timeCount - x * 2 - y * 2);
				float radius = 22 * (scale + 1);
				fillcircle(x, y, radius);
			}
		}
		FlushBatchDraw();
	}
}
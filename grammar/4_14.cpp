#include "main.h"

void chapter_4_14()
{
	int rowNum = 15; // 棋盘行数
	int colNum = 15; // 棋盘列数
	int length = 40;
	int width = (rowNum + 2) * length; // 画面宽度
	int height = (colNum + 2) * length; // 画面高度

	initgraph(width, height); // 新建画面
	setbkcolor(WHITE); // 画面背景设为白色
	cleardevice(); // 用背景色清空画面

	for (int i = 0; i < rowNum; i++)
		for (int j = 0; j < colNum; j++)
		{
			if ((i - j) % 2 == 0) // 设置黄色
			{
				setlinecolor(RGB(170, 220, 0));
				setfillcolor(RGB(170, 220, 0));
			}
			else // 设置青色
			{
				setlinecolor(RGB(60, 190, 30));
				setfillcolor(RGB(60, 190, 30));
			}
			fillrectangle((i + 1) * length, (j + 1) * length, (i + 2) * length, (j + 2) * length);
		}

	for (int i = 1; i < rowNum; i++)
		for (int j = 1; j < colNum; j++)
		{
			if ((i - j) % 3 == 0) // 设置白色
			{
				setlinecolor(RGB(230, 255, 240));
				setfillcolor(RGB(230, 255, 240));
			}
			else // 设为红色
			{
				setlinecolor(RGB(175, 50, 140));
				setfillcolor(RGB(175, 50, 140));
			}
			fillcircle((i + 1) * length, (j + 1) * length, 4);
		}
}
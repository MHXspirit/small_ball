// 用 easyx 学习 C 语言
// IDE：vs2022
// 课程：《C 语言程序设计：一个小球的编程之旅》- 童晶老师
// 视频链接：https://space.bilibili.com/652060948

#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main()
{
	int width = 1200; // 画面宽度
	int height = 800; // 画面高度
	initgraph(width, height); // 初始化画面

	float blockWidth = 20; // 障碍物宽度
	float gapHeight = height * 0.5; // 空隙高度
	float xBlockLeft = width * 0.8; // 障碍物左侧 x 坐标
	float xBlockRight = xBlockLeft + blockWidth; // 障碍物右侧 x 坐标
	float yGapTop = height / 3; // 空隙顶部坐标
	float yGapBottom = yGapTop + gapHeight; // 空隙底部坐标

	while (1)
	{
		cleardevice(); // 清屏
		fillrectangle(xBlockLeft, 0, xBlockRight, yGapTop); // 画上方障碍物
		fillrectangle(xBlockLeft, yGapBottom, xBlockRight, height); // 画下方障碍物

		// 障碍物从右向左移动
		xBlockLeft -= 3;
		xBlockRight = xBlockLeft + blockWidth;
		if (xBlockRight <= 0)
			xBlockLeft = width;

		Sleep(5);
	}

	return 0;
}
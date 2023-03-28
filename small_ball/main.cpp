// 用 easyx 学习 C 语言
// 课程：《C 语言程序设计：一个小球的编程之旅》- 童晶老师
// 视频链接：https://space.bilibili.com/652060948

#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main()
{
	int width = 800; // 画面宽度
	int height = 600; // 画面高度
	int x = width / 2; // 小球 x 坐标
	int y = height / 2; // 小球 y 坐标
	int radius = 20; // 小球半径
	int vx = 3; // 小球 x 方向速度
	int vy = 4; // 小球 y 方向速度
	initgraph(width, height); // 新建画面
	
	while (1)
	{
		cleardevice(); // 清屏
		fillcircle(x, y, radius); // 画小球

		// 小球碰到上下左右边界，速度反向
		if (y >= height - radius || y <= radius)
		{
			vy = -vy;
		}
		if (x >= width - radius || x <= radius)
		{
			vx = -vx;
		}

		y = y + vy; // 更新小球 x 坐标
		x = x + vx; // 更新小球 y 坐标
		Sleep(30); // 暂停30ms
	}
	
	return 0;
}
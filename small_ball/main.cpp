// 用 easyx 学习 C 语言
// IDE：vs2022
// 课程：《C 语言程序设计：一个小球的编程之旅》- 童晶老师
// 视频链接：https://space.bilibili.com/652060948

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
	int width = 800; // 画面宽度
	int height = 600; // 画面高度

	float x = width / 6; // 小球 x 坐标
	float y = height / 2; // 小球 y 坐标
	int radius = 20; // 小球半径
	float vy = 0; // 小球下落速度
	float g = 0.3; // 小球下落加速度

	float blockWidth = 30; // 障碍物宽度
	float gapHeight = height * 0.5; // 空隙高度
	float xBlockLeft = width * 0.8; // 障碍物左侧 x 坐标
	float xBlockRight = xBlockLeft + blockWidth; // 障碍物右侧 x 坐标
	float yGapTop = height / 3; // 空隙顶部坐标
	float yGapBottom = yGapTop + gapHeight; // 空隙底部坐标

	int score = 0; // 得分
	int scoreFlag = 1; // 得分判定，1 为可以得分，0 为不可以得分

	int life = 3; // 生命条数
	int lifeFlag = 1; // 扣命判定，1 为可以扣命，0 为不可以扣命

	initgraph(width, height); // 初始化画面
	BeginBatchDraw(); // 开始批量绘制，提升画面流畅度

	while (1)
	{
		cleardevice(); // 清屏
		fillcircle(x, y, radius); // 画小球
		fillrectangle(xBlockLeft, 0, xBlockRight, yGapTop); // 画上方障碍物
		fillrectangle(xBlockLeft, yGapBottom, xBlockRight, height); // 画下方障碍物

		TCHAR s[20]; // 定义字符串数组
		settextstyle(30, 0, _T("宋体")); // 设置文字大小、字体
		swprintf_s(s, _T("生命：%d"), life); // 将life转换为字符串		
		outtextxy(20, 10, s); // 输出血量文字
		swprintf_s(s, _T("得分：%d"), score); // 将score转换为字符串		
		outtextxy(20, 40, s); // 输出得分文字

		// 生命归零，游戏结束
		if (life <= 0)
			break;

		// 按下空格，小球向上
		if (_kbhit())
		{
			char input = _getch();
			if (input == ' ')
				vy = -8;
		}

		// 障碍物从右向左移动，高度随机
		xBlockLeft -= 3 + score / 10 * 2; // 障碍物移动速度根据得分越来越快
		xBlockRight = xBlockLeft + blockWidth;
		if (xBlockRight < 0)
		{
			gapHeight = height * 0.5 - score / 10 * 10; // 障碍物空隙根据得分越来越小
			yGapTop = rand() % (height / 2);
			yGapBottom = yGapTop + gapHeight;
			xBlockLeft = width;
			xBlockRight = xBlockLeft + blockWidth;
			scoreFlag = 1;
			lifeFlag = 1;
		}

		// 障碍物与小球碰撞
		if ((x + radius >= xBlockLeft && x - radius <= xBlockRight)
			&& (y - radius <= yGapTop || y + radius >= yGapBottom))
		{
			Sleep(20); // 慢动作效果
			scoreFlag = 0; // 不可以得分
			if (lifeFlag == 1)
			{
				life--;
				lifeFlag = 0; // 扣了一条命后，不可以继续扣命
			}
		}

		// 小球自由下落
		vy = vy + g;
		y = y + vy;
		if (y <= radius || y >= height - radius)
		{
			life--;
			y = height / 2;
			vy = 0;
		}

		// 得分，每得10分加1命
		if ((x - radius > xBlockRight) && scoreFlag == 1)
		{
			scoreFlag = 0;
			score++;
			if (score != 0 && score % 10 == 0)
				life++;
		}

		FlushBatchDraw();
		Sleep(3);
	}

	return 0;
}
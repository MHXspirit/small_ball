// 用 easyx 学习 C 语言
// 课程：《C 语言程序设计：一个小球的编程之旅》- 童晶老师
// 视频链接：https://space.bilibili.com/652060948

#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main()
{
	int width = 800;
	int height = 600;
	int x = 400;
	int y = 300;
	int radius = 100;

	initgraph(width, height);
	fillcircle(x, y, radius);
	_getch();

	return 0;
}
// �� easyx ѧϰ C ����
// �γ̣���C ���Գ�����ƣ�һ��С��ı��֮�á�- ͯ����ʦ
// ��Ƶ���ӣ�https://space.bilibili.com/652060948

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
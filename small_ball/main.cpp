// �� easyx ѧϰ C ����
// �γ̣���C ���Գ�����ƣ�һ��С��ı��֮�á�- ͯ����ʦ
// ��Ƶ���ӣ�https://space.bilibili.com/652060948

#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main()
{
	int width = 800; // ������
	int height = 600; // ����߶�
	int x = width / 2; // С�� x ����
	int y = height / 2; // С�� y ����
	int radius = 20; // С��뾶
	int vx = 3; // С�� x �����ٶ�
	int vy = 4; // С�� y �����ٶ�
	initgraph(width, height); // �½�����
	
	while (1)
	{
		cleardevice(); // ����
		fillcircle(x, y, radius); // ��С��

		// С�������������ұ߽磬�ٶȷ���
		if (y >= height - radius || y <= radius)
		{
			vy = -vy;
		}
		if (x >= width - radius || x <= radius)
		{
			vx = -vx;
		}

		y = y + vy; // ����С�� x ����
		x = x + vx; // ����С�� y ����
		Sleep(30); // ��ͣ30ms
	}
	
	return 0;
}
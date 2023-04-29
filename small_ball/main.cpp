// �� easyx ѧϰ C ����
// IDE��vs2022
// �γ̣���C ���Գ�����ƣ�һ��С��ı��֮�á�- ͯ����ʦ
// ��Ƶ���ӣ�https://space.bilibili.com/652060948

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
	int width = 800; // ������
	int height = 600; // ����߶�

	float x = width / 6; // С�� x ����
	float y = height / 2; // С�� y ����
	int radius = 20; // С��뾶
	float vy = 0; // С�������ٶ�
	float g = 0.3; // С��������ٶ�

	float blockWidth = 30; // �ϰ�����
	float gapHeight = height * 0.5; // ��϶�߶�
	float xBlockLeft = width * 0.8; // �ϰ������ x ����
	float xBlockRight = xBlockLeft + blockWidth; // �ϰ����Ҳ� x ����
	float yGapTop = height / 3; // ��϶��������
	float yGapBottom = yGapTop + gapHeight; // ��϶�ײ�����

	int score = 0; // �÷�
	int scoreFlag = 1; // �÷��ж���1 Ϊ���Ե÷֣�0 Ϊ�����Ե÷�

	int life = 3; // ��������
	int lifeFlag = 1; // �����ж���1 Ϊ���Կ�����0 Ϊ�����Կ���

	initgraph(width, height); // ��ʼ������
	BeginBatchDraw(); // ��ʼ�������ƣ���������������

	while (1)
	{
		cleardevice(); // ����
		fillcircle(x, y, radius); // ��С��
		fillrectangle(xBlockLeft, 0, xBlockRight, yGapTop); // ���Ϸ��ϰ���
		fillrectangle(xBlockLeft, yGapBottom, xBlockRight, height); // ���·��ϰ���

		TCHAR s[20]; // �����ַ�������
		settextstyle(30, 0, _T("����")); // �������ִ�С������
		swprintf_s(s, _T("������%d"), life); // ��lifeת��Ϊ�ַ���		
		outtextxy(20, 10, s); // ���Ѫ������
		swprintf_s(s, _T("�÷֣�%d"), score); // ��scoreת��Ϊ�ַ���		
		outtextxy(20, 40, s); // ����÷�����

		// �������㣬��Ϸ����
		if (life <= 0)
			break;

		// ���¿ո�С������
		if (_kbhit())
		{
			char input = _getch();
			if (input == ' ')
				vy = -8;
		}

		// �ϰ�����������ƶ����߶����
		xBlockLeft -= 3 + score / 10 * 2; // �ϰ����ƶ��ٶȸ��ݵ÷�Խ��Խ��
		xBlockRight = xBlockLeft + blockWidth;
		if (xBlockRight < 0)
		{
			gapHeight = height * 0.5 - score / 10 * 10; // �ϰ����϶���ݵ÷�Խ��ԽС
			yGapTop = rand() % (height / 2);
			yGapBottom = yGapTop + gapHeight;
			xBlockLeft = width;
			xBlockRight = xBlockLeft + blockWidth;
			scoreFlag = 1;
			lifeFlag = 1;
		}

		// �ϰ�����С����ײ
		if ((x + radius >= xBlockLeft && x - radius <= xBlockRight)
			&& (y - radius <= yGapTop || y + radius >= yGapBottom))
		{
			Sleep(20); // ������Ч��
			scoreFlag = 0; // �����Ե÷�
			if (lifeFlag == 1)
			{
				life--;
				lifeFlag = 0; // ����һ�����󣬲����Լ�������
			}
		}

		// С����������
		vy = vy + g;
		y = y + vy;
		if (y <= radius || y >= height - radius)
		{
			life--;
			y = height / 2;
			vy = 0;
		}

		// �÷֣�ÿ��10�ּ�1��
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
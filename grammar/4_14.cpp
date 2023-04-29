#include "main.h"

void chapter_4_14()
{
	int rowNum = 15; // ��������
	int colNum = 15; // ��������
	int length = 40;
	int width = (rowNum + 2) * length; // ������
	int height = (colNum + 2) * length; // ����߶�

	initgraph(width, height); // �½�����
	setbkcolor(WHITE); // ���汳����Ϊ��ɫ
	cleardevice(); // �ñ���ɫ��ջ���

	for (int i = 0; i < rowNum; i++)
		for (int j = 0; j < colNum; j++)
		{
			if ((i - j) % 2 == 0) // ���û�ɫ
			{
				setlinecolor(RGB(170, 220, 0));
				setfillcolor(RGB(170, 220, 0));
			}
			else // ������ɫ
			{
				setlinecolor(RGB(60, 190, 30));
				setfillcolor(RGB(60, 190, 30));
			}
			fillrectangle((i + 1) * length, (j + 1) * length, (i + 2) * length, (j + 2) * length);
		}

	for (int i = 1; i < rowNum; i++)
		for (int j = 1; j < colNum; j++)
		{
			if ((i - j) % 3 == 0) // ���ð�ɫ
			{
				setlinecolor(RGB(230, 255, 240));
				setfillcolor(RGB(230, 255, 240));
			}
			else // ��Ϊ��ɫ
			{
				setlinecolor(RGB(175, 50, 140));
				setfillcolor(RGB(175, 50, 140));
			}
			fillcircle((i + 1) * length, (j + 1) * length, 4);
		}
}
// �� easyx ѧϰ C ����
// IDE��vs2022
// �γ̣���C ���Գ�����ƣ�һ��С��ı��֮�á�- ͯ����ʦ
// ��Ƶ���ӣ�https://space.bilibili.com/652060948

#include <stdio.h>
#include <graphics.h>
#include <conio.h>

int main()
{
	int width = 1200; // ������
	int height = 800; // ����߶�
	initgraph(width, height); // ��ʼ������

	float blockWidth = 20; // �ϰ�����
	float gapHeight = height * 0.5; // ��϶�߶�
	float xBlockLeft = width * 0.8; // �ϰ������ x ����
	float xBlockRight = xBlockLeft + blockWidth; // �ϰ����Ҳ� x ����
	float yGapTop = height / 3; // ��϶��������
	float yGapBottom = yGapTop + gapHeight; // ��϶�ײ�����

	while (1)
	{
		cleardevice(); // ����
		fillrectangle(xBlockLeft, 0, xBlockRight, yGapTop); // ���Ϸ��ϰ���
		fillrectangle(xBlockLeft, yGapBottom, xBlockRight, height); // ���·��ϰ���

		// �ϰ�����������ƶ�
		xBlockLeft -= 3;
		xBlockRight = xBlockLeft + blockWidth;
		if (xBlockRight <= 0)
			xBlockLeft = width;

		Sleep(5);
	}

	return 0;
}
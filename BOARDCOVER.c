#include <stdio.h>
#pragma warning(disable:4996)

int C, c;//Test Cases
int H, W;
char pan[20][20];

//����: '.' ���ڰ� �ִ� ������ 3ĭ¥�� L�� ������� �����.
//�Ϸ� ����: '.' ���ڰ� �ϳ��� ����.
//���� ����: 3ĭ �̸� ���Ҵ�. ���� ĭ�� L�� ������� ���� �� ����.
int func(void)
{
	//������ '.' ���� ��ġ�� ã�´�.
	int i_now = -1, j_now = -1, i, j, ret = 0;
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
			if (pan[i][j] == '.')
				{
					i_now = i; j_now - j;
					break;
				}
		if (i_now != -1) break;
	}
	if (i_now == -1) return 1; //Nothing left
	//x,y�� �������� L�ڸ� ���� �� �ִ� ��� ����� ���� ���� ó��
	//x,y�� ������ '.'�̶� ���� ����ϸ� �� ���� ��� ��
	if (i_now < H - 1 && j_now > 0 && pan[i_now + 1][j_now] == '.' &&pan[i_now + 1][j_now - 1] == '.')
	{
		//# .
		//. .
		pan[i_now][j_now] = pan[i_now + 1][j_now] = pan[i_now + 1][j_now - 1] = '#';
		ret += func();
		pan[i_now][j_now] = pan[i_now + 1][j_now] = pan[i_now + 1][j_now - 1] = '.';
	}
	if (i_now < H - 1 && j_now < W - 1 && pan[i_now + 1][j_now] == '.' && pan[i_now + 1][j_now + 1] == '.')
	{
		// . #
		// . .
		pan[i_now][j_now] = pan[i_now + 1][j_now] = pan[i_now + 1][j_now + 1] = '#';
		ret += func();
		pan[i_now][j_now] = pan[i_now + 1][j_now] = pan[i_now + 1][j_now + 1] = '.';
	}
	if (i_now < H - 1 && j_now > W - 1 && pan[i_now + 1][j_now] == '.' &&pan[i_now + 1][j_now + 1] == '.')
	{
		//# .
		//. .
		pan[i_now][j_now] = pan[i_now + 1][j_now] = pan[i_now + 1][j_now - 1] = '#';
		ret += func();
		pan[i_now][j_now] = pan[i_now + 1][j_now] = pan[i_now + 1][j_now - 1] = '.';
	}
	if (i_now < H - 1 && j_now < W - 1 && pan[i_now][j_now + 1] == '.' && pan[i_now + 1][j_now + 1] == '.')
	{
		// . #
		// . .
		pan[i_now][j_now] = pan[i_now + 1][j_now] = pan[i_now + 1][j_now + 1] = '#';
		ret += func();
		pan[i_now][j_now] = pan[i_now + 1][j_now] = pan[i_now + 1][j_now + 1] = '.';
	}
	return ret;
}

int main(void)
{
	int i;
	scanf("%d", &C);
	for (c = 0; c < C; c++)
	{
		scanf("%d %d", &H, &W);
		for (i = 0; i < H; i++)
			scanf("%s", pan[i]);
		int ret = func();
		printf("%d\n", ret);
	}
	return 0;
}
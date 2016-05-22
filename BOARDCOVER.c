#include <stdio.h>
#pragma warning(disable:4996)

int C, c;//Test Cases
int H, W;
char pan[20][20];

//문제: '.' 문자가 있는 공간을 3칸짜리 L자 블록으로 덮어라.
//완료 조건: '.' 문자가 하나도 없다.
//실패 조건: 3칸 미만 남았다. 남은 칸을 L자 블록으로 덮을 수 없다.
int func(void)
{
	//최초의 '.' 문자 위치를 찾는다.
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
	//x,y를 기준으로 L자를 만들 수 있는 모든 경우의 수에 대해 처리
	//x,y가 최초의 '.'이란 점을 고려하면 네 가지 방법 뿐
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
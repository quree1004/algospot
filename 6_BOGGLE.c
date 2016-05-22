#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int C; // Test Case
char pan[10][10];
int N; // Num of Strings
char str[20];
int len;
const int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };

// Found : 1, Not Found : 0 Return
int search(int ii, int jj, int idx)
{

	if (ii < 0 || ii >= 5 || jj < 0 | jj >= 5) return 0; // 게임판 범위 확인
	if (idx >= len) return 0; // 글자수 범위 확인
	if (pan[ii][jj] != str[idx]) return 0; // 첫번째 글자 일치확인

	//Done!
	if (pan[ii][jj] == str[idx] && idx == len - 1) return 1;

	//Recursive Call
	int dir = 0; 
	for (dir = 0; dir < 8; dir++)
	{
		if (search(ii + dx[dir], jj + dy[dir], idx + 1)) return 1;
	}
	//Can't find
	return 0;
}

int i, j, c, n;

int main(void) {
	scanf("%d", &C);
	for (c = 0; c < C; c++)
	{
		for (i = 0; i < 5; i++)
			scanf("%s", pan[i]);
		scanf("%d", &N);
		for (n = 0; n < N; n++)
		{
			scanf("%s", str);
			len = strlen(str);
			for (i = 0; i < 5; i++)
			{	for (j = 0; j < 5; j++)
				{
					int ret = search(i, j, 0);
					if (ret = 1)
						goto FINISH;

				}
			}
	FINISH:
	
			if (i == 5 && j == 5)
				printf("%s %s\n", str, "NO");
			else
				printf("%s %s\n", str, "YES");
		}
	}

	return 0;

}
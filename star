Enter file contents here#include <stdio.h>

int main()
{
	int N;
	
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < N - i; j++)
			printf(" ");
		for (int k = 0; k < i; k++)
			printf("*");

		putchar('\n');
	}

	return 0;
}
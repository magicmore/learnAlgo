#include <stdio.h>

static const int LEN = 7;
static const unsigned int INFINITE = 0xfffffff;
int cost[LEN] = {30, 35, 15, 5, 10, 20, 25};
unsigned int multiCost[LEN-1][LEN-1];
unsigned int decesion[LEN-1][LEN-1];

void findArrayMinOrder()
{
	for (int i = 0; i < LEN-1; ++i)
	{
		for (int j=0; j < LEN-1; ++j)
		{
			decesion[i][j] = 0x0;
			multiCost[i][j] = 0x0;
		}
	}
	for (int l = 2; l < LEN; ++l)
	{
		for (int i = 0; i < LEN-l; ++i)
		{
			int j = i + l - 1;
			multiCost[i][j] = INFINITE;
			for (int k = i; k < j; ++k)
			{
				int q = multiCost[i][k] + multiCost[k+1][j] + cost[i]*cost[k+1]*cost[j+1];
				if (q < multiCost[i][j])
				{
					multiCost[i][j] = q;
					decesion[i][j] = k;
				}

			}
		}
	}
	for (int i = 0; i < LEN-1; ++i)
	{
		for (int j=0; j < LEN-1; ++j)
		{
			printf("%5d ,", decesion[i][j]);
		}
		printf("\n");
	}
}

void printRes(int i, int j)
{
	if (i == j)
	{
		printf("A%d", i);
	}
	else
	{
		int k = decesion[i][j];
		printf("(");
		printRes(i, k);
		printRes(k+1, j);
		printf(")");		
	}

}
int main(int argc, char const *argv[])
{
	findArrayMinOrder();
	printRes(0,LEN-2);
	return 0;
}
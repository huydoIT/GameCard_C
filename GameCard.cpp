#include <iostream>
#include <stdio.h>
#include <time.h>

//int tb[4][13] = { 0 };

void createData(int dt[4][13], int sta[4][13]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			dt[i][j] = j + 1;
		}
		for (int j = 0; j < 13; j++) {
			int r = rand() % 12;
			int t = dt[i][j];
			dt[i][j] = dt[i][r];
			dt[i][r] = t;
			sta[i][j] = 0;
		}
	}
}

void printData(int dt[4][13]) {
	printf("===================================== Data ====================================\n\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			printf("%4d |", dt[i][j]);
		}
		printf("\n");
	}
	printf("\n=================================== ******* ===================================\n");
}

void printTable(int dt[4][13]) {
	printf("===================================== Data ====================================\n\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			if (dt[i][j] == 0) {
				printf("%3c |", 'O');
			} else
				printf("%3c |", 'X');
		}
		printf("\n");
	}
	printf("\n=================================== ******* ===================================\n");
}

void printChoose(int dt[4][13], int r1, int c1, int r2, int c2) {
	printf("===================================== Data ====================================\n\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			if (((i == r1)&&(j==c1)) || ((i == r2) && (j == c2))) {
				printf("%3d |", dt[i][j]);
			}
			else
				printf("%3c |", 'O');
		}
		printf("\n");
	}
	printf("\n=================================== ******* ===================================\n");
}
int main()
{
	srand((unsigned)time(NULL));
	int tb[4][13] = { 0 };
	int state[4][13] = { 0 };
	int point = 0;
	int p1 = 0, p2 = 0;
	int game = 0;
	createData(tb, state);
	printData(tb);
	while (point < 10)
	{
		int r1, c1, r2, c2;
		//printData(tb);
		printTable(state);
		printf("%s", game == 0 ? "Player A\n" : "Player B\n");
		printf("Input choose [1]: ");
		scanf("%d %d", &r1, &c1);
		printf("Input choose [2]: ");
		scanf("%d %d", &r2, &c2);
		
		if (tb[r1][c1] == tb[r2][c2]) {
			//point += 2;
			
			state[r1][c1] = state[r2][c2] = 1;
			printf("%d point\n", game == 0 ? p1 += 2 : p2 += 2);
		}
		else {
			printChoose(tb, r1, c1, r2, c2);
			printf("Sorry!\n");
			game == 0 ? game = 1 : game = 0;
		}
	}
	printf("=== End ===\n");
}

#include <iostream>
#include <stdio.h>
#include <time.h>
#define LINE "\n====================================================================\n"
int dt[4][13] = { 0 };
/**
 * Tạo dữ liệu, status
 */
void createData() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			dt[i][j] = j + 1;
		}
		for (int j = 0; j < 13; j++) {
			int r = rand() % 12;
			int temp = dt[i][j];
			dt[i][j] = dt[i][r];
			dt[i][r] = temp;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			int r = rand() % 3;
			int c = rand() % 12;
			int temp = dt[i][j];
			dt[i][j] = dt[r][c];
			dt[r][c] = temp;
		}
	}
}

/**
 * Hien thi du lieu (full)
 */
void displayData() {
	printf("====================================== Data =====================================\n\n");
	printf("  |");
	for (int i = 0; i < 13; i++) {
		printf("%3d |", i);
	}
	printf(LINE);
	for (int i = 0; i < 4; i++) {
		printf("%d||", i);
		for (int j = 0; j < 13; j++) {
			printf("%3d |", dt[i][j]);
		}
		printf("\n--------------------------------------------------------------------\n");
	}
	printf("\n=================================== ******* ===================================\n");
}

/**
 * Hien thi du lieu o vi tri row, col
 *
 * @param arr[][], row1, col1, row2, col2.
 */
void display(int r1, int c1, int r2, int c2) {
	printf("=============================== GAMES ==============================\n\n");
	printf("  |");
	for (int i = 0; i < 13; i++) {
		printf("%3d |", i);
	}
	printf(LINE);
	for (int i = 0; i < 4; i++) {
		printf("%d |", i);
		for (int j = 0; j < 13; j++) {
			if (((i == r1)&&(j==c1)) || ((i == r2) && (j == c2))) {
				printf("%3d |", dt[i][j]);
			}
			else if (dt[i][j] > 0) {
				printf("%3c |", '#');
			}
			else
				printf("%3c |", ' ');
		}
		printf("\n--------------------------------------------------------------------\n");
	}
	printf("\n");
	//printf("\n============================== ******* ==============================\n");
}
int main()
{
	srand((unsigned)time(NULL));
	int count = 6;
	int p1 = 0, p2 = 0;
	int game = 0;
	createData();
	//displayData();
	while (count > 0)
	{
		int r1, c1, r2, c2;
		//printData(tb);
		//printTable();
		display(-1, -1, -1, -1);
		printf("%s", game == 0 ? "Player A\n" : "Player B\n");
		printf("Input choose [1]: ");
		scanf("%d %d", &r1, &c1);
		display(r1, c1, -1, -1);
		printf("Input choose [2]: ");
		scanf("%d %d", &r2, &c2);
		display(-1, -1, r2, c2);

		if (dt[r1][c1] == dt[r2][c2]) {
			count -= 2;
			dt[r1][c1] = dt[r2][c2] = -1;
			printf("%d point\n", game == 0 ? p1 += 2 : p2 += 2);
		}
		else {
			printf("Sorry!\n");
			game == 0 ? game = 1 : game = 0;
		}
	}
	printf("=== The End ===\n");
	printf("%s won!!!\n\n", p1 > p2 ? "Player A" : "Player B");
	getchar();
}

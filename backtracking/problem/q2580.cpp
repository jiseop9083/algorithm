//백준 2580번 스도쿠
//
//단순 반복으로 채워보자

#include <stdio.h>

int table[15][15];
int pos[85][2];//y,x
int count = 0;
int end = 0;

void reduce(int deep) {
	if (deep == count) {
		end = 1;
		return;
	}
	for (int i = 1; i < 10; i++) {//넣을 숫자
		int nonzero = 0;
		for (int j = 0; j < 9; j++) {
			if (table[pos[deep][0]][j] == i ||table[j][pos[deep][1]] == i || table[((pos[deep][0] / 3) * 3) + (j / 3)][((pos[deep][1] / 3)*3) + (j % 3)] == i) {
				break;
			}
			else {
				nonzero++;
			}
		}
		if (nonzero == 9) {
			table[pos[deep][0]][pos[deep][1]] = i;
			reduce(deep + 1);
			continue;
		}

	}
	if (end == 0) {
		table[pos[deep - 1][0]][pos[deep - 1][1]] = 0;
	}
	return;
}


int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &table[i][j]);
			if (table[i][j] == 0) {
				pos[count][0] = i;
				pos[count][1] = j;
				count++;
				continue;
			}
		}
	}
	reduce(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", table[i][j]);
		}
		printf("\n");
	}
	return 0;
}
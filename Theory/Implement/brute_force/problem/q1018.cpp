//백준 1018번 체스판 다시 칠하기
//브루트포스 알고리즘으로 하나씩 하면 된다.

#include <stdio.h>

int main() {
	int n, m;
	char chess[55][55];
	scanf("%d  %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", &chess[i]);
	}
	int min = 64;

	for (int i = 0; i < n-7; i++) {
		for (int j = 0; j < m-7; j++) {
			for (int h = 0; h < 2; h++) {
				char color;
				int num = 0;
				for (int k = i; k < i + 8; k++) {
					for (int l = j; l < j + 8; l++) {
						if (l == j && k == i) {
							if (h) color = 'W';
							else color = 'B';
						}
						else if ((l != j && color == chess[k][l - 1]) || (l == j && color != chess[k - 1][l + 7])) {
							num++;
						}
						if (l != j + 7) {
							if (color == 'W') color = 'B';
							else if (color == 'B') color = 'W';
						}
						if (k == i+7 && l == j+7 && color != chess[k][l]) num++;
					}
				}
				if (min > num) min = num;
			}
		}
	}
	printf("%d", min);
	return 0;
}
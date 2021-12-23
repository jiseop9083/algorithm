//백준 18111번 마인크래프트
//마지막에만 인벤토리가 양수면 된다!

#include <stdio.h>

int main() {
	int n, m, b;
	int dart[505][505];
	int min = 2 * 500 * 500 * 256 * 10;
	int high = 0;
	scanf("%d %d %d", &n, &m, &b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &dart[i][j]);
		}
	}
	for (int i = 0; i <= 256; i++) {
		int time = 0;
		int inven = b;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (dart[j][k] > i) {
					time += (dart[j][k] - i) * 2;
					inven += (dart[j][k] - i);
				}
				else if (dart[j][k] < i) {
					time += (i - dart[j][k]);
					inven -= (i - dart[j][k]);
				}
			}
		}
		if (time <= min && inven >= 0) {
			min = time;
			high = i;
		}
	}
	printf("%d %d\n", min, high);
	return 0;
}
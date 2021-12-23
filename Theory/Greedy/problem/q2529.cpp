//백준 2529번 부등호
//각 부등호의 개수를 세서 최대, 최소를 각각 구하자.

#include <cstdio>
#include <algorithm>

bool naerim(int a, int b) {
	return a > b;
}

int main() {
	int k;
	char inequal[10];
	int pos[11] = { -1, -1, -1, -1, -1, -1 , -1, -1, -1 ,-1};

	int p = 0;
	int m = 0;
	scanf("%d ", &k);
	int plus = 9;
	int minus = k;
	char a;
	int turn = 0;
	while (turn < k) {
		scanf("%c", &a);
		if (a == '<') {
			inequal[turn] = a;
			turn++;
		}
		else if (a == '>') {
			inequal[turn] = a;
			turn++;
		}
	}
	//최대
	for (int i = 0; i < k; i++) {
		if (inequal[i] == '>') {
			for (int j = i; j >= 0; j--) {
				if (pos[j] == -1) {
					pos[j] = plus;
					plus--;
				}
			}
		}
	}
	if (inequal[k - 1] == '<') {
		for (int j = k; j >= 0; j--) {
			if (pos[j] == -1) {
				pos[j] = plus;
				plus--;
			}
		}
	}
	else
		pos[k] = plus;

	for (int i = 0; i <= k; i++) {
		printf("%d", pos[i]);
		pos[i] = -1;
	}
	printf("\n");

	for (int i = k - 1; i >= 0; i--) {
		if (inequal[i] == '<') {
			for (int j = i + 1; j <= k; j++) {
				if (pos[j] == -1) {
					pos[j] = minus;
					minus--;
				}
			}
		}
	}
	if (inequal[0] == '>') {
		for (int j = 0; j <= k; j++) {
			if (pos[j] == -1) {
				pos[j] = minus;
				minus--;
			}
		}
	}
	else
		pos[0] = minus;


	for (int i = 0; i <= k; i++) {
		printf("%d", pos[i]);
	}
	printf("\n");
}

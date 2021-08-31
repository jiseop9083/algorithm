//백준 2661번 좋은수열
//백트랙킹으로 간선의 확장을 제한하자!
//전수조사로 나쁜 수열 거르기

#include<cstdio>
int n;
int sequence[81];
int pri = 0;

void backtracking(int depth) {
	if (pri != 0) return;
	else if (depth == n && pri == 0) {
		for (int i = 0; i < n; i++) {
			printf("%d", sequence[i]);
		}
		printf("\n");
		pri = 1;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		int bad = 0;
		sequence[depth] = i;
		for (int j = 1; j <= ((depth+1) / 2); j++) {
			for (int k = 0; k + (j * 2) <= depth+1; k++) {//이동
				int count = 0;
				for (int m = 0; m < j; m++) {
					if (sequence[k + m] == sequence[k + m + j])
						count++;
				}
				if (count == j) {
					bad = 1;
					count = 0;
					continue;
				}

			}
		}
		if (bad) continue;
		backtracking(depth + 1);
	}
}

int main() {
	scanf("%d", &n);
	backtracking(0);
	return 0;
}
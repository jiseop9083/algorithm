//백준 1182번 부분수열의 합
//트리를 생성하면서 백트렉킹을 연습해보자!

#include <cstdio>
int n, s;
int sol[21];
int part[21];
int count = 0;

void backtracking(int depth) {
	if (depth == n) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (part[i] == 1)
				sum += sol[i];
		}
		if (sum == s)
			count++;
		return;
	}
	for (int i = 0; i <= 1; i++) {
		part[depth] = i;
		backtracking(depth + 1);
	}
}


int main() {
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &sol[i]);
	}
	backtracking(0);
	if (s == 0) {//공집합일 경우 뺄 것
		printf("%d", count-1);
	}
	else {
		printf("%d", count);
	}
	return 0;
}
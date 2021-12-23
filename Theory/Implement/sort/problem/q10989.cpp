// 백준 10989번 수 정렬하기3
// 10,000,000개의 수를 모두 저장함과 동시에 메모리는 8MB를 넘는다
// 자연수가 몇 번 입력되는지를 저장하자.

#include <stdio.h>


int main() {
	long long t;
	int number;
	int num[10005] = { 0, };
	scanf("%lld", &t);
	for (long long i = 0; i < t; i++) {
		scanf("%d", &number);
		num[number]++;
	}
	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < num[i]; j++) {
			printf("%d\n", i);
		}
	}
	return 0;
}
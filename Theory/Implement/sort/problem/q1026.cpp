//백준 1026번 보물 
//B배열에서의 큰 수는 A배열의 작은 수를 만나야한다.
//출력형태는 최솟값이므로 A는 오름차순, B는 내림차순으로 정렬하자.

#include <stdio.h>

int A[51];
int B[51];

void quick_sort(int list[], int start, int end) {
	if (start >= end) return;
	int laft_index = start + 1;
	int light_index = end;

	while (laft_index <= light_index) {
		while (laft_index <= end && list[laft_index] <= list[start]) {
			laft_index++;
		}
		while (light_index > start && list[light_index] >= list[start]) {
			light_index--;
		}
		if (laft_index > light_index) {
			int swap = list[start];
			list[start] = list[light_index];
			list[light_index] = swap;
		}
		else {
			int swap = list[laft_index];
			list[laft_index] = list[light_index];
			list[light_index] = swap;
		}
	}


	quick_sort(list, start, light_index - 1);
	quick_sort(list, light_index + 1, end);
}




int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &B[i]);
	}
	quick_sort(A, 0, n-1);
	quick_sort(B, 0, n-1);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += A[i] * B[n - i-1];
	}
	printf("%d", sum);
	return 0;
}
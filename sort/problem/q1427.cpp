//백준 1727 소트인사이드
//버블 정렬


#include <stdio.h>

int main() {
	int num[15];
	char arr[15];
	scanf("%s", arr);
	int n = 0;
	while (arr[n] != '\0') {
		num[n] = (int)arr[n]-48;
		n++;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (num[j] < num[j + 1]) {
				int swap = num[j];
				num[j] = num[j + 1];
				num[j+1] = swap;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d", num[i]);
	}
	
	return 0;
}
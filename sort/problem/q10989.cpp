// ���� 10989�� �� �����ϱ�3
// 10,000,000���� ���� ��� �����԰� ���ÿ� �޸𸮴� 8MB�� �Ѵ´�
// �ڿ����� �� �� �ԷµǴ����� ��������.

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
//���� 1120�� ���ڿ�
//sequece alignment�� �������� ������.
//��������� �ּڰ��� ������.

#include <stdio.h>

int main() {
	char x[55];
	char y[55];
	scanf("%s %s", x, y);
	int min = 100;
	int a = 0;
	int b = 0;
	while (x[a] != '\0')
		a++;
	while (y[b] != '\0')
		b++;
	for (int i = 0; i <= b - a; i++) {
		int count = 0;
		for (int k = 0; k < a; k++) {
			if (x[k] != y[k+i])
				count++;
		}
		if (min > count)
			min = count;
	}
	printf("%d", min);
	return 0;
}
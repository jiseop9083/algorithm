//���� 1049�� ��Ÿ��
//��Ű���� �ּҿ� ������ �ּҸ� ������

#include <stdio.h>

int main() {
	int n, m;
	int pac;//��Ű��
	int natgae;//����
	int p_min = 1000;
	int n_min = 1000;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &pac, &natgae);
		if (p_min > pac)
			p_min = pac;
		if (n_min > natgae)
			n_min = natgae;
	}
	if (6 * n_min > p_min) {
		if((n % 6) * n_min > p_min)
			printf("%d", ((n/6)+1) * p_min);
		else printf("%d", ((n / 6) * p_min) + (n % 6) * n_min);
	}
	else printf("%d", n * n_min);
	return 0;
}
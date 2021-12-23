//���� 11004�� K��° ��
//���ϴ�...�����ϸ�ȴ�. 
//2�ʶ�� ���� ����Ϸ� �ð� ���⵵�� N^2�� �ƴϸ� �� ���ϴ�.

#include <stdio.h>

long long num[5000005];
long long list[5000005];


void merge(long long arr[], int start, int middle, int end) {
	int i = start;
	int j = middle + 1;
	int k = start;

	while (i <= middle && j <= end) {
		if (arr[i] <= arr[j]) {
			num[k] = arr[i];
			i++;
		}
		else {
			num[k] = arr[j];
			j++;
		}
		k++;
	}

	if (i > middle) {
		for (int t = j; t <= end; t++) {
			num[k] = arr[t];
			k++;
		}
	}
	else {
		for (int t = i; t <= middle; t++) {
			num[k] = arr[t];
			k++;
		}
	}
	for (int t = start; t <= end; t++) {
		arr[t] = num[t];
	}
}


void merge_sort(long long arr[], int start, int end) {
	if (start < end) {
		int middle = (start + end) / 2;
		merge_sort(arr, start, middle);
		merge_sort(arr, middle+1, end);
		merge(arr, start, middle, end);
	}

	
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &list[i]);
	}
	merge_sort(list, 0, n -1);
	printf("%lld", list[k-1]);

	return 0;
}
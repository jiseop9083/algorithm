//���� 1016�� ����������
//�Ҽ��� �������� ������ ���������� Ȯ��
//1001���� �Ҽ� ���ϱ�
//�� ���� �����ٱ��� ������������ Ȯ��

#include <iostream>
#include <cmath>
using namespace std;

long long sosu[1000010];
long long cnt = 1;
long long start, en;
long long an = 0;
bool table[1000005];

int main() {
	cin >> start >> en;
	sosu[0] = 2;
	for (long long i = 3; i <= 1000005; i++) {
		int check = 0;
		for (long long j = 0; sosu[j] * sosu[j] <= i; j++) {
			if (i % sosu[j] == 0) {
				check = 1;
				break;
			}
		}
		if (check == 0) {
			sosu[cnt] = i;
			cnt++;
		}
	}
	for (long long j = 0; sosu[j] * sosu[j] <= en; j++) {
		long long num = sosu[j] * sosu[j];
		for (long long k = (start / num) * num; k <= en; k += num){
			if (start <= k) {
				table[k - start] = true;
			}
		}
	}
	for (long long i = 0; i <= en - start; i++) {
		if (table[i] == false) {
			an++;
		}
	}
	cout << an;
	return 0;
}
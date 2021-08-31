//���� 1929�� �Ҽ� ���ϱ�
//�������׳׽��� ü: �Ҽ��� �ƴ� ���� �� ���� �����ٺ��� ���� � �Ҽ��� ������ ��������.

#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int num[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	memset(num, 1, sizeof(num));
	num[1] = 0;
	cin >> m >> n;
	for (int i = 2; i * i <= n; i++) {
		if (num[i]) {
			for (int j = i * i; j <= n; j += i) {
				num[j] = 0;
			}
		}
	}
	for (int i = m; i <= n; i++) {
		if (num[i]) {
			cout << i << "\n";
		}
	}
	return 0;
}
//백준 1929번 소수 구하기
//에라스토테네스의 체: 소수가 아닌 수는 그 수의 제곱근보다 작은 어떤 소수로 나누어 떨어진다.

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
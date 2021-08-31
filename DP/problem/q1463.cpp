//백준 1463번 1로 만들기
//DP를 활용하자!!

#include <iostream>
#include <cstring>
#define INF 10000000
using namespace std;

int n;
int one[1000005];

int dp(int num) {
	int& ret = one[num];
	if (ret != -1) {
		return ret;
	}
	int ma = INF;
	if (num % 3 == 0) {
		ma = dp(num / 3) + 1;
	}
	if (num % 2 == 0) {
		int a = dp(num / 2) + 1;
		if (ma > a) {
			ma = a;
		}
	}
	int a = dp(num - 1) + 1;
	if (ma > a) {
		ma = a;
	}
	return ret = ma;
}

int main() {
	cin >> n;
	memset(one, -1, sizeof(one));
	one[1] = 0;
	cout << dp(n);
	/*for (int i = 1; i <= n; i++) {
		cout << i << " " <<one[i] << "\n";
	}*/
	return 0;
}
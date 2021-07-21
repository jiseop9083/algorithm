//백준 11051번 이항 계수 2

#include <iostream>
#include <cstring>
using namespace std;

int num[1005][1005];

int dp(int n, int k) {
	int& ret = num[n][k];
	if (ret != -1) {
		return ret;
	}
	return ret = (dp(n -1, k) + dp(n -1, k - 1)) % 10007;
}

int main() {
	int n, k;
	cin >> n >> k;
	memset(num, -1, sizeof(num));
	for (int i = 0; i <= n; i++) {
		num[i][i] = 1;
		num[i][0] = 1;
	}
	cout << dp(n, k);
	return 0;
}

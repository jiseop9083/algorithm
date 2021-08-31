#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


int num[105][105][205];

int dp(int n, int k) {
	if (num[n][k][0] != 0) {
		return num[n][k][0];
	}
	int a = 0;
	int len = max(dp(n - 1, k), dp(n - 1, k - 1));
	for (int i = 1; i <= len; i++) {
		num[n][k][i] = (num[n - 1][k][i] + num[n - 1][k - 1][i] + a) % 10;
		a = (num[n - 1][k][i] + num[n - 1][k - 1][i] + a) / 10;
	}
	if (a != 0) {
		num[n][k][0] = len + 1;
		num[n][k][len + 1] = a;
	}
	else {
		num[n][k][0] = len;
	}
	return num[n][k][0];
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	memset(num, 0, sizeof(num));
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		num[i][0][0] = 1;
		num[i][0][1] = 1;
		num[i][i][0] = 1;
		num[i][i][1] = 1;
	}
	int cnt = dp(n, m);
	for (int i = cnt; i >= 1; i--) {
		cout << num[n][m][i];
	}
	return 0;
}
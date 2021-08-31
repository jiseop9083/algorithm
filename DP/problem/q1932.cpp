#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int table[505][505];
int dis[505][505];

int dp(int y, int x) {
	int& ret = dis[y][x];
	if (ret != -1) {
		return ret;
	}
	if (y < n - 1) {
		ret = max(dp(y + 1, x) + table[y][x], dp(y + 1, x + 1) + table[y][x]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dis, -1, sizeof(dis));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> table[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		dis[n - 1][i] = table[n - 1][i];
	}
	cout << dp(0, 0);
	return 0;
}
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int table[505][505];
int dp[505][505];
int ma = 0;
pair<int, int>start;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1, -1,0,0 };

int panda(int y, int x) {
	int& ret = dp[y][x];
	if (ret != -1) {
		return ret;
	}
	ret = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || xx >= n || yy < 0 || yy >= n) {
			continue;
		}
		if (table[y][x] < table[yy][xx]) {
			ret = max(ret, panda(yy, xx) + 1);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> table[i][j];
			if (ma < table[i][j]) {
				ma = table[i][j];
				start = { i, j };
			}
		}
	}
	dp[start.first][start.second] = 1;
	int an = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			an = max(an, panda(i, j));
		}
	}
	cout << an;
	return 0;
}
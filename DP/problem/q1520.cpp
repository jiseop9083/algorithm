//백준 1520번 내리막 길
//DP를 적절히 사용하자!

#include <iostream>
using namespace std;
int n, m;
int memoi[505][505];
int board[505][505];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0,0 };

int dp(int y, int x) {
	int& ret = memoi[y][x];
	if (ret != -1) {
		return ret;
	}
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		int xx = dx[i] + x;
		int yy = dy[i] + y;
		if (xx < 0 || xx >= n || yy < 0 || yy >= m) {
			continue;
		}
		if (board[y][x] < board[yy][xx]) {
			sum += dp(yy, xx);
		}
	}
	return ret = sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			memoi[i][j] = -1;
		}
	}
	memoi[0][0] = 1;
	cout << dp(m -1, n -1);
	return 0;
}
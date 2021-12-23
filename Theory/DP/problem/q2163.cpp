//백준 2163번 초콜릿 자르기
//수학으로 때려 맞출 수 있지만 DP로 푼다.

#include <iostream>
#include <cstring>
#define INF 100000000
using namespace std;

int n, m;
int board[305][305];

int dp(int a, int b) {
	int& ret = board[a][b];
	int mi = INF;
	if (ret != -1) {
		return ret;
	}
	for (int i = 1; i <= a/ 2; i++) {
		int c = dp(i, b) + dp(a - i, b) + 1;
		if (c < mi) {
			mi = c;
		}
	}
	for (int i = 1; i <= b / 2; i++) {
		int c = dp(a, i) + dp(a, b - i) + 1;
		if (c < mi) {
			mi = c;
		}
	}
	ret = mi;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	memset(board, -1, sizeof(board));
	board[1][1] = 0;
	cin >> n >> m;
	cout << dp(n, m);
	return 0;
}

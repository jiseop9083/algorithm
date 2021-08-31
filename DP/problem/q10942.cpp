//백준 10942번 팰린드롬?

#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int board[2005];
int an[2005][2005];

int dp(int start, int end) {
	int& ret = an[start][end];
	if (ret != -1) {
		return ret;
	}
	int mid = (start + end) / 2;
	for (int i = start; i <= mid; i++) {
		if (board[i] != board[end + start - i]) {
			return ret = 0;
		}
	}
	return ret = 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(an, -1, sizeof(an));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> board[i];
	}
	cin >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << dp(a, b) << "\n";
	}
	return 0;
}
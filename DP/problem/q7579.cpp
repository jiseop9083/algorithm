//백준 7579번 앱
//점화식을 세우자
//번수, 비용 > 용량

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int dp[105][10005];
int memory[105];
int cost[105];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> memory[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	dp[0][0] = 0;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 10001; j++) {
			if (j - cost[i] >= 0) {
				dp[i][j] = max(dp[i-1][j - cost[i]] + memory[i], dp[i-1][j]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	for (int i = 0; i <= 10000; i++) {
		if (dp[n][i] >= m) {
			cout << i;
			break;
		}
	}
	return 0;
}
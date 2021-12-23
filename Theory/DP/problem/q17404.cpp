//백준 17404번 RGB거리 2
//n번째만 특수 처리

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int dp[1005][3][3];
int color[1005][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> color[i][j];
		}
	}

	for (int k = 0; k < 3; k++) {
		for (int j = 0; j < 3; j++) {
			if (k != j) {
				dp[0][j][k] = 10000000;
			}
			else {
				dp[0][j][k] = color[0][j];
			}
			
		}
		
	}
	for (int k = 0; k < 3; k++) {
		for (int i = 1; i < n - 1; i++) {
			dp[i][0][k] = min(dp[i - 1][1][k], dp[i - 1][2][k]) + color[i][0];
			dp[i][1][k] = min(dp[i - 1][0][k], dp[i - 1][2][k]) + color[i][1];
			dp[i][2][k] = min(dp[i - 1][1][k], dp[i - 1][0][k]) + color[i][2];
		}
	}
	int mi = 100000000;
	for (int i = 0; i < 3; i++) {
		if (i != 0) {
			dp[n - 1][0][i] = min(dp[n - 2][1][i], dp[n - 2][2][i]) + color[n - 1][0];
			cout << i <<  " " << 0 << " " << dp[n - 1][0][i] << "\n";
			if (mi > dp[n - 1][0][i]) {
				mi = dp[n - 1][0][i];
				
			}
		}
		if (i != 1) {
			dp[n - 1][1][i] = min(dp[n - 2][0][i], dp[n - 2][2][i]) + color[n - 1][1];
			cout << i <<" " <<  1 << " " << dp[n - 1][1][i] << "\n";
			if (mi > dp[n - 1][1][i]) {
				mi = dp[n - 1][1][i];
			}
		}
		if (i != 2) {
			dp[n - 1][2][i] = min(dp[n - 2][1][i], dp[n - 2][0][i]) + color[n - 1][2];
			cout << i << " " << 2 << " " << dp[n - 1][2][i] << "\n";
			if (mi > dp[n - 1][2][i]) {
				mi = dp[n - 1][2][i];
			}
		}
	}
	cout << mi;
	return 0;
}
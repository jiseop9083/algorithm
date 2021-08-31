//백준 2229번 조짜기
//1차원 DP

#include <iostream>
#include <cstring>
#define INF 10000000
using namespace std;

int n;
int team[1005];
int num[1005];

int dp(int person) {
	int& ret = team[person];
	if (ret != -1) {
		return ret;
	}
	int maxi = 0;
	for (int i = 0; i < person; i++) {
		int ma = -INF; 
		int mi = INF;
		for (int j = i + 1; j <= person; j++) {
			if (num[j] > ma) {
				ma = num[j];
			}
			if (num[j] < mi) {
				mi = num[j];
			}
		}
		int a = dp(i) + ma - mi;
		if (maxi < a) {
			maxi = a;
		}
	}
	return ret = maxi;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(team, -1, sizeof(team));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
	}
	team[0] = 0;
	team[1] = 0;
	cout << dp(n);
	return 0;
}
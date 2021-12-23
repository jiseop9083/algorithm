//백준 14501번 퇴사
//사실 1차원 DP문제인듯

#include <iostream>
using namespace std;

int n;
int money[20];
pair<int, int> sangdam[20];//시간, 금액

int dp(int day) {
	int& ret = money[day];
	if (ret != 0) {
		return ret;
	}
	int ma = 0;
	for (int i = 1; i < day; i++) {
		if (sangdam[i].first + i <= day) {
			int a = dp(i) + sangdam[i].second;
			if (ma < a) {
				ma = a;
			}
		}
	}
	return ret = ma;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		sangdam[i] = { a, b };
		money[i] = 0;
	}
	cout << dp(n + 1);
	return 0;
}

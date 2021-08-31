//백준 3943번 헤일스톤 수열
//메모이제이션을 활용하자!

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int t;
int n;
int number[100005];

int dp(int num) {//답을 리턴
	if (num >= 100000) {
		if (num % 2 == 0) {
			return max(num, dp(num / 2));
		}
		else {
			return max(num, dp((num * 3) + 1));
		}
	}
	int& ret = number[num];
	if (ret != -1) {
		return ret;
	}
	if (num % 2 == 0) {
		return ret = max(num, dp(num/ 2));
	}
	else {
		return ret = max(num, dp((num * 3) + 1));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	memset(number, -1, sizeof(number));
	number[1] = 1;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << dp(n) << "\n";
	}
	return 0;
}
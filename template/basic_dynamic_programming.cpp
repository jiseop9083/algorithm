//기본적인 다이나밍 프로그래밍(동적계획법)
//핵심은 같은 연산을 하지 않는 것이다.
//memoization(메모이제이션)을 적절히 사용하자
//1차원 DP

//기본문제
//백준 1003번 피보나치 함수
//2Xn타일링

//피보나치 함수 문제 풀이
//top -down
#include <iostream>
using namespace std;

pair<int, int> num[45];//0, 1
int t, n;

pair<int, int> dp(int deep) {
	pair<int, int>& ret = num[deep];
	//연산을 했으면 패스
	if (ret.first != -1) {
		return ret;
	}
	return ret = { dp(deep - 1).first + dp(deep - 2).first , dp(deep - 1).second + dp(deep - 2).second };
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	//초기화
	for (int i = 0; i < 42; i++) {
		num[i].first = -1;
		num[i].second = -1;
	}
	num[0] = { 1, 0 };
	num[1] = { 0, 1 };
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << dp(n).first << " " << dp(n).second << "\n";
	}

	return 0;
}
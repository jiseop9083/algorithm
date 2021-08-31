//백준 1904번 01타일
//1차원 DP

#include <iostream>
#include <cstring>
using namespace std;
int n;
int num[1000005];

int dp(int deep) {
	int& ret = num[deep];
	if (ret != -1) {
		return ret;
	}
	return ret = ((dp(deep - 1) + dp(deep - 2)) % 15746);
}

int main() {
	cin >> n;
	memset(num, -1, sizeof(num));
	num[1] = 1;
	num[2] = 2;
	cout << dp(n);
	return 0;
}
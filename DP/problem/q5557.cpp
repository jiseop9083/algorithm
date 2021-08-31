//백준 5557번 1학년
//long long 사용할 것!
//숫자 개수, 부분합 > 답

#include <iostream>
#include <cstring>
using namespace std;

long long sum[105][25];
long long nu[105];
int an;
int n, cnt;

long long dp(int len, int num) {
	long long& ret = sum[len][num];
	if (len == 1) {
		return ret;
	}
	if (ret != 0) {
		return ret;
	}
	long long a = 0;
	if( num + nu[len] <= 20) {
		a += dp(len - 1, num + nu[len]);
	}
	if (num - nu[len] >= 0) {
		a += dp(len - 1, num - nu[len]);
	}
	return ret = a;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= n; i++) {
		cin >> nu[i];
	}
	sum[1][nu[1]] = 1;
	cout << dp(n-1, nu[n]);
	return 0;
}
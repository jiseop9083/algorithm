//세그먼트에서 아이디어를 얻자
//분할정복
#include <iostream>
#include <algorithm>
using namespace std;

int s, e;
int t;
int num[35];

int dp(int start, int end) {
	int cnt = 1;
	for (int i = 1; i < 31; i++, cnt *= 2);//cnt = 2^30
	int ret = 0;
	for (int i = 30; i >= 0; i--) {
		if (start == 1 && end == cnt - 1) {
			return num[i];
		}
		if (start < cnt &&  end >= cnt) {
			ret = max(ret, dp(1, end - cnt + 1) + i);
			end = cnt -1;
		}
		if (start < cnt - 1 && end == cnt - 1) {
			end--;
			ret = max(ret, i);
		}
		if (start == cnt - 1 && end == cnt - 1) {
			return max(ret ,i);
		}
		else if (start >= cnt && end >= cnt) {
			ret = max(ret, dp(start - cnt + 1, end - cnt + 1) + i);
			return ret;
		}
		cnt /= 2;
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	num[0] = 0;
	num[1] = 1;
	for (int i = 2; i < 32; i++) {
		num[i] = num[i - 1] + i - 1;
	}
	for (int i = 0; i < t; i++) {
		cin >> s >> e;
		cout << dp(s, e) << "\n";
	}
	return 0;
}
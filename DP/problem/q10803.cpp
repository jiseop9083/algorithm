#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 987654321
using namespace std;

int n, m;
int square[10005][105];

int dp(int h, int w) {
	int& ret = square[h][w];
	if (ret != -1) {
		return ret;
	}

	if (h % w == 0) {
		ret = h / w -1;
	}
	else if (w % h == 0) {
		ret = w / h - 1;
	}
	else if (h > 3 * w) {
		ret = 1 + dp(h - w, w);
	}
	else if (w > 3 * h) {
		ret = 1 + dp(h, w - h);
	}
	else {
		ret = INF;
		for (int i = 1; i <= h / 2; i++) {
			ret = min(ret, dp(i, w) + dp(h - i, w) + 1);
		}
		for (int i = 1; i <= w / 2; i++) {
			ret = min(ret, dp(h, i) + dp(h, w - i) + 1);
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(square, -1, sizeof(square));
	for (int i = 0; i <= 100; i++) {
		square[i][i] = 0;
	}
	
	cin >> n >> m;
	cout << dp(n, m) + 1;//ÀÚ¸¥ È½¼ö + 1
	return 0;
}
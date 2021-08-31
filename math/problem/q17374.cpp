//백준 17374번 비트베리
//비트와 코인의 차이를 최소화

#include <iostream>
#include <algorithm>
using namespace std;

int t;
int beat, q, a, b, c, d;
int coin;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) {
		coin = 0;
		cin >> beat >> q >> a >> b >> c >> d;
		coin += (q / c) * d;
		int mi = 0;
		if (beat >= coin) {
			int k = (beat - coin) / (a + b);
			coin += b * k;
			beat -= a * k;
			mi = min(coin, beat);
			coin += b;
			beat -= a;
			//cout << coin << " " << beat << "\n";
			if (beat >= 0 && mi < min(coin, beat)) {
				mi = min(coin, beat);
			}
		}
		else {
			int k = (coin - beat) / (a + b);
			coin -= b * k;
			beat += a * k;
			mi = min(coin, beat);
			coin -= b;
			beat += a;
			if (coin >= 0 && mi < min(coin, beat)) {
				mi = min(coin, beat);
			}
		}
		cout << mi << "\n";
	}
	return 0;
}
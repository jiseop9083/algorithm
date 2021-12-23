//백준 11057번 오르막 수
//botton up 연습 > 명확한 점화식이 필요

#include <iostream>
#include <cstring>
using namespace std;

int an[1005][10];
int n;

int main() {
	memset(an, 0, sizeof(an));
	for (int i = 0; i <= 9; i++) {
		an[1][i] = 1;
	}
	
	cin >> n;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				an[i][j] += an[i - 1][k];
			}
			an[i][j] = an[i][j] % 10007;
		}
	}
	int sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += an[n][i];
	}
	cout << sum % 10007;
	return 0;
}
//백준 1793번 타일링
//10진법 배열

#include <iostream>
#include <cstring>
using namespace std;

int n;
int num[255][1001];//0번째는 자리수 표시

int main() {
	memset(num, 0, sizeof(num));
	num[0][0] = 1;
	num[0][1] = 1;
	num[1][0] = 1;
	num[1][1] = 1;
	num[2][0] = 1;
	num[2][1] = 3;
	while (cin >> n) {
		//cout << num[n][1];
		for (int i = 3; i <= n; i++) {
			if (num[i][0] != 0) {
				continue;
			}
			int up = 0;
			num[i][0] = num[i - 1][0];
			for (int j = 1; j <= num[i - 1][0]; j++) {
				num[i][j] = (num[i - 1][j] + (2 * num[i - 2][j]) + up) % 10;
				up = (num[i - 1][j] + (2 * num[i - 2][j]) + up) / 10;
				if (j == num[i - 1][0]) {
					if (up != 0) {
						num[i][j + 1] = up;
						num[i][0]++;
					}
				}
			}
		}
		for (int i = num[n][0]; i >= 1; i--) {
			cout << num[n][i];
		}
		cout << "\n";
	}
	return 0;
}
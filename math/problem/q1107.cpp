//백준 1107번 리모컨

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string n;
int number;
int m;
int num[11];
int an;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n.size(); i++) {
		number = (number * 10) + n[i] - '0';
	}
	an = abs(number - 100);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num[i];
	}
	for (int i = 0; i <= 999999; i++) {
		int check = 0;
		int cnt = 0;
		int b = i;
		bool once = true;
		while (once || b != 0) {
			once = false;
			for (int j = 0; j < m; j++) {
				if (b % 10 == num[j]) {
					check = 1;
					break;
				}
			}
			if (check == 1) {
				break;
			}
			b /= 10;
			cnt++;
		}
		if (check == 0) {
			if (an > abs(number - i) + cnt) {
				an = abs(number - i) + cnt;
			}
		}
	}
	cout << an;
	return 0;
}
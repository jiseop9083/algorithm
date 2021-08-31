//백준 1339번 단어 수학
//대략 10!이면 될듯

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char alpa[11];
int n, cnt;
int an = 0;
string num[11];
int chec[11];
int table[11];

int c = 0;

int find(int i) {
	int sum = 0;
	for (char j : num[i]) {
		for (int k = 0; k < cnt; k++) {
			if (alpa[k] == j) {
				sum = (sum * 10) + chec[k];
				break;
			}
		}
	}
	return sum;
}

void su(int deep) {
	if (deep == cnt) {
		int total = 0;
		for (int i = 0; i < n; i++) {
			total += find(i);
		}
		if (total > an) {
			an = total;
		}
		return;
	}
	for (int i = 9; i >= 0; i--) {
		if (table[i] == -1) {
			chec[deep] = i;
			table[i] = deep;
			su(deep + 1);
			table[i] = -1;
			chec[deep] = -1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	memset(chec, -1, sizeof(chec));
	memset(table, -1, sizeof(table));
	for (int i = 0; i < n; i++) {
		string arr;
		cin >> arr;
		num[i] = arr;
		for (char j : arr) {
			int check = 0;
			for (int k = 0; k < cnt; k++) {
				if (alpa[k] == j) {
					check = 1;
					break;
				}
			}
			if (check == 0) {
				alpa[cnt] = j;
				cnt++;
			}
		}
	}
	su(0);
	cout << an;
	return 0;
}
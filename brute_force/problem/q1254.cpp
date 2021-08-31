//백준 1254번 팰린드롬 만들기

#include <iostream>
#include <string>
using namespace std;

string arr;

int main() {
	cin >> arr;
	int len = arr.size();
	int cnt = len;
	while (cnt <= len * 2) {
		int check = 0;
		for (int i = 0; i <= (cnt - 1) / 2; i++) {
			if (cnt - 1 - i >= len) {
				continue;
			}
			if (arr[i] != arr[cnt - 1 - i]) {
				check = 1;
				break;
			}
		}
		if (check == 0) {
			cout << cnt;
			break;
		}
		cnt++;
	}
	return 0;
}
//백준 10610번 30
//30의 배수: 숫자에 0이 존재하고 수의 합이 3의 배수이어야함

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	string s;
	vector<int>ve;
	cin >> s;
	int sum = 0;
	int zero = 0;
	for (int i = 0; i < s.size(); i++) {
		int num = s[i] - '0';
		if (num == 0) {
			zero = 1;
		}
		sum += num;
		ve.push_back(num);
	}
	if (zero != 1 || sum % 3 != 0) {
		cout << "-1\n";
	}
	else {
		sort(ve.begin(), ve.end(), greater<int>());
		for (int i = 0; i < s.size(); i++) {
			cout << ve[i];
		}
		cout << "\n";
	}
	return 0;
}
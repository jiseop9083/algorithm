//백준 1541번 잃어버린 괄호
//-부터 -가 나올때까지 괄호로 묶기

#include <iostream>
#include <vector>
using namespace std;

int main() {
	string s;
	vector<char>ve;
	cin >> s;
	int total, sum, num;//출력값, 임시저장소, 각 숫자 저장
	total = 0;
	sum = 0;
	num = 0;
	int minus = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+') {
			sum += num;
			num = 0;
		}
		else if (s[i] == '-') {
			sum += num;
			num = 0;
			if (minus == 0) {
				total += sum;
				sum = 0;
			}
			else {
				total -= sum;
				sum = 0;
			}
			minus++;
		}
		else {
			num *= 10;
			num += (s[i] - '0');
		}
	}
	if (minus) {
		sum += num;
		total -= sum;
		sum = 0;
		num = 0;
	}
	else {
		sum += num;
		total += sum;
		sum = 0;
		num = 0;
	}
	cout << total << "\n";
	return 0;
}
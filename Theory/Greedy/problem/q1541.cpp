//���� 1541�� �Ҿ���� ��ȣ
//-���� -�� ���ö����� ��ȣ�� ����

#include <iostream>
#include <vector>
using namespace std;

int main() {
	string s;
	vector<char>ve;
	cin >> s;
	int total, sum, num;//��°�, �ӽ������, �� ���� ����
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
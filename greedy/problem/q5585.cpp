//���� 5585�� �Ž�����
//ū ������ ������.

#include <iostream>
using namespace std;

int main() {
	int money;
	int count = 0;
	cin >> money;
	money = 1000 - money;
	while (money != 0) {
		if (money >= 500) {
			money -= 500;
			count++;
		}
		else if (money >= 100) {
			money -= 100;
			count++;
		}
		else if (money >= 50) {
			money -= 50;
			count++;
		}
		else if (money >= 10) {
			money -= 10;
			count++;
		}
		else if (money >= 5) {
			money -= 5;
			count++;
		}
		else {
			money -= 1;
			count++;
		}
	}
	cout << count << "\n";
	return 0;
}
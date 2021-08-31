//백준 2839번 설탕 배달

#include <iostream>
using namespace std;
int n;

int main() {
	cin >> n;
	for (int i = (n/5); i >= 0; i--) {
		if ((n - (i * 5)) % 3 == 0) {
			cout << i + ((n - (i * 5)) / 3);
			return 0;
		}
	}
	cout << "-1";
	return 0;
}
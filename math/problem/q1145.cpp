//백준 1145번 적어도 대부분의 배수
//1000만

#include <iostream>
#include <algorithm>
using namespace std;

long long num[6];

int main() {
	for (int i = 0; i < 5; i++) {
		cin >> num[i];
	}
	sort(num, num + 5);
	long long mi = 10000000000;
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 4; j++) {
			for (int k = j + 1; k < 5; k++) {
				int a = num[i] * num[j] * num[k];
				for (long long q = num[i]; q <= a; q++) {
					if (q % num[i] == 0 && q % num[j] == 0 && q % num[k] == 0) {
						if (mi > q) {
							mi = q;
						}
					}
				}
			}
		}
	}
	cout << mi;
	return 0;
}
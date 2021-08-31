//백준 1644번 소수의 연속합

#include <iostream>
using namespace std;

int n;
long long sosu[4000005];
long long cnt = 2;
int an = 0;

int main() {
	sosu[0] = 0;
	sosu[1] = 2;
	cin >> n;
	for (long long i = 3; i <= 4000050; i++) {
		int check = 0;
		long long j = 1;
		while((sosu[j] - sosu[j-1]) * (sosu[j] - sosu[j - 1]) <= i && j < cnt){
			if (i % ((sosu[j] - sosu[j - 1])) == 0) {
				check = 1;
				break;
			}
			j++;
		}
		if (check == 0) {
			sosu[cnt] = sosu[cnt -1] + i;
			cnt++;
		}
	}
	int start = 0;
	int end = 1;
	int con = sosu[end] - sosu[end - 1];
	while (end < cnt &&  con <= n) {
		if (sosu[end] - sosu[start] < n) {
			end++;
		}
		else if (sosu[end] - sosu[start] > n) {
			start++;
		}
		else if (sosu[end] - sosu[start] == n) {
			an++;
			end++;
		}
	}
	cout << an;
	return 0;
}
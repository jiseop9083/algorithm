//백준 9506번 약수들의 합
//시간복잡도 n

#include <iostream>
using namespace std;
int n;
int sum;
int num[10005];
int cnt = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	while (n != -1) {
		sum = 1;
		cnt = 0;
		for (int i = 2; i <= n / 2; i++) {
			if (n % i == 0) {
				num[cnt] = i;
				cnt++;
				sum += i;
			}
		}
		if (sum == n) {
			cout << n << " = 1";
			for (int i = 0; i < cnt; i++) {
				cout << " + " << num[i];
			}
			cout << "\n";
		}
		else {
			cout << n << " is NOT perfect.\n";
		}
		cin >> n;
	}
	return 0;
}
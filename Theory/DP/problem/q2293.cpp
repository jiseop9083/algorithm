//백준 2293번 동전
//k번째 동전으로 만들 수 있는 경우의 수

#include <iostream>
#include <cstring>
using namespace std;

int n, k;
int coin[105];
int num[10005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(num, 0, sizeof(num));

	cin >> n >> k;
	num[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
		
	}
	
	for (int i= 0; i < n; i++) {
		
		for (int j = 1; j <= k; j++) {
			if (coin[i] > j) {
				continue;
			}
			num[j] += num[j - coin[i]];
		}
	}
	cout << num[k];
	return 0;
}
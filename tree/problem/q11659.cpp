//백준 11659번 구간 합 구하기4

#include <iostream>
using namespace std;

int n, m;
int sum[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		sum[i] = sum[i - 1] + a;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << "\n";
	}
	return 0;
}
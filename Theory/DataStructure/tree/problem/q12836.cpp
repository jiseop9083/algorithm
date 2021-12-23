//백준 12836번 가계부(Easy)

#include <iostream>
#include <cstring>
using namespace std;

long long day[10005];

int n, q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(day, 0, sizeof(day));
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			day[b] += c;
		}
		else if (a == 2) {
			long long an = 0;
			for (long long j = b; j <= c; j++) {
				an += day[j];
			}
			cout << an << "\n";
		}
	}
	return 0;
}
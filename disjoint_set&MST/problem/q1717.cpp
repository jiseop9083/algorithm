#include <iostream>
using namespace std;

int n, m;

int node[1000006];

int fin(int a) {
	if (a == node[a]) {
		return a;
	}
	return node[a] = fin(node[a]);
}

void sum(int a, int b) {
	int root_a = fin(a);
	int root_b = fin(b);

	node[root_b] = root_a;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		node[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			sum( b,  c);
		}
		else if (a == 1) {
			if (fin(b) == fin(c)) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}
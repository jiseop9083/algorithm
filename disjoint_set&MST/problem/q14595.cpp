#include <iostream>
using namespace std;

int n, m;
int room[1000005];
int an[1000005];

int find(int a) {
	if (a == room[a]) {
		return a;
	}
	return room[a] = find(room[a]);
}

void sum(int a, int b) {
	int root_a = find(a);
	int root_b = find(b);
	for (int i = root_a; i != root_b; i = find(i + 1)) {
		room[i] = root_b;
		an[root_b] += an[i];
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		room[i] = i;
		an[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		sum(x, y);
	}
	int cnt = 0;
	for (int i = n; i >= 1; i--) {
		int nex = an[i];
		i -= (nex - 1);
		cnt++;
	}
	cout << cnt;
	return 0;
}
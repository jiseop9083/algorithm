#include <iostream>
using namespace std;

int n, m;
long long k;
long long stone = 0;
bool gongsa[1000005];
int node[1000005];
int need[1000005];

int find(int a) {
	if (a == node[a]) {
		return a;
	}
	return node[a] = find(node[a]);
}

void sum(int a, int b) {
	int root_a = find(a);
	int root_b = find(b);
	if (need[root_a] < need[root_b]) {
		node[root_b] = root_a;
	}
	else {
		node[root_a] = root_b;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> need[i];
		gongsa[i] = false;
		node[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a ,b;
		cin >> a >> b;
		if (a == n && b == 1) {
			gongsa[a] = true;
		}
		else if (b == n && a == 1) {
			gongsa[b] = true;
		}
		else if (a < b) {
			gongsa[a] = true;
		}
		else {
			gongsa[b] = true;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (gongsa[i] == false) {
			if (i == n) {
				sum(i, 1);
			}
			else {
				sum(i, i + 1);
			}
		}
	}
	if (m > 1) {
		for (int i = 1; i <= n; i++) {
			if (gongsa[i] == true) {
				stone += (long long)need[find(i)];
			}
		}
	}
	if (stone <= k) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}
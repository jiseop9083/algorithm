#include <iostream>
using namespace std;

int n,m;
int node[205];

int find(int a) {
	if (a == node[a]) {
		return a;
	}
	return node[a] = find(node[a]);
}

void sum(int a, int b) {
	int root_a = find(a);
	int root_b = find(b);
	node[root_b] = root_a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n; 
	cin >> m;
	for (int i = 1; i <= n; i++) {
		node[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			if (a == 1) {
				sum(i, j);
			}
		}
	}
	int check ;
	for (int i = 0; i < m; i++) {
		int a; 
		cin >> a;
		if (i == 0) {
			check = find(a);
		}
		else if (check != find(a)) {
			cout << "NO";
			return 0;
		}
	}
	
	cout << "YES";
	return 0;
}
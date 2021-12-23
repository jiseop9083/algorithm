#include <iostream>
using namespace std;

int node[1000005];
int an[1000005];
int n;

int find(int a) {
	if (a == node[a]) {
		return a;
	}
	return node[a] = find(node[a]);
}

void sum(int a, int b) {
	int root_a = find(a);
	int root_b = find(b);
	if (root_a != root_b) {
		an[root_a] += an[root_b];
	}
	node[root_b] = root_a;
	
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= 1000000; i++) {
		node[i] = i;
		an[i] = 1;
	}
	for (int i = 0; i < n; i++) {
		char a;
		int b, c;
		cin >> a;
		if (a == 'I') {
			cin >> b >> c;
			sum(b, c);
		}
		else if (a == 'Q') {
			cin >> b;
			cout << an[find(b)] << "\n";
		}
	}
	return 0;
}
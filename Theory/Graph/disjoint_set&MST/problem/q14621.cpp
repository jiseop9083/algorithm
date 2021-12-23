#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
bool gender[1005];
int node[1005];
int an = 0;
typedef pair<int, pair<int, int>> Edge;
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

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
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		char g;
		cin >> g;
		if (g == 'M') {
			gender[i] = true;
		}
		else {
			gender[i] = false;
		}
		node[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (gender[a] != gender[b]) {
			pq.push({ c, {a,b} });
		}
	}
	while (!pq.empty()) {
		Edge e = pq.top();
		pq.pop();
		if (find(e.second.first) != find(e.second.second)) {
			an += e.first;
			sum(e.second.first, e.second.second);
		}
	}
	int check = find(1);
	for (int i = 2; i <= n; i++) {
		if (check != find(i)) {
			cout << "-1";
			return 0;
		}
	}
	cout << an;
	return 0;
}
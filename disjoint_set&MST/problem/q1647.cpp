#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, pair<int, int>> Edge;
int n, m;
int node[100005];
int an = 0;
int ma = 0;
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
		node[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ c, {a, b} });
	}
	while (!pq.empty()) {
		Edge e = pq.top();
		pq.pop();
		if (find(e.second.first) != find(e.second.second)) {
			sum(e.second.first, e.second.second);
			an += e.first;
			if (e.first > ma) {
				ma = e.first;
			}
		}
	}
	cout << an - ma;
	return 0;
}
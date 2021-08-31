#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, pair<int, int>> edge;//맨앞이 가중치
priority_queue<edge, vector<edge>, greater<edge>>pq;
int node[10005];
int an = 0;
int v, e;

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
	cin >> v >> e;
	for (int i = 1; i <= v; i++) {
		node[i] = i;
	}
	for (int i = 1; i <= e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ c, {a, b} });
	}
	while (!pq.empty()) {
		edge e = pq.top();
		pq.pop();
		if (find(e.second.first) != find(e.second.second)) {
			sum(e.second.first, e.second.second);
			an += e.first;
		}
	}
	cout << an;
	return 0;
}
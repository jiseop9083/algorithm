#include <iostream>
#include <queue>
#include <vector>
using namespace std;

long long an = 0;
pair<int ,int> node[100005];
typedef pair<int, pair<int, int>> Edge;
priority_queue<Edge, vector<Edge>> pq;
int n;

int find(int a) {
	if (a == node[a].second) {
		return a;
	}
	return node[a].second = find(node[a].second);
}

void sum(int a, int b) {
	int root_a = find(a);
	int root_b = find(b);
	if (root_a < root_b) {
		node[root_b].second = root_a;
		node[root_a].first += 1 + node[root_b].first;
	}
	else {
		node[root_a].second = root_b;
		node[root_b].first += 1 + node[root_a].first;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		node[i] = { 0, i };
		int x, y, w;
		cin >> x >> y >> w;
		pq.push({ w, {x, y } });
	}
	node[n] = { 0, n };
	while (!pq.empty()) {
		Edge e = pq.top();
		pq.pop();
		int num1 = find(e.second.first);
		int num2 = find(e.second.second);
		if (num1 != num2) {
			an += (long long)(e.first) * (1 + (long long)(node[num1].first)) * (1 + (long long)(node[num2].first));
			sum(e.second.first, e.second.second);
		}
	}
	cout << an;
	return 0;
}
//백준 1753번 최단경로
//전형적인 다익스트라 알고리즘

#include <iostream>
#include <queue>

#include <climits>
using namespace std;

int t, e;
int k;
int u, v, w;

const int INF = INT_MAX;

const int MAX_V = 20005;
vector<pair<int, int >> edges[MAX_V];
vector<int> dist(MAX_V, INF);
priority_queue<pair<int, int>> pq;

void dijkstra(int start) {
	dist[start] = 0;
	for (auto e : edges[start]) {
		if (dist[e.first] == INF) {
			pq.push({ -e.second, e.first });
		}
	}

	while (!pq.empty()) {
		int now, nowdist;
		nowdist = -pq.top().first;
		now = pq.top().second;
		pq.pop();

		if (dist[now] != INF)
			continue;

		dist[now] = nowdist;

		for (auto e : edges[now]) {
			if (dist[e.first] == INF) {
				pq.push({ -(nowdist + e.second ), e.first});
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t >> e;
	cin >> k;
	for (int i = 1; i <= e; i++) {
		cin >> u >> v >> w;
		edges[u].push_back({ v,w });
	}
	dijkstra(k);

	for (int i = 1; i <= t; v++) {
		if (dist[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}

	return 0;
}
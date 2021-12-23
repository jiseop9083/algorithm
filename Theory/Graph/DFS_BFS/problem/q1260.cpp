//백준 1260번 DFS와 BFS
//DFS: 깊이 우선 탐색 > 재귀함수 이용
//BFS: 너비 우선 탐색 > 큐를 이용
//이차원 배열을 이용해보자!

#include <iostream>
#include <queue>

using namespace std;
int visit_dfs[1005] = {0,};
int visit_bfs[1005] = { 0, };
int edge[1005][1005] = { {0,}, };
int n, m, v;

void dfs(int x) {
	visit_dfs[x] = 1;
	cout << x << " ";
	for (int i = 1; i <= n; i++) {
		if (edge[x][i] && !visit_dfs[i]) {
			dfs(i);
		}
	}
}

void bfs() {
	queue<int>q;
	q.push(v);
	visit_bfs[v] = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << " ";
		for (int i = 1; i <= n; i++) {
			if (edge[now][i] && !visit_bfs[i]) {
				q.push(i);
				visit_bfs[i] = 1;
			}
		}
	}
}

int main() {

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		edge[s][e] = 1;
		edge[e][s] = 1;
	}
	dfs(v);
	cout << "\n";
	bfs();
	return 0;
}
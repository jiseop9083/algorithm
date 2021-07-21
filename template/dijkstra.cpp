//다익스트라
//최단경로구하기
//최댓값을 리턴하는 우선순위 큐를 이용하여 구현한다


//기본 문제
//백준 1753번 최단경로
//백준 1238번 파티

#include <iostream>
#include <vector>
#include <queue>
#define INF 2000000000
using namespace std;

int node[1005];
//간선 정보
vector<pair<int, int>> ve[1005];
//가중치, 현재 경로
priority_queue<pair<int, int>> pq;
//정점 개수
int n;

void dij() {
	while (!pq.empty()) {
		int dis = -pq.top().first;
		int con = pq.top().second;
		pq.pop();
		for (pair<int, int> i : ve[con]) {
			int cost = i.first + dis;
			int next = i.second;
			if (cost < node[next]) {
				node[next] = cost;
				pq.push({ -cost, next });
			}
		}
	}
}

int main() {
	//간선정보 입력 받기

	for (int i = 1; i <= n; i++) {
		int a, b,c;
		cin >> a >>b >> c;
		ve[a].push_back({ c, b });
		//정점 초기화
		node[i] = INF;
	}
	//시작점 입력
	pq.push({ 0,1 });
	return 0;
}

int edge[105][105];

int floyd_warshall() {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			edge[i][j] = INF;
			if (i == j) edge[i][j] = 0;
		}
	}
	//입력받기
	int a, b, c; cin >> a >> b >> c;
	if (edge[a][b] > c) {
		edge[a][b] = c;
	}
	for (int mid = 1; mid <= n; mid++) {
		for (int start = 1; start <= n; start++) {
			for (int end = 1; end <= n; end++) {
				if (start == end || mid == start || mid == end) {
					continue;
				}
				if (edge[start][end] > edge[start][mid] + edge[mid][end]) {
					edge[start][end] = edge[start][mid] + edge[mid][end];
				}
			}
		}
	}
}
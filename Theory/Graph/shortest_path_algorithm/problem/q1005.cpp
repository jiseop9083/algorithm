//백준 1005번 ACM Craft
//최소 시간을 구하는 전형적인 다익스트라 알고리즘
//건설 끝나는 시간 기준으로 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;// t테스트개수, n건물 개수, k 건설순서 규칙 개수
int t;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k;
		int dist[1005];//이동거리
		vector<int> edge[1005];//시작지점, 도착지점
		vector<int> r_edge[1005];//도착지점, 시작지점
		priority_queue<pair<int, int>> pq;//거리, 정점

		cin >> n >> k;
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			dist[j] = a;
		}
		for (int j = 0; j < k; j++) {
			int a, b;
			cin >> a >> b;
			r_edge[b].push_back(a);
			edge[a].push_back(b);
		}
		int a;
		cin >> a;
		int min = 100000000000;
		for (int i = 1; i <= n; i++) {
			if (r_edge[i].empty()) {
				if (a == i) {
					min = dist[i];
					break;
				}
				pq.push({ dist[i], i });

				while (!pq.empty()) {
					int now, nowdist;
					nowdist = pq.top().first;
					now = pq.top().second;
					if (now == a) { //&& min < pq.top().first) {
						if(min > nowdist) min = nowdist;
						//cout << nowdist << "\n";
						while (!pq.empty()) pq.pop();
						break;
					}
					pq.pop();
					for (auto e : edge[now]) {
						pq.push({ (nowdist + dist[e]), e });
					}
				}
			}
				
		}
		cout << min << "\n";
		
	}
	return 0;
}

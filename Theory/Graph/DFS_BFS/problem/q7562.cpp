#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dy[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int t, n;
int x1, x2, y1, y2;
queue <pair<int, int>> q[1000];

int visit[305][305];

int bfs() {
	int cnt = 0;
	while (!q[cnt].empty()) {
		while (!q[cnt].empty()) {
			int x = q[cnt].front().first;
			int y = q[cnt].front().second;
			if (x == x2 && y == y2) {
				return cnt;
			}
			for (int i = 0; i < 8; i++) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx < 0 || yy < 0 || xx >= n || yy >= n) {
					continue;
				}
				if (visit[yy][xx] == 0) {
					visit[yy][xx] = 1;
					q[cnt + 1].push({ xx, yy });
				}
			}
		}
		cnt++;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		memset(visit, 0, sizeof(visit));
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		q[0].push({ x1, y1 });
		cout << bfs() << "\n";
	}
	return 0;
}
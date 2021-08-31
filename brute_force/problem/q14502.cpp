//백준 14502번 연구소
//dfs와 브루트 포스를 이용해 풀어보자!

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int table[10][10];
int visit[10][10];
int dx[4] = { 0,0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int ma = 0;
queue <pair<int, int>> q;
vector <pair<int, int>> save;
vector <pair<int, int>> ve;


void bfs() {
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		visit[y][x] = 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx < 0 || xx >= m || yy < 0 || yy >= n) {
				continue;
			}
			else if (table[yy][xx] == 0 && visit[yy][xx] != 1) {
				q.push({ yy,xx });
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (table[i][j] == 0 && visit[i][j] == 0) {
				
				sum++;
			}
			visit[i][j] = 0;
		}
	}
	if (ma < sum) {
		ma = sum;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cin >> n >> m;//세로, 가로
	ve.reserve(n * m);
	save.reserve(n * m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visit[i][j] = 0;
			cin >> table[i][j];
			if (table[i][j] == 2) {
				save.push_back({ i, j });//y,x
			}
			else if (table[i][j] == 0) {
				ve.push_back({ i, j });
			}
		}
	}
	int s = ve.size();
	for (int i = 0; i < s - 2; i++) {
		for (int j = i + 1; j < s - 1; j++) {
			for (int k = j + 1; k < s; k++) {
				table[ve[i].first][ve[i].second] = 1;
				table[ve[j].first][ve[j].second] = 1;
				table[ve[k].first][ve[k].second] = 1;
				for (int p = 0; p < save.size(); p++) {
					q.push({ save[p].first, save[p].second});
				}
				bfs();
				table[ve[i].first][ve[i].second] = 0;
				table[ve[j].first][ve[j].second] = 0;
				table[ve[k].first][ve[k].second] = 0;
			}
		}
	}
	cout << ma;
	return 0;
}
//백준 4991번 로봇 청소기
//위치, 쓰레기 번호 > 최소이동거리

#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

int w, h;
int board[21][21];
int dis[21][21][2050];//y, x, num
int visit[21][21][2050];//y, x, num > 이동거리
queue <pair<int,pair<int, int>>> q;
string arr;
int cnt;
int dx[4] = { 0,0, 1,-1 };
int dy[4] = { 1, -1, 0, 0 };

void bfs() {
	while (!q.empty()) {
		int y = q.front().second.first;
		int x = q.front().second.second;
		int num = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (xx >= w || xx < 0 || yy < 0 || yy >= h || visit[yy][xx][num]) {
				continue;
			}
			if (board[yy][xx] == -1) {
				continue;
			}
			else if (board[yy][xx] > 0) {
				if ((num / board[yy][xx]) % 2 == 0) {
					q.push({ num + board[yy][xx], {yy,xx} });
					visit[yy][xx][num + board[yy][xx]] = visit[y][x][num] + 1;
				}
				if (num + board[yy][xx] == cnt - 1) {
					while (!q.empty()) {
						q.pop();
					}
					cout << visit[yy][xx][num + board[yy][xx]] << "\n";
					return;
				}
			}
			visit[yy][xx][num] = visit[y][x][num] + 1;
			q.push({ num, {yy,xx} });
		}
	}
	cout << "-1\n";
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> w >> h;
	while (w != 0 && h != 0) {
		memset(visit, 0, sizeof(visit));
		memset(board, 0, sizeof(board));
		cnt = 1;
		for (int i = 0; i < h; i++) {
			cin >> arr;
			for (int j = 0; j < w; j++) {
				if (arr[j] == 'x') {
					board[i][j] = -1;
				}
				else if (arr[j] == '*') {
					board[i][j] = cnt;
					cnt *= 2;
				}
				else if (arr[j] == 'o') {
					q.push({ 0, {i, j} });
				}
			}
		}
		bfs();
		cin >> w >> h;
	}
}
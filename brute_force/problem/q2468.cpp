//백준 2468번 안전 영역

#include <iostream>
using namespace std;

int n;
int board[105][105];
bool water[105][105];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1,-1, 0, 0 };
int an = 0;


void dfs(int y, int x) {
	water[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i];
		int xx = x + dx[i];
		if (xx < 0 || xx >= n || yy < 0 || yy >= n) {
			continue;
		}
		if (water[yy][xx] == false) {
			dfs(yy, xx);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int ma = 0;
	int mi = 1000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (ma < board[i][j]) {
				ma = board[i][j];
			}
			if (mi > board[i][j]) {
				mi = board[i][j];
			}
		}
	}
	for(int k = mi -1; k <= ma; k++) {
		int area = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (k >= board[i][j]) {
					water[i][j] = true;
				}
				else {
					water[i][j] = false;
				}
			}
		}


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (water[i][j] == false) {
					dfs(i ,j);
					area++;
				}
			}
		}
		if (area > an) {
			an = area;
		}
	}
	cout << an;
	return 0;
}
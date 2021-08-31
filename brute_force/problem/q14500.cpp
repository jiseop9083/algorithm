//백준 14500번 테트로미노
//백트랙킹같은 브루트 포스
 
#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int table[505][505];
bool visit[505][505];
int an = 0;

void back(int deep, int sum, int y, int x) {
	if (deep == 4) {
		if (an < sum) {
			an = sum;
		}
		return;
	}
	if (deep == 0) {
		for (int i = 0; i < 4; i++) {
			int check = 0;
			int su = table[y][x];
			for (int j = 0; j < 4; j++) {
				if (j == i) {
					continue;
				}
				int xx = x + dx[j];
				int yy = y + dy[j];
				if (xx < 0 || xx >= m || yy < 0 || yy >= n) {
					check = 1;
					break;
				}
				su += table[yy][xx];
			}
			if (check == 0 && an < su) {
				an = su;
			}
		}
	}
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || xx >= m || yy < 0 || yy >= n || visit[yy][xx] == true) {
			continue;
		}
		
		back(deep + 1, sum + table[y][x], yy, xx);
		
	}
	visit[y][x] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(visit, false, sizeof(visit));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> table[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			back(0, 0, i ,j);
		}
	}
	cout << an;
	return 0;
}
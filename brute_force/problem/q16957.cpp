//백준 16957번 체스판 위의 공
//백트랙킹, 브루트포스

#include <iostream>
#include <cstring>
using namespace std;

int r, c;
int dx[8] = { 0, 0, 1,-1, 1, 1, -1,-1 };
int dy[8] = { 1,-1, 0, 0, 1, -1, 1,-1 };
pair<int, int> pos[505][505];
int an[505][505];
int table[505][505];

pair<int ,int> move(int y, int x) {
	pair<int, int>& ret = pos[y][x];
	if (ret.first != -1) {
		return ret;
	}
	int check = 0;
	int nextX = x;
	int nextY = y;
	for (int i = 0; i < 8; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || xx >= c || yy < 0 || yy >= r) {
			continue;
		}
		if (table[nextY][nextX] > table[yy][xx]) {
			check = 1;
			nextY = yy;
			nextX = xx;
		}
	}
	if (check == 0) {
		return ret = { y, x };
	}
	else {
		return ret = move(nextY, nextX);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(an, 0, sizeof(an));
	memset(pos, -1, sizeof(pos));
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> table[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			pair<int, int> p = move(i, j);
			an[p.first][p.second]++;
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << an[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

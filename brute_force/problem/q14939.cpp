//백준 14939번 불 끄기

#include <iostream>
#define INF 1000000
using namespace std;

int board[11][11];
int co[11][11];
int dx[5] = { 0,0,0,1,-1 };
int dy[5] = { 0,1,-1,0,0 };
int an = INF;

void trans(int y, int x, bool type) {
	for (int i = 0; i < 5; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx < 0 || xx >= 10 || yy < 0 || yy >= 10) {
			continue;
		}
		if (type == true) {
			board[yy][xx] = (board[yy][xx] + 1) % 2;
		}
		else {
			co[yy][xx] = (co[yy][xx] + 1) % 2;
		}
	}
}

void off(int deep, int sum) {
	if (deep == 10) {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				co[i][j] = board[i][j];
			}
		}
		for (int i = 1; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (co[i - 1][j] == 1) {
					sum++;
					trans(i, j, false);
				}
			}
		}
		int check = 0;
		for (int i = 0; i < 10; i++) {
			if (co[9][i] == 1) {
				check = 1;
				break;
			}
		}
		if (check == 0 && an > sum) {
			an = sum;
		}
		return;
	}
	trans(0, deep, true);
	off(deep + 1, sum + 1);
	trans(0, deep, true);
	off(deep + 1, sum);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			char a;
			cin >> a;
			if (a == '#') {
				board[i][j] = 0;
			}
			else {
				board[i][j] = 1;
			}
		}
	}
	off(0, 0);
	if (an == INF) {
		cout << "-1";
	}
	else {
		cout << an;
	}
	return 0;
}
//백준 14927번 전구 

#include <iostream>
#include <algorithm>
#define INF 1000
using namespace std;

int n;
int board[20][20];
int an = INF;
int dx[5] = { 0,1, -1, 0,0 };
int dy[5] = { 0,0,0,1,-1 };

//전구 누르기
void trans(int y, int x) {
	for (int i = 0; i < 5; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (yy < 0 || yy >= n || xx < 0 || xx >= n) {
			continue;
		}
		board[yy][xx] = (board[yy][xx] + 1) % 2;
	}
}

void solve(int deep, int num) {
	//전구를 모두 끌 수 있는지 검사
	if (deep == n) {
		//검사전 복사하기
		int cop[20][20];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cop[i][j] = board[i][j];
			}
		}
		//[i-1][j]가 켜져 있으면 [i][j]누르기
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (cop[i - 1][j] == 1) {
					num++;
					for (int k = 0; k < 5; k++) {
						if (i + dy[k] >= n || i + dy[k] < 0 || j + dx[k] < 0 || j + dx[k] >= n) {
							continue;
						}
						cop[i + dy[k]][j + dx[k]] = (1 + cop[i + dy[k]][j + dx[k]]) % 2;
					}
				}
			}
		}
		//마지막 행 전부 꺼져있는지 확인
		bool check = true;
		for (int i = 0; i < n; i++) {
			if (cop[n - 1][i] == 1) {
				check = false;
				break;
			}
		}
		if (check == true) {
			an = min(an, num);
		}
		return;
	}
	trans(0, deep);
	//누른다
	solve(deep + 1, num + 1);
	trans(0, deep);
	//안누른다
	solve(deep + 1, num);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	solve(0,0);
	//없을 때
	if (an == INF) {
		cout << "-1";
	}
	else {
		cout << an;
	}
	return 0;
}

#include <iostream>
#include <cstring>
#include <string>
#define INF 987654321
using namespace std;

int n, m;
int board[55][55];
int visit[55][55];
int num[55][55];
int dx[4] = { 1, -1, 0,0 };
int dy[4] = { 0,0,1,-1 };
bool infi = false;

int dp(int y, int x) {
	int& ret = num[y][x];
	if (visit[y][x] == 1) {
		infi = true;
		return -1;
	}
	if (ret != -1) {
		return ret;
	}
	visit[y][x] = 1;
	int an = -1;
	for (int i = 0; i < 4; i++) {
		int yy = y + (board[y][x] * dy[i]);
		int xx = x + (board[y][x] * dx[i]);
		if (yy >= n || yy < 0 || xx >= m || xx < 0 || board[yy][xx] == -1) {
			an = max(an, 1);
			continue;
		}
		if (an < dp(yy, xx) + 1) {
			an = dp(yy, xx) + 1;
		}
	}
	visit[y][x] = 0;
	return ret = an;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(visit, 0, sizeof(visit));
	memset(num, -1, sizeof(num));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string arr; cin >> arr;
		for (int j = 0; j < arr.size(); j++) {
			if (arr[j] == 'H') {
				board[i][j] = -1;
			}
			else 
				board[i][j] = (int)(arr[j] - '0');
		}
	}
	int an = dp(0, 0);
	if (infi == true) {
		cout << "-1";
	}
	else {
		cout << an;
	}	
	return 0;
}
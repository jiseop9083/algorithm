//���� 2169�� �κ� �����ϱ�
//��, ���� ,���������� �̵�
//DP�� �ٽ� Ȱ������

#include <iostream>
#include <string.h>
#define INF 9000
using namespace std;

int n, m;
int board[1005][1005][3];
int num[1005][1005];
int check[1005][1005];
int dx[3] = { -1, 0, 1 };
int dy[3] = { 0, -1, 0 };

int dp(int y, int x, int di) {//��ǥ, ����
	int &ret = board[y][x][di];
	if (ret != -INF) {
		return ret;
	}
	for (int i = 0; i < 3; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (yy < 1 || yy > n || xx < 1 || xx > m ) {
			continue;
		}
		if (check[yy][xx] == 1 ) {
			continue;
		}
		check[yy][xx] = 1;
		int a = dp(yy, xx, i);
		check[yy][xx] = 0;
		/*if (a == -INF) {
			continue;
		}*/
		if (ret < a + num[y][x]) {
			ret = a + num[y][x];
		}
		
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	memset(num, 0, sizeof(num));
	memset(check, 0, sizeof(check));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> num[i][j];
			for (int k = 0; k < 3; k++) {
				board[i][j][k] = -INF;
			}
			
		}
	}
	board[1][1][0] = num[1][1];
	board[1][1][1] = num[1][1];
	board[1][1][2] = num[1][1];
	check[n][m] = 1;
	cout << dp(n, m, 0) << "\n";


	/*for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}*/
	return 0;
}
//백준 2449번 전구
//이차원 DP 시작점, 끝점> 이동횟수 최솟값
//가장 왼쪽의 색으로 정렬하자!

#include <iostream>
#include <cstring>
#define INF 10000
using namespace std;

int n, k;
int num[205];
int board[205][205];
int cnt = 0;

int dp(int start, int end) {
	int& ret = board[start][end];
	if (start == end) {
		return ret = 0;
	}
	if (ret != -1) {
		return ret;
	}
	int mi = INF;
	for (int i = start; i < end; i++) {
		int a = dp(start, i) + dp(i + 1, end);
		if (num[start] != num[i + 1]) {
			a++;
			//cout << start << " " << i + 1 << " " << end << "\n";
		}
		if (a < mi) {
			mi = a;
			
		}
		
	}
	return ret = mi;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(board, -1, sizeof(board));
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> num[cnt];
		if (i == 0 || num[cnt - 1] != num[cnt]) {
			cnt++;
		}
	}
	cout << dp(0, cnt - 1);
	return 0;
}
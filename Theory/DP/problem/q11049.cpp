//백준 11049번 행렬 곱셈 순서
//시작 위치, 끝위치
#include <iostream>
#include <cstring>
#include <algorithm>
#define INF 2147483647
using namespace std;

int n;
int table[505][505];
pair<int, int> matrix[505];

int dp(int start, int end) {
	int& ret = table[start][end];
	if (ret != -1) {
		return ret;
	}
	int mi = INF;
	for (int i = start; i < end; i++) {
		int a = dp(start, i) + dp(i+1, end) + (matrix[start].first * matrix[i].second * matrix[end].second);
		if (mi > a) {
			mi = a;
		}
	}
	return ret = mi;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(table, -1, sizeof(table));
	cin >> n;
	for (int i = 0; i < n; i++) {
		int r, c;
		cin >> r >> c;
		matrix[i] = { r, c };
		table[i][i] = 0;
	}
	cout << dp(0, n - 1);
	return 0;

}
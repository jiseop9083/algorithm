//백준 1693번 트리 색칠하기

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define INF 987654321
using namespace std;
int  n;
int dp[100005][20];
vector<int> ve[100005];
int visit[100005];

int dfs(int x, int c) {
	int& ret = dp[x][c];
	if (ret != -1)
		return ret;

	visit[x] =1;
	ret = 0;
	int cnt = 0;
	for (int i : ve[x]) {
		if (visit[i] == 1)
			continue;
		cnt++;
	}
	if (cnt == 0) {
		visit[x] = 0;
		return ret = c;
	}
	for (int i : ve[x]) {
		if (visit[i] == 1)
			continue;
		int mi = INF;
		for (int j = 1; j <= 18; j++) {
			if (j == c)
				continue;
			mi = min(mi, dfs(i, j));
		}
		ret += mi;
	}
	ret += c;
	visit[x] = 0;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	memset(dp, -1, sizeof(dp));
	memset(visit, 0, sizeof(visit));
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		ve[a].push_back(b);
		ve[b].push_back(a);
	}
	int answer = INF;
	for (int i = 1; i <= 18; i++) {
		answer = min(answer, dfs(1, i));
	}
	cout << answer;
	return 0;
}

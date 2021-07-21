//백준 2533번 사회망 서비스(

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int  n;
pair<int, int> an[1000005];
vector<int>ve[1000005];
int visit[1000005];

pair<int, int> dfs(int x) {
	pair<int, int>& ret = an[x];
	if (ret.first != -1) {
		return ret;
	}
	visit[x] = 1;
	if (ve[x].empty()) {
		return ret = { 1, 0 };
	}
	ret = { 0,0 };
	for (int i : ve[x]) {
		if (visit[i] == 1)
			continue;
		pair<int, int> a = dfs(i);
		ret.first += min(a.first, a.second);
		ret.second += a.first;
	}
	ret.first++;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(an, -1, sizeof(an));
	memset(visit, 0, sizeof(visit));
	cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		ve[a].push_back(b);
		ve[b].push_back(a);
	}
	pair<int, int> answer = dfs(1);
	cout << min(answer.first, answer.second);
	return 0;
}

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> ve[2005];
int n, m;
int an = 0;
int visit[2005];
int edge[1005];

int dfs(int x) {
	visit[x] = 1;
	for (int i : ve[x]) {
		if (visit[edge[i]])
			continue;
		if (edge[i] == 0 || dfs(edge[i])) {
			edge[i] = x;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(edge, 0, sizeof(edge));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int cnt; cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int a; cin >> a;
			ve[i].push_back(a);
			ve[i + n].push_back(a);
		}
	}
	for (int i = 1; i <= n * 2; i++) {
		memset(visit, 0, sizeof(visit));
		dfs(i);
	}
	for (int i = 1; i <= m; i++) {
		if (edge[i] != 0) {
			an++;
		}
	}
	cout << an;
	return 0;
}
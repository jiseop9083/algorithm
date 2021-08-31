#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> ve[1005];
int n, m;
int edge[1005];
int visit[1005];

int dfs(int start) {
	visit[start] = 1;
	for (int i : ve[start]) {
		if (visit[edge[i]]) {
			continue;
		}
		if (edge[i] == 0 || dfs(edge[i])) {
			edge[i] = start;
			return 1;
		}
			
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	memset(edge, 0, sizeof(edge));
	for (int i = 1; i <= n; i++) {
		int cnt; cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int a; cin >> a;
			ve[i].push_back(a);
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		dfs(i);
	}
	int an = 0;
	for (int i = 0; i <= m; i++) {
		//cout << i << " " << edge[i] << "\n";
		if (edge[i] != 0) {
			an++;

		}
	}
	cout << an;
	return 0;
}
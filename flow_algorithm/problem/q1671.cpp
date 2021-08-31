#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int dat[55][3];
vector<int> ve[105];
int visit[105];
int edge[105];
int n;

int dfs(int x) {
	visit[x] = 1;
	for (int i : ve[x]) {
		if (visit[edge[i]])
			continue;
		int st, en;
		st = x % n;
		en = i % n;
		if (x == n || x == 2 * n) {
			st = n;
		}
		if (i == n || i == 2 * n) {
			en = n;
		}
		if (edge[st] == en)
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
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c; cin >> a >> b >> c;
		dat[i][0] = a;
		dat[i][1] = b;
		dat[i][2] = c;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			if (dat[i][0] >= dat[j][0] && dat[i][1] >= dat[j][1] && dat[i][2] >= dat[j][2]) {
				ve[i].push_back(j);
				ve[i + n].push_back(j);
			}
		}
	}
	for (int i = 1; i <= n * 2; i++) {
		memset(visit, 0, sizeof(visit));
		dfs(i);
	}
	int an = 0;
	for (int i = 1; i <= n; i++) {
		//cout << i << " " << edge[i] << "\n";
		if (edge[i] != 0) {
			an++;
		}
	}
	if (n - an == 0) {
		cout << "1";
	}
	else {
		cout << n - an;
	}
	
	return 0;
}
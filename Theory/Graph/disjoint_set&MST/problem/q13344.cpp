#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> ve[50005];
int node[50005];
bool an = true;

int find(int a) {
	if (a == node[a]) {
		return a;
	}
	return node[a] = find(node[a]);
}

void sum(int a, int b) {
	int root_a = find(a);
	int root_b = find(b);
	node[root_b] = root_a;
}

int check_equal(int a, int b) {
	if (find(a) == find(b)) {
		return 1;
	}
	return 0;
}

int check_big(int a, int b, int deep) {//a > b 검사
	if (find(a) == find(b)) {
		return deep;
	}
	if (!ve[find(b)].empty()) {
		return check_big(find(a), find(ve[find(b)][0]), deep + 1);
	}
	return 0;
}

int check_small(int a, int b, int deep) {//a < b 검사
	if (find(a) == find(b)) {
		return deep;
	}
	if (!ve[find(a)].empty()) {
		return check_small(find(b), find(ve[find(a)][0]), deep + 1);
	}
	else {
		return 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		node[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, c;
		char b;
		cin >> a >> b >> c;
		if (b == '=') {
			if (check_big(a, c, 1) != 0 || check_small(a, c, 1) != 0) {
				an = false;
				break;
			}
			sum(a, c);
		}	
		else if (b == '>') {
			if (check_small(a, c, 1) != 0) {
				an = false;
				break;
			}
			ve[c].push_back(a);
		}
		else if (b == '<') {
			if (check_big(a, c, 1) != 0) {
				an = false;
				break;
			}
			ve[a].push_back(c);
		}
	}
	if (an == true) {
		cout << "consistent";
	}
	else {
		cout << "inconsistent";
	}
	return 0;
}
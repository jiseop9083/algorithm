//백준 2357번 최솟값과 최댓값
//세그먼트 트리의 응용

#include <iostream>
#include <algorithm>
#define INF 1000000005
using namespace std;

int n, m;
int table[100005];
pair<int, int> tree[262500];//min, max

pair<int, int> init(int index, int start, int end) {
	if (start == end) {
		tree[index] = { table[start], table[start] };
	}
	else {
		int mid = (start + end) / 2;
		pair <int, int > a = init((index * 2) + 1, start, mid);
		pair <int, int > b = init((index * 2) + 2, mid + 1, end);
		tree[index] = { min(a.first, b.first), max(a.second, b.second) };
	}
	return tree[index];
}

pair<int, int> find(int index, int start, int end, int left, int right) {
	if (start > right || end < left) {
		return { INF, -INF };
	}
	else if (left <= start && end <= right) {
		return tree[index];
	}
	else {

		int mid = (start + end) / 2;
		pair <int, int> a = find((index * 2) + 1, start, mid, left, right);
		pair <int, int> b = find((index * 2) + 2, mid + 1, end, left, right);
		return { min(a.first, b.first), max(a.second, b.second) };
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> table[i];
	}
	init(0, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		pair<int, int> an = find(0, 0, n - 1, a - 1, b - 1);
		cout << an.first << " " << an.second << "\n";
	}
	return 0;
}
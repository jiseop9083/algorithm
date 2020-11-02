//백준 2042번 구간 합 구하기

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int n, m, k;

class Segtree {
public:
	int size;
	vector<ll> tree;

	Segtree(int t) {
		for (size = 1; size < t; size *= 2);
		tree.resize(2 * size);
	}

	void update(int pos, ll diff) {
		int index = size + pos - 1;
		diff = diff - tree[index];
		while (index) {
			tree[index] += diff;
			index /= 2;
		}
	}

	ll sum(int pos, int start, int end, int left, int right) {
		if (start > right || end < left) {
			return 0;
		}
		else if(left <= start && end <= right) {
			return tree[pos];
		}
		else {
			int mid = (start + end) / 2;
			return sum(pos * 2, start, mid, left, right) + sum(pos * 2 + 1, mid + 1, end, left, right);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	Segtree tree(n);
	for (int i = 1; i <= n; i++) {
		ll a; cin >> a;
		tree.update(i, a);
	}
	for (int i = 0; i < m + k; i++) {
		int a; cin >> a;
		if (a == 1) {
			int b;
			ll c;
			cin >> b >> c;
			tree.update(b, c);
		}
		else if (a == 2) {
			int b, c;
			cin >> b >> c;
			cout << tree.sum(1, 1, tree.size, b, c) << "\n";
		}
	}
	return 0;
}

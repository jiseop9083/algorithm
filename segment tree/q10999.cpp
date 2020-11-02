//백준 10999번 구간 합 구하기 2

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

class Seglazy {
public:
	int size;
	vector<ll>tree;
	vector<ll>lazy;

	Seglazy(int t) {
		for (size = 1; size < t; size *= 2);
		tree.resize(size * 2);
		lazy.resize(size * 2);
	}

	void propagation(int pos, int start, int end) {
		if (lazy[pos] != 0) {
			tree[pos] += ((ll)end - (ll)start + 1) * lazy[pos];
			if (start != end) {
				lazy[pos * 2] += lazy[pos];
				lazy[pos * 2 + 1] += lazy[pos];
			}
			lazy[pos] = 0;
		}
	}
	void update(int pos, int start, int end, int left, int right, ll diff) {
		propagation(pos, start, end);
		if (start > right || end < left) {
			return;
		}
		else if (left <= start && end <= right) {
			lazy[pos] += diff;
			propagation(pos, start, end);
		}
		else {
			int mid = (start + end) / 2;
			update(pos * 2, start, mid, left, right, diff);
			update(pos * 2 + 1, mid + 1, end, left, right, diff);
			tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
		}
	}

	ll sum(int pos, int start, int end, int left, int right) {
		propagation(pos, start, end);
		if (start > right || end < left) {
			return 0;
		}
		else if (left <= start && end <= right) {
			return tree[pos];
		}
		else {
			int mid = (start + end) / 2;
			return sum(pos * 2, start, mid, left, right) + sum(pos * 2 + 1, mid + 1, end, left, right);
		}
	}
	
};

int n, m, k;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	Seglazy tree(n);
	for (int i = 1; i <= n; i++) {
		ll a; cin >> a;
		tree.update(1, 1, tree.size, i, i, a);
	}
	for (int i = 0; i < m + k; i++) {
		int a; cin >> a;
		if (a == 1) {
			int b, c;
			ll d;
			cin >> b >> c >> d;
			tree.update(1, 1, tree.size, b, c, d);
		}
		else if (a == 2) {
			int b, c;
			cin >> b >> c;
			cout << tree.sum(1, 1, tree.size, b, c)<< "\n"; 
		}
	}
	return 0;
}

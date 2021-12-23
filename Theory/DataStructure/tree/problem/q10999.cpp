//백준 10999번 구간 합 구하기2
//lazy propagation

#include <iostream>
#include <cstring>
using namespace std;

int n, m, k;
long long tree[2100000];
long long lazy[2100000];
long long table[1000005];


void propagate(int index, int start, int end) {
	if (lazy[index] == 0) {
		return;
	}
	tree[index] += (long long)(end - start + 1) * lazy[index];
	if (start != end) {
		lazy[index * 2 + 1] += lazy[index];
		lazy[index * 2 + 2] += lazy[index];
	}
	lazy[index] = 0;
}

long long init(int index, int start, int end) {
	if (start == end) {
		tree[index] = table[start];
	}
	else {
		int mid = (start + end) / 2;
		tree[index] = init((index* 2) + 1, start, mid) + init((index * 2) + 2, mid + 1, end);
	}
	return tree[index];
}


long long sum(int index, int start, int end, int left, int right) {
	propagate(index, start, end);
	if (start > right || end < left) {
		return 0;
	}
	else if (start >= left && end <= right) {
		return tree[index];
	}
	else {
		int mid = (start + end) / 2;
		return (sum((index * 2) + 1, start, mid, left, right) + sum((index * 2) + 2, mid + 1, end, left, right));
	}

}

void change(int start, int end, int index, long long diff, int left, int right) {
	propagate(index, start, end);
	if (start > right || end < left) {
		return;
	}
	if (start >= left && end <= right) {
		tree[index] += (long long)(end - start + 1) * diff;
		if (start != end) {
			lazy[index * 2 + 1] += diff;
			lazy[index * 2 + 2] += diff;
		}
		return;
	}
	int mid = (start + end) / 2;
	change(start, mid, (index * 2) + 1, diff, left, right);
	change(mid + 1, end, (index * 2) + 2, diff, left, right);
	tree[index] = tree[index * 2 + 1] + tree[index * 2 + 2];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(lazy, 0, sizeof(lazy));
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> table[i];
	}
	init(0,0, n-1);

	for (int i = 0; i < m + k; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			long long b, c, d;
			cin >> b >> c >> d;
			change(0, n -1, 0, d, b-1, c-1);
		}
		else if (a == 2) {
			int b, c;
			cin >> b >> c;
			cout << sum(0, 0, n - 1, b - 1, c - 1) << "\n";
		}
	}

	return 0;
}
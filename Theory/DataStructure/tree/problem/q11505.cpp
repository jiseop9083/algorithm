//백준 11505번 구간 곱 구하기
//세그먼트 트리 연습 문제

#include <iostream>
#include <cstring>
using namespace std;

int n, m, k;
long long tree[2100000];
long long table[1000005];

long long init(int start, int end, int index) {
	if (start == end) {
		tree[index] = table[start];
	}
	else {
		int mid = (start + end) / 2;
		tree[index] = (init(start, mid, (index * 2) + 1) * init(mid + 1, end, (index * 2) + 2)) % 1000000007;
	}
	return tree[index];
}

long long mul(int start, int end, int index, int left, int right) {
	if (start > right || end < left) {
		return 1;
	}
	else if (start >= left && end <= right) {
		return tree[index];
	}
	else {
		int mid = (start + end) / 2;
		return (mul(start, mid, (index * 2) + 1, left, right) * mul(mid + 1, end, (index * 2) + 2, left, right)) % 1000000007;
	}
}

void change(int start, int end, int index, int pos, long long diff) {
	if (pos < start || pos > end) {
		return;
	}
	if (start != end) {
		int mid = (start + end) / 2;
		change(start, mid, (index * 2) + 1, pos, diff);
		change(mid + 1, end, (index * 2) + 2, pos, diff);
		tree[index] = (tree[index * 2 + 1] * tree[index * 2 + 2]) % 1000000007;
	}
	else {
		tree[index] = table[pos];
		return;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> table[i];
	}
	init(0, n - 1, 0);
	for (int i = 0; i < m + k; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			long long b, c;
			cin >> b >> c;
			table[b - 1] = c;
			change(0, n - 1, 0, b - 1, c);
		}
		else if (a == 2) {
			int b, c;
			cin >> b >> c;
			cout << mul(0, n - 1, 0, b - 1, c - 1) << "\n";
		}
	}
	return 0;
}
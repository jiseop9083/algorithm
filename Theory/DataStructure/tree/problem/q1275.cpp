//백준 1275번 커피숍2
//세그먼트 트리 기초

#include <iostream>
using namespace std;

int n, q;
long long table[100005];
long long tree[300000];

long long init(int start, int end, int index) {
	if (start == end) {
		tree[index] = table[start];
	}
	else {
		int mid = (start + end) / 2;
		tree[index] = init(start, mid, (index * 2) + 1) + init(mid + 1, end, (index * 2 + 2));
	}
	return tree[index];
}

long long sum(int start, int end, int index, int left, int right) {
	if (start > right || end < left) {
		return 0;
	}
	else if (left <= start && end <= right) {
		return tree[index];
	}
	else {
		int mid = (start + end) / 2;
		return (sum(start, mid, (index * 2) + 1, left, right) + sum(mid + 1, end, (index * 2) + 2, left, right));
	}
}

void change(int pos, long long diff, int start, int end, int index) {
	if (pos < start || pos > end) {
		return;
	}
	tree[index] += diff;
	if (start != end) {
		int mid = (start + end) / 2;
		change(pos, diff, start, mid, (index * 2) + 1);
		change(pos, diff, mid + 1, end, (index * 2) + 2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> table[i];
	}
	init(0, n - 1, 0);
	for (int i = 0; i < q; i++) {
		int a, b, c;
		long long d;
		cin >> a >> b >> c >> d;
		if (a < b) {
			cout << sum(0, n - 1, 0, a - 1, b - 1) << "\n";
		}
		else {
			cout << sum(0, n - 1, 0, b - 1, a - 1) << "\n";
		}
		long long e = d - table[c - 1];
		table[c - 1] = d;
		change(c - 1, e, 0, n - 1, 0);
	}
	return 0;
}
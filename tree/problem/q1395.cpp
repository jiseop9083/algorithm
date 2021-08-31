//백준 1395번 스위치
//느리게 갱신되는 세그먼트 트리

#include <iostream>
#include <cstring>
using namespace std;

int n, m;
int tree[270000];
bool lazy[270000];

void propagate(int index, int start, int end) {
	if (lazy[index] == false) {
		return;
	}
	tree[index] = (end - start + 1) - tree[index];
	if (start != end) {
		lazy[index * 2 + 1] = !lazy[(index * 2) + 1];
		lazy[index * 2 + 2] = !lazy[(index * 2) + 2];
	}
	lazy[index] = false;
}


int sum(int index, int start, int end, int left, int right) {
	propagate(index, start, end);
	if (start > right || end < left) {
		return 0;
	}
	else if (left <= start && end <= right) {
		return tree[index];
	}
	else {
		int mid = (start + end) / 2;
		return sum((index * 2) + 1, start, mid, left, right) + sum((index * 2) + 2, mid + 1, end, left, right);
	}
}

void change(int index, int start, int end, int left, int right) {
	propagate(index, start, end);
	if (start > right || end < left) {
		return;
	}
	else if (left <= start && end <= right) {
		tree[index] = (end - start + 1) - tree[index];
		if (start != end) {
			lazy[(index * 2) + 1] = !lazy[(index * 2) + 1];
			lazy[(index * 2) + 2] = !lazy[(index * 2) + 2];
		}
		return;
	}
	int mid = (start + end) / 2;
	change((index * 2) + 1, start, mid, left, right);
	change((index * 2) + 2, mid + 1, end, left, right);
	tree[index] = tree[(index * 2) + 1] + tree[(index * 2) + 2];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	memset(tree, 0, sizeof(tree));
	memset(lazy, false, sizeof(lazy));
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			change(0, 0, n-1, b-1, c-1);
		}
		else if (a == 1) {
			cout << sum(0, 0, n-1, b-1, c-1) << "\n";
		}
	}
	return 0;
}
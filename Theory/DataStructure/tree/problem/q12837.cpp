//백준 12837번 가계부(Hard)
//세그먼트 트리

#include <iostream>
#include <cstring>
using namespace std;

int n, q;
long long tree[2100000];

void change(int index, int pos, long long diff, int start, int end) {
	if (pos < start || pos > end) {
		return;
	}
	tree[index] += diff;
	if (start != end) {
		int mid = (start + end) / 2;
		change((index * 2) + 1, pos, diff, start, mid);
		change((index * 2) +2, pos, diff, mid + 1, end);
	}
}

long long sum(int index, int start, int end, int left, int right) {
	if (start > right || end < left) {
		return 0;
	}
	else if (left <= start && end <= right) {
		return tree[index];
	}
	else {
		int mid = (start + end) / 2;
		return sum((index * 2) + 1, start, mid, left, right) + sum((index * 2) +2, mid + 1, end, left, right);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(tree, 0, sizeof(tree));
	cin >> n >> q;
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			long long c;
			cin >> c;
			change(0, b-1, c, 0, n-1);
		}
		else if(a == 2){
			int c;
			cin >> c;
			cout << sum(0, 0, n - 1, b - 1, c - 1) << "\n";
		}
	}
	return 0;
}
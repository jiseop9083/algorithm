//백준 17400번 깃발춤
//세그먼트 트리 문제 응용

#include <iostream>
#include <cstdlib>
using namespace std;

int n, q;
int odd_cnt;
int even_cnt;

long long odd_tree[524300];
long long even_tree[524300];
int* odd_table; 
int* even_table;

long long init(int* table, long long* tree, int index, int start, int end) {
	if (start == end) {
		tree[index] = (long long)table[start];
	}
	else {
		tree[index] = init(table, tree, (index * 2) + 1, start, (start + end) / 2) + init(table, tree, (index * 2) + 2, (start + end) / 2 + 1, end);
	}
	return tree[index];
}

long long sum(long long* tree, int index, int start, int end, int left, int right) {
	if (start > right || end < left) {
		return 0;
	}
	else if (left <= start && end <= right) {
		return tree[index];
	}
	else {
		return sum(tree, (index * 2) + 1, start, (start + end) / 2, left, right) + sum(tree, (index * 2) + 2, (start + end) / 2 + 1, end, left, right);
	}
}

void change(long long* tree, long long diff, int pos, int index, int start, int end) {
	if (pos < start || pos > end) {
		return;
	}
	tree[index] += diff;
	if (start != end) {
		change(tree, diff, pos, (index * 2) + 1, start, (start + end) / 2);
		change(tree, diff, pos, (index * 2) + 2, (start + end) / 2 + 1, end);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> q;
	even_table = new int[160000];
	odd_table = new int[160000];
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			cin >> even_table[even_cnt];
			even_cnt++;
		}
		else {
			cin >> odd_table[odd_cnt];
			odd_cnt++;
		}
	}
	init(even_table, even_tree, 0, 0, even_cnt - 1);
	init(odd_table, odd_tree, 0, 0, odd_cnt - 1);
	delete [] even_table;
	delete [] odd_table;
	int odd_s, even_s, odd_e, even_e;
	for (int i = 0; i < q; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			int b, c;
			cin >> b >> c;
			odd_s = (b -1) / 2;
			even_s = (b -1) / 2;
			odd_e = (c - 1) / 2;
			even_e = (c -1) / 2;
			if ((b - 1) % 2 == 1) {
				even_s++;
			}
			if ((c - 1)% 2 == 0) {
				odd_e--;
			}
			long long p = sum(even_tree, 0, 0, even_cnt - 1, even_s, even_e);
			long long q = sum(odd_tree, 0, 0, odd_cnt - 1, odd_s, odd_e);
			cout << llabs(p - q) << "\n";
		}
		else if (a == 2) {
			int b;
			long long c;
			cin >> b >> c;
			if ((b-1) % 2 == 0) {
				change(even_tree, c, (b - 1) / 2, 0, 0, even_cnt -1);
			}
			else {
				change(odd_tree, c, (b - 1) / 2, 0, 0, odd_cnt -1);
			}
		}
	}
	return 0;
}
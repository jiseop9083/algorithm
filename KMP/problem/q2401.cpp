//백준 2401번 최대 문자열 붙여넣기
//일차원 DP > deep번째까지 최대 

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string whole;
string part[501];
int table[100001];
pair<int, int> memo[501];
int pi[505][10001];

void get_pos(int num) {
	int m = part[num].size();
	memset(pi, 0, sizeof(pi));
	int start = 1;
	int match = 0;
	while (start + match < m) {
		if (part[num][start + match] == part[num][match]) {
			match++;
			pi[num][start + match - 1] = match;
		}
		else {
			if (match == 0) {
				start++;
			}
			else {
				start += match - pi[num][match - 1];
				match = pi[num][match - 1];
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> whole;
	cin >> n;
	memset(table, -1, sizeof(table));
	memset(memo, 0, sizeof(memo));
	for (int i = 0; i < n; i++) {
		cin >> part[i];
		get_pos(i);
	}
	


	for (int deep = 0; deep < whole.size(); deep++) {
		if (deep > 0) {
			table[deep] = table[deep - 1];
		}
		for (int k = 0; k < n; k++) {

			int start = memo[k].first;
			int match = memo[k].second;
			int m = part[k].size();
			while (start <= deep + 1 - m) {
				if (match < m && whole[start + match] == part[k][match]) {
					match++;
					if (match == m) {

						start++;
						match = pi[k][match - 1];
					}
				}
				else {
					if (match == 0) {
						start++;
					}
					else {
						start += match - pi[k][match - 1];
						match = pi[k][match - 1];
					}
				}
			}
			memo[k].first = start;
			memo[k].second = match;

		}
	}
	

	cout << table[whole.size() - 1];


	return 0;
}

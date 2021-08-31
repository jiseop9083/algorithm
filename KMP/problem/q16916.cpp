//백준 16916번 부분 문자열
//KMP연습문제

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int pi[1000005];
string part;
string whole;

void get_pi() {
	int n = part.size();
	int start = 1;
	int matched = 0;
	while (start + matched < n) {
		if (part[start + matched] == part[matched]) {
			matched++;
			pi[start + matched - 1] = matched;
		}
		else {
			if (matched == 0) {
				start++;
			}
			else {
				start += (matched - pi[matched - 1]);
				matched = pi[matched -1];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	bool an = false;
	memset(pi, 0, sizeof(pi));
	cin >> whole;
	cin >> part;
	get_pi();
	int n = whole.size();
	int m = part.size();
	int start = 0;
	int matched = 0;
	while (start <= n - m) {
		if (matched < m && whole[start + matched] == part[matched]) {
			matched++;
			if (matched == m) {
				an = true;
				break;
			}
		}
		else {
			if (matched == 0) {
				start++;
			}
			else {
				start += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	if (an == true) {
		cout << "1";
	}
	else {
		cout << "0";
	}
	return 0;
}

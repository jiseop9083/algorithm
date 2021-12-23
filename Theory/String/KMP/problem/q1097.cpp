//백준 1097번 마법의 단어
//조합한다 8! > kmp로 분석한다 480번

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int k;
string word[10];
int an = 0;
int pi[200];
bool visit[10];

void get_pi(string part) {
	memset(pi, 0, sizeof(pi));
	int m = part.size();
	int start = 1;
	int matched = 0;
	while (start + matched < m) {
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
				matched = pi[matched - 1];
			}
		}
	}
}

void back(int deep, string arr) {
	if (deep == n) {
		string part = arr;
		string whole = arr + arr;
		int p = part.size();
		int w = whole.size();
		get_pi(part);
		int start = 0;
		int matched = 0;
		int cnt = 0;
		while (start <= w - p) {
			if (matched < p && whole[start + matched] == part[matched]) {
				matched++;
				if (matched == p) {
					cnt++;
					start++;
					matched = 0;
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
		if (cnt - 1== k) {
			an++;
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			back(deep+1, arr + word[i]);
			visit[i] = false;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(visit, false, sizeof(visit));
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word[i];
	}
	cin >> k;
	string arr = "";
	back(0, arr);
	cout << an;
	return 0;
}
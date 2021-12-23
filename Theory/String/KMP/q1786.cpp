#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

string word;
string pattern;
int pi[1000005];
vector<int> an;

void get_pi() {
	int len = pattern.size();
	pi[0] = 0;
	int start = 1;
	int matched = 0;
	while (start + matched < len) {
		if (pattern[start + matched] == pattern[matched]) {
			pi[start + matched] = 1 + matched;
			matched++;
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


void kmp() {
	int n = word.size();
	int m = pattern.size();
	int start = 0;
	int matched = 0;
	while (start <= n - m) {
		//검색에 성공했을 때
		if (matched < m && word[start + matched] == pattern[matched]) {
			matched++;
			if (matched == m) {
				an.push_back(start+ 1);
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
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	getline(cin, word);
	getline(cin, pattern);
	get_pi();
	kmp();
	cout << an.size() << "\n";
	for (int i = 0; i < an.size(); i++) {
		cout << an[i]  << " ";
	}
	return 0;
}

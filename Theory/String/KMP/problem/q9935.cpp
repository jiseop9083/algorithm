//백준 9935번 문자열 폭발

#include <iostream>
#include <string>
#include <stack>
using namespace std;

string arr;
string boom;
stack <char> an;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> arr;
	cin >> boom;
	for (int i = 0; i < arr.size(); i++) {
		int check = 0;
		an.push(arr[i]);
		if (an.size() >= boom.size()) {
			for (int j = boom.size() - 1; j >= 0; j--) {
				if (an.top() == boom[j]) {
					an.pop();
				}
				else {
					check = boom.size() -1 - j;
					break;
				}
			}
		}
		if (check != 0) {
			for (int j = boom.size() - check; j < boom.size(); j++) {
				an.push(boom[j]);
			}
		}
	}



	int cnt = 0;
	stack <char> a;
	if (an.size() == 0) {
		cout << "FRULA";
	}
	else {
		while (!an.empty()) {
			a.push(an.top());
			an.pop();
		}
		while (!a.empty()) {
			cout << a.top();
			a.pop();
		}
	}
	
	return 0;
}
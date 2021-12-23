//백준 9253번 스페셜 저지
//KMP를 연습하자!

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string a;
string b;
string c;
bool an = false;
int pi[200005];

void get_pi() {
	int en = c.size();
	pi[0] = 0;
	int start = 1;
	int matched = 0;//
	while(start+ matched < en){
		if (c[start + matched] == c[matched]) {//일치
			pi[start + matched] = matched + 1;
			matched++;
		}
		else {//일치하지 않을 때
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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(pi, 0, sizeof(pi));
	cin >> a;
	cin >> b; 
	cin >> c;
	get_pi();

	int check = 0;

	int aa = a.size();
	int bb = b.size();
	int cc = c.size();
	int start = 0;
	int matched = 0;
	while (start <= aa - cc) {
		if (matched < cc && a[start + matched] == c[matched]) {
			matched++;
			//정답 추가
			if (matched == cc) {
				check = 1;
				break;
			}
		}
		else {
			if (matched == 0) {//예외: 처음에는 다음 칸에서 계속
				start++;
			}
			else {
				start += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	start = 0;
	matched = 0;
	if (check == 1) {
		while (start <= bb - cc) {
			if (matched < cc && b[start + matched] == c[matched]) {
				matched++;
				if (matched == cc) {
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
	}
	if (an == false) {
		cout << "NO";
	}
	else {
		cout << "YES";
	}
	return 0;
}
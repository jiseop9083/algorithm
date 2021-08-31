//���� 4354�� ���ڿ� ����
//���� p��� �ϸ� n = p(n - pi(n-1))�� �����ϸ� �ȴ�

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string arr;
int pi[1000005];


void get_pi() {
	memset(pi, 0, sizeof(pi));
	int n = arr.size();
	int start = 1;
	int match = 0;
	while (start + match < n) {
		if (arr[start + match] == arr[match]) {
			match++;
			pi[start + match - 1] = match;
		}
		else{
			if (match == 0) {
				start++;
			}
			else {
				start += match - pi[match - 1];
				match = pi[match - 1];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> arr;
	while (arr != ".") {
		get_pi();
		int n = arr.size();
		if (n % (n - pi[n - 1]) == 0) {
			cout << n / (n - pi[n - 1]) << "\n";
		}
		else {
			cout << "1" << "\n";
		}
		cin >> arr;
	}
	return 0;
}
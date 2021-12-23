//백준 2004번 조합 0의 개수
//nCk = n!/ k!(n-k)!

#include <iostream>
#include <algorithm>
using namespace std;
int n, m;

int five(int num) {
	if (num / 5 >= 5) {
		return (num / 5) + five(num / 5);
	}
	else {
		return (num / 5);
	}
}

int two(int num) {
	if (num / 2 >= 2) {
		return (num / 2) + two(num / 2);
	}
	else {
		return (num / 2);
	}
}

int main() {
	cin >> n >> m;
	cout << min(five(n) - five(m) - five(n -m), two(n) - two(m) - two(n -m));
	return 0;
}
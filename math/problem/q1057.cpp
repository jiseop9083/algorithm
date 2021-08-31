//백준 1057번 토너먼트

#include <iostream>
using namespace std;

int n, a, b;
int cnt = 0;
int main(){
	cin >> n >> a >> b;
	while (a != b) {
		a = (a+1) / 2;
		b = (b+1) / 2;
		cnt++;
	}
	cout << cnt;
	return 0;
}
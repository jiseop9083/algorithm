//백준 1003번 피보나치 함수

#include <iostream>
#include <cstring>
using namespace std;

pair<int, int> num[45];

pair<int, int> fibo(int n) {
	pair<int, int>& ret = num[n];
	if (ret.first != -1) {
		return ret;
	}
	return ret = { fibo(n - 1).first + fibo(n - 2).first, 
				fibo(n - 1).second + fibo(n - 2).second };
}

int main() {
	memset(num, -1, sizeof(num));
	int n,t;
	cin >> t;
	num[0] = { 1, 0 };
	num[1] = { 0 , 1 };
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << fibo(n).first << " " << fibo(n).second << "\n";
	}
		
	return 0;
}

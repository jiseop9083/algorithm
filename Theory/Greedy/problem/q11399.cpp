//백준 11399번 ATM
//인출시간이 짧은 놈이 앞에 오면 된다.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	int a;
	int sum = 0;
	vector <int> v;
	vector<int>::iterator it;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(),v.end());

	for (it = v.begin(); it != v.end(); it++) {
		if(it != v.begin())	*it += *(it-1);
		sum += *it;
		
	}
	cout << sum << "\n";
	return 0;
}
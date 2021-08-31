#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>matrix;

int n;
long long m;

vector<vector<int>> product(vector<vector<int>> a, vector<vector<int>> b) {
	vector<vector<int>> c;
	vector<int>ve;
	for (int i = 0; i < n; i++) {
		ve.clear();
		for (int j = 0; j < n; j++) {
			int sum = 0;
			for (int k = 0; k < n; k++) {
				sum += (a[i][k] * b[k][j]);
			}
			ve.push_back(sum % 1000);
		}
		c.push_back(ve);
	}
	return c;
}

vector<vector<int>> con(long long deep) {
	if (deep == 1) {
		return matrix;
	}
	vector<vector<int>> vec;
	vec = con(deep / 2);
	if (deep % 2 == 0) {
		return product(vec, vec);
	}
	else {
		return product(vec, product(vec, matrix));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	vector<int> ve;
	for (int i = 0; i < n; i++) {
		ve.clear();
		for (int j = 0; j < n; j++) {
			int a;
			cin >> a;
			ve.push_back(a % 1000);
		}
		matrix.push_back(ve);
	}
	vector<vector<int>> an;
	an = con(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << an[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
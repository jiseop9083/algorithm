//백준 6549번 히스토그램에서 가장 큰 직사각형
//범위가 long long인 것만 빼면 히스토그램과 똑같은 문제

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long n;
long long height[100005];
long long an = 0;


long long cq(long long start, long long end) {
	if (start == end) {
		return height[end];
	}
	long long mid = (start + end) / 2;
	long long sum = max(cq(mid + 1, end), cq(start, mid));
	long long fron = mid;
	long long bac = mid;
	long long hi = min(height[fron], height[bac]);

	while (start < fron || bac < end) {
		if (bac < end && (fron == start || height[bac + 1] > height[fron - 1])) {
			bac++;
			hi = min(height[bac], hi);
		}
		else {
			fron--;
			hi = min(height[fron], hi);
		}
		sum = max(sum, (bac - fron + 1) * hi);
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	while (n != 0) {
		memset(height, 0, sizeof(height));
		for (int i = 0; i < n; i++) {
			cin >> height[i];
		}
		cout << cq(0, n - 1) << "\n";
		
		cin >> n;
	}
	return 0;
}
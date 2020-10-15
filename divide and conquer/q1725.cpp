//백준 1725번 히스토그램

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int num[100005];

int histo(int start, int end) {
	if (start == end) {
		return num[start];
	}
	int mid = (start + end) / 2;
	int ret = max(histo(start, mid), histo(mid + 1, end));
	int left = mid;
	int right = mid + 1;
	int height = min(num[left], num[right]);
	ret = max(ret, height * 2);
	while (start < left || right < end) {
		if (right < end && (left == start || num[left - 1] < num[right + 1])) {
			right++;
			height = min(height, num[right]);
		}
		else {
			left--;
			height = min(height, num[left]);
		}
		ret = max(ret, height * (right - left + 1));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cout << histo(0, n - 1);
	return 0;
}

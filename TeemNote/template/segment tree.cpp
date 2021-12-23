//세그먼트 트리 구간합 구하기

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

class Segtree{
public:
	//세그먼트 트리
	vector <ll> tree; 
	//leaf크기 (구간의 범위보다 큰 2의 제곱수)
	int size; 

	Segtree(int t) {
		for (size = 1; size < t; size *= 2);
		tree.resize(size * 2);
	}

	//bottom up 방식, 숫자 업데이트
	void update(int pos, ll diff) {
		//변화시키고자하는 숫자의 번호
		int index = size + pos - 1;
		while (index) {
			tree[index] += diff;
			index /= 2;
		}
	}

	//간략화
	ll sum(int left, int right) {
		return sum(1, 1, size, left, right);
	}

	//구간 합 구하기
	ll sum(int pos, int start, int end, int left, int right) {
		//범위 밖
		if (start > right || end < left) {
			return 0;
		}
		//완전히 범위 안
		else if (left <= start && end <= right) {
			return tree[pos];
		}
		//그 외
		else {
			int mid = (start + end) / 2;
			return sum(pos * 2, start, mid, left, right) + sum(pos * 2 + 1, mid + 1, end, left, right);
		}
	}
};


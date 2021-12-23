//이분탐색
//up-down 숫자게임생각하면 된다
//사용전 정렬 필수
#include <iostream>
using namespace std;
int n;

//top - down
int bs(int* arr, int start, int end, int num) {
	if (start > end) {
		return -1;
	}
	int mid = (start + end) / 2;
	if (arr[mid] > num) {
		return bs(arr, mid + 1, end, num);
	}
	else if (arr[mid] < num) {
		return bs(arr, start, mid - 1, num);
	}
	else {
		return mid;
	}
}

//bottom -up
bool bs(int* arr,  int num) {
	int start = 0;
	int end = n - 1;
	while (start <= end) {
		int mid = (start + end) / 2;

		if (num == arr[mid]) {
			return true;
		}
		else if (num > arr[mid]) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
}


//lower_bound;
int lower_bound(int* arr, int len, int num) {
	int start = 0;
	int end = len;

	int mid;
	while (end - start > 0) {
		mid = (start + end) / 2;

		if (arr[mid] < num) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}
	return end;
}

//upper_bound;
int upper_bound(int* arr, int len, int num) {
	int start = 0;
	int end = len;
	int mid;

	while (end - start > 0) {
		mid = (start + end) / 2;
		if (arr[mid] < num) {
			start = mid + 1;
		}
		else {
			end = mid;
		}
	}
	return end;
}

//백준 2042번 구간 합 구하기
//세그먼트 트리 기본 문제

#include <iostream>
#include <cstring>
using namespace std;

long long tree[2101000];
long long table[1000005];
int n, m, k;

long long init(int index, int start, int end){
    if (start == end) {
        tree[index] = table[start];
    }
    else {
        int mid = (start + end) / 2;
        tree[index] = init((index * 2) + 1, start, mid) + init((index * 2) + 2, mid + 1, end);
    }
    return tree[index];
}

long long sum(int index, int start, int end, int left, int right) {
    if (start > right || end < left) {//벗어났을 때
        return 0;
    }
    else if (left <= start && end <= right) {//속할때
        return tree[index];
    }
    else {//애매할 때
        int mid = (start + end) / 2;
        return (sum((2 * index) + 1, start, mid, left, right) + sum(2 * index + 2, mid + 1,end, left, right));
    }
}

void change(int pos, long long num, int index, int start, int end) {
    if (pos < start || pos > end) {
        return;
    }
    tree[index] += num;//속해있으면 바뀐 숫자만큼 변해야함

    if (start != end) {
        int mid = (start + end) / 2;
        change(pos, num, (index * 2) + 1, start, mid);
        change(pos, num, (index * 2) + 2, mid+1, end);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(tree, 0, sizeof(tree));
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> table[i];
    }
    init(0, 0, n - 1);

    for (int i = 0; i < m + k; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            long long b, c;
            cin >> b >> c;
            long long d = c - table[b - 1];
            table[b - 1] = c;
            change(b - 1, d, 0, 0, n - 1);
            
        }
        else if (a == 2) {
            int b, c;
            cin >> b >> c;
            cout << sum(0, 0, n - 1, b-1, c-1) << "\n";
        }
    }
    return 0;
}
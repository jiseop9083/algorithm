// ���׸�Ʈ Ʈ�� ������ ���ϱ�

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

class Segtree {
 public:
  // ���׸�Ʈ Ʈ��
  vector<ll> tree;
  // leafũ�� (������ �������� ū 2�� ������)
  int size;

  Segtree(int t) {
    for (size = 1; size < t; size *= 2)
      ;
    tree.resize(size * 2);
  }

  // bottom up ���, ���� ������Ʈ
  void update(int pos, ll diff) {
    // ��ȭ��Ű�����ϴ� ������ ��ȣ
    int index = size + pos - 1;
    while (index) {
      tree[index] += diff;
      index /= 2;
    }
  }

  // ����ȭ
  ll sum(int left, int right) { return sum(1, 1, size, left, right); }

  // ���� �� ���ϱ�
  ll sum(int pos, int start, int end, int left, int right) {
    // ���� ��
    if (start > right || end < left) {
      return 0;
    }
    // ������ ���� ��
    else if (left <= start && end <= right) {
      return tree[pos];
    }
    // �� ��
    else {
      int mid = (start + end) / 2;
      return sum(pos * 2, start, mid, left, right) +
             sum(pos * 2 + 1, mid + 1, end, left, right);
    }
  }
};

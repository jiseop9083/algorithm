// ������ ���ŵǴ� ���׸�Ʈ Ʈ��

#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

class Segtree {
 public:
  // Ʈ���� lazy��
  vector<ll> tree;
  vector<ll> lazy;
  int size;

  Segtree(int t) {
    for (size = 1; size < t; size *= 2)
      ;
    tree.resize(size * 2);
    lazy.resize(size * 2);
  }

  // lazy����
  void lazy_update(int pos, int start, int end) {
    if (lazy[pos] != 0) {
      // lazy���� ���ϱ�
      tree[pos] += ((ll)end - (ll)start + 1) * lazy[pos];
      if (start != end) {
        // ����
        lazy[pos * 2] += lazy[pos];
        lazy[pos * 2 + 1] += lazy[pos];
      }
      lazy[pos] = 0;
    }
  }

  // ����ȭ
  void update(int left, int right, ll diff) {
    update(1, 1, size, left, right, diff);
  }

  void update(int pos, int start, int end, int left, int right, ll diff) {
    lazy_update(pos, start, end);
    if (start > right || end < left) {
      return;
    } else if (left <= start && end <= right) {
      lazy[pos] += diff;
      // �� �ڽĿ��� �Ȱ��� ����
      lazy_update(pos, start, end);
    } else {
      int mid = (start + end) / 2;
      update(pos * 2, start, mid, left, right, diff);
      update(pos * 2 + 1, mid + 1, end, left, right, diff);
      tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
    }
  }

  ll sum(int left, int right) { return sum(1, 1, size, left, right); }

  ll sum(int pos, int start, int end, int left, int right) {
    lazy_update(pos, start, end);
    if (start > right || end < left) {
      return 0;
    } else if (left <= start && end <= right) {
      return tree[pos];
    } else {
      int mid = (start + end) / 2;
      return sum(pos * 2, start, mid, left, right) +
             sum(pos * 2 + 1, mid + 1, end, left, right);
    }
  }
};
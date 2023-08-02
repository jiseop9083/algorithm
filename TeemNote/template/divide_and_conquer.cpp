

// �⺻����
// ���� 11729�� �ϳ��� ž �̵� ����
// ���� 1074�� Z
// ���� 1725�� ������׷�

#include <iostream>
using namespace std;

int arr[10000];

void dosomething() { return; }

// ��������
// ū ������ ���� ������ ������ �ذ�
// ū ������ ���� �����ذ� ����� ����!!!
int dc(int start, int end) {
  if (start > end) {
    return;
  }
  int mid = (start + end) / 2;
  // ����������(divide)
  dc(start, mid);
  dc(mid + 1, end);

  // ���� ���� �ΰ� ��ġ��(conquer)
  dosomething();
  return;
}
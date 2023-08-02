// ��Ʈ��ŷ
// �⺻������ dfs(���� Ž��)
// ��, ���ɼ��� ���� ���� �߶���
// ����� ���� �پ��� �� ��밡��

// �⺻ ����
// ���� 9663�� N -Queen
// ���� N�� M�ø���
// ���� 2580�� ������

#include <iostream>
using namespace std;

int solution[100000];
int n;

bool IsOK();
void Dosomething();

void back(int deep) {
  if (deep == n) {
    // ���������� �˻�
    // for������ �̸� �غ��� ������
    if (IsOK()) {
      Dosomething();
    }
    return;
  }

  for (int i = 0; i <= 1; i++) {
    // ���⼭ �˻��ص� ��
    if (IsOK()) {
      solution[deep] = i;
      // �ڽĳ��� �̵�
      back(deep + 1);
    }
  }
}
// �⺻���� ���̳���
// ���α׷���(������ȹ��) �ٽ��� ���� ������ ���� �ʴ�
// ���̴�. memoization(�޸������̼�)�� ������
// ������� 1���� DP

// �⺻����
// ���� 1003�� �Ǻ���ġ �Լ�
// 2XnŸ�ϸ�

// �Ǻ���ġ �Լ� ���� Ǯ��
// top -down
#include <iostream>
using namespace std;

pair<int, int> num[45];  // 0, 1
int t, n;

pair<int, int> dp(int deep) {
  pair<int, int>& ret = num[deep];
  // ������ ������ �н�
  if (ret.first != -1) {
    return ret;
  }
  return ret = {dp(deep - 1).first + dp(deep - 2).first,
                dp(deep - 1).second + dp(deep - 2).second};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  // �ʱ�ȭ
  for (int i = 0; i < 42; i++) {
    num[i].first = -1;
    num[i].second = -1;
  }
  num[0] = {1, 0};
  num[1] = {0, 1};
  for (int i = 0; i < t; i++) {
    cin >> n;
    cout << dp(n).first << " " << dp(n).second << "\n";
  }

  return 0;
}
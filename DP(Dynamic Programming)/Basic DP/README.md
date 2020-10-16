# 기본적인 DP의 개념
 
## DP란?
 - Dynamic programming은 동적 계획법이라고 불린다.
 - 문제를 풀다보면 시간이나 메모리 제한이 작은 복잡한 문제가 많다.
 - 이러한 문제들을 작은 문제로 나누어서 다양한 알고리즘을 적용해 문제를 해결하는 방식이다.
 - 문제를 나누어 해결한다는 점에서 분할정복 알고리즘과 비슷하지만,
 - 분할정복과는 다르게 작은 문제를 여러 번 계산하는 대신 한 번만 계산하고 재활용한다.
 - 어떤 단계에서 나온 값을 저장하는 기법을 **메모이제이션(memoization)**이라고 한다. **~memorization 아님~**
 - memoization을 사용하기 위해서는 사용하는 함수가 참조적 투명성(referential transparency을 가져야한다.
 - 참조적 투명성이란 함수에서 입력변수(argument)이 같으면 return값이 똑같이 나오는 성질이다.
 - 즉, 함수의 return값이 argument에 의해서만 결정된다는 것이다.
 
 ---
 
## top-down과 bottom up
 - DP를 구현하는 방법은 크게 두 가지가 있다.
 - 바로 top-down과 bottom-up이다. 
 - top-down은 큰 문제를 점점 작은 단위문제로 나누어서 푸는 방식이고
 - bottom-up은 작은 문제들을 해결하면서 점점 큰 문제에 접근하는 방식이다.
 - 말로 설명하면 어려우니 n번째 피보나치수를 구현하는 방식을 
 - dp없이 구현, top-down방식으로 구현, bottom-up으로 구현하는 코드를 보자 (전체 코드이다)
 - **백준 2747번 피보니치 수**
 <br/><https://www.acmicpc.net/problem/2747>
 
 ### dp없이 구현한 n번째 
 
 ```
#include <iostream>
using namespace std;

int num[50];

int main() {
	 int n;
	 cin >> n;
	 num[0] = 0;
	 num[1] = 1;
	 for (int i = 2; i <= n; i++) {
		  num[i] = num[i - 1] + num[i - 2];
	 }
	 cout << num[n];
	 return 0;
}

```


 
## 문제를 풀어보자!!!
 
### 1. 백준 1003번 피보나치 함수
<br/> <https://www.acmicpc.net/problem/1003>

 - 0과 1이 몇 번 출력되는지 구하면되는 문제이다.
 - fibonacci 함수의 정의에 의해 fibo(n)을 구하려면 fibo(n -1)과 fibo(n -2)를 호출해야한다.
 - 즉, fibo(n)을 호출하면 fibo함수를 n번째 피보나치 수만큼 호출해야한다. 
 - 고로 n이 40일때 문제에 나와있는 함수를 호출하면 fibo함수는 무려 **165,580,141번** 호출된다.
 <br/>
 - 이를 해결하는 방법은 메모이제이션을 사용하는 것이다.
 - fibo를 중복해서 호출하는 경우가 너무 많기 때문에 return값을 저장한다면 더 적은 호출을 사용할 것이다.
 - 이제 코드를 보자.

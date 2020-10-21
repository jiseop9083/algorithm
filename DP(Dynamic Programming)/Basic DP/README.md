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
 
 ### dp없이 구현
 
 ```
#include <iostream>
using namespace std;

int fibo(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibo(n - 1) + fibo(n - 2);
}

int main() {
	int n;
	cin >> n;
	cout << fibo(n);
	return 0;
}

```

~DP없이 풀면 시간초과나요!!~

 ### bottom-up 방식
 
 ```
#include <iostream>
using namespace std;

int num[50];

int main() {
	 int n;
	 cin >> n;
	 //기저 조건
	 num[0] = 0;
	 num[1] = 1;
	 for (int i = 2; i <= n; i++) {
	 //num[i]에 저장
		  num[i] = num[i - 1] + num[i - 2];
	 }
	 cout << num[n];
	 return 0;
}

```
### top-down 방식

```
#include <iostream>
#include <cstring>
using namespace std;

int num[50];

int fibo(int n) {
	int& ret = num[n];
	//이전에 호출된적이 있으면
	if (ret != -1) {
		return ret;
	}
	return ret = fibo(n - 1) + fibo(n - 2);
}

int main() {
	memset(num, -1, sizeof(num));
	int n;
	cin >> n;
	num[0] = 0;
	num[1] = 1;
	cout << fibo(n);
	return 0;
}

```

- 두방식의 차이**
	| |장점|단점|
	|:------:|:---:|:---:|
	|top-down|구현이 쉬움|메모리와 시간을 많이 먹음|
	|bottom-up|메모리와 시간을 적게 먹음|직관적이지 않음|

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
 - 이제 핵심 코드를 보자.
	 
```
//top-down구현
//pair<int, int>는 0출력횟수, 1출력횟수
pair<int, int> fibo(int n) {
	pair<int, int>& ret = num[n];
	//이전에 호출된적이 있으면 바로 return
	if (ret.first != -1) {
		return ret;
	}
	return ret = { fibo(n - 1).first + fibo(n - 2).first, 
				fibo(n - 1).second + fibo(n - 2).second };
}

```

### 2. 백준 11051번 이항 계수 2
 - 간단한 문제이다 nCk를 10007로 나눈 나머지를 구하면 된다.
 - nCk = n-1Ck-1 + n -1Ck라는 성질만 이용하면 피보나치문제처럼 구할 수 있다.
 - 다면 독립 변수가 n, k로 두개이므로 이차원 배열을 이용한 DP를 구현해야한다.
 <br/>
 
 **참고**
 - a = x*10007 + c, b = y*10007 + d라고 하자. 
 - (a + b) % 10007 = (x*10007 + y* 10007 + c + d) % 10007 = (c + d) % 10007이다.
 - 즉, a + b의 나머지는 a의 나머지와 b의 나머지의 합의 나머지와 같다.
 
``` 
int dp(int n, int k) {
	int& ret = num[n][k];
	//이전에 호출된적이 있으면 바로 return
	if (ret != -1) {
		return ret;
	}
	//이항계수
	return ret = (dp(n -1, k) + dp(n -1, k - 1)) % 10007;
}

int main() {
	int n, k;
	cin >> n >> k;
	memset(num, -1, sizeof(num));
//기본값설정
//이항계수값이 1인 경우
	for (int i = 0; i <= n; i++) {
		num[i][i] = 1;
		num[i][0] = 1;
	}
	cout << dp(n, k);
	return 0;
}

```

### 3. 백준 12865번 평범한 배낭
 <br/><https://www.acmicpc.net/problem/12865>

### 배낭문제란???
 - 배낭에 담을 수 있는 무게의 최댓값이 정해져 있고, 일정 가치와 무게가 있는 짐들을 배낭에 넣을 때, 가치의 합이 최대가 되도록 짐을 고르는 방법을 찾는 문제이다.
 - 배낭문제는 짐을 쪼갤 수 있는 문제와 쪼갤 수 없는 문제가 있는데, 여기서는 쪼갤 수 없는 경우만 다루자!
 - 이 문제 역시 DP를 이용하면 해결 가능하다.
<br/>
<br/>
 - 최적해에서 n번째 짐까지 담을 수 있고, 최대 무게가 m일때의 가치는 유일하다.
 - 고로, 이는 여러 번 계산할 이유가 없다.
 - 배열을 dp[n][m]로 잡고 bottom-up으로 구현하자!
 - i번째 짐을 추가하지 않는 경우 가치는 **dp[i-1][m]**이고
 - i번째 짐을 추가하는 경우 가치는 **dp[i-1][m-짐의 무게] + 짐의 가치**가 될 것이다.
 
 
 ```
for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        item[i] = { a, b };//무게, 가치
}

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
        //i번째 짐 추가 안함
        knapsack[i][j] = max(knapsack[i][j], knapsack[i - 1][j]);
        if (j - item[i].first >= 0) {
                //i번째 짐 추가함
            knapsack[i][j] = max(knapsack[i][j], knapsack[i - 1][j - item[i].first] + item[i].second);
        }
    }
}
//출력
cout << knapsack[n][k];
```
    


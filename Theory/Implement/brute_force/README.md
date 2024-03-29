# 완전 탐색(brute-force)

  1. 완전 탐색 ~알고리즘~은 이름 그대로 모든 경으의 수를 일일이 탐색하면서 답을 찾는 방법이다.
  2. 이 방식의 장점은 예외없이 답을 찾아낼 수 있다는 점이지만,
  3. 단점은 시간이 오래 걸린다는 점이다. 
  4. 따라서, 시간을 줄일 수 있는 방안을 생각해봐야 한다.

## 재귀 함수(recursion function)
  1. 재귀 함수란 함수안에서 자기 자신을 호출하는 함수를 말한다.
  2. 완전 탐색 문제는 주로 여러 개의 선택지 중 몇 개를 선택하는 과정(조합)이다.
    - 이를 **반복문 대신 재귀함수**를 사용하면 쉽게 구현이 가능하다.
  3. 기저 조건(basis case)를 정해 함수가 무한 루프에 빠지는 것을 방지해야 한다. 
  
  
---
  
## 연습문제를 풀어보자!!
   **1. 백준 2309번 일곱난쟁이**
   <br/> <https://www.acmicpc.net/problem/2309>
   - 아홉 명중 일곱 명을 선택했을 때 그들의 키의 합이 100을 만드는 문제이다.
   - 즉, 9개 중 7개를 선택해(조합) 정답인지 확인하면 된다.
   - 먼저 재귀함수를 사용해 풀어보자
   
   * 핵심 코드
   
   ```
	//deep번째, 위치, 지금까지 합
	int solve(int deep, int pos, int sum) {
		//기저조건, 7명 모임
		if (deep == 7) {
			//합이 100이면
			if (sum == 100) {
				//출력
				for (int i = 0; i < 9; i++) {
					if (check[i])
						cout << num[i] << "\n";
				}
				return 1;
			}
			return 0;
		}
		for (int i = pos; i < 9; i++) {
			check[i] = true;
			//i번째 난쟁이 포함
			if (solve(deep + 1, i + 1, sum + num[i]))
				return 1;
			check[i] = false;
			//i번쩨 난쟁이 미포함
			if (solve(deep, i + 1, sum))
				return 1;
		}
		return 0;
	}

```
   - **그런데,** 이를 반복문을 이용해 풀 수 있다.
   - 7중 for문을 돌리면 된다.
   - 하지만 이는 손이 아프다. ~복사 붙여넣기만 잘하면 되긴함~
   - **9명중에 난쟁이가 아닌 2명을 고른다면??**
   - 2중 for문만 돌리면 된다.
   
   * 핵심 코드 (자세한 건 전체 코드를 보자!
	
   ```
   for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			//7명의 합이 100일때
			if (sum - num[i] - num[j] == 100) {
				//정렬했을때 뒤로 빠지도록 설정
				num[i] = INF;
				num[j] = INF;
				//탐색 종료
				i = 9;
				break;
			}
		}
	}
```

---
	
**2. 백준 5520번 The Clocks**
<br/> <https://www.acmicpc.net/problem/5520>
 - 9개의 시계를 모두 12시로 맞추기 위해서 스위치를 최소한 몇 번 눌려야하는지 구해
 - 눌러야하는 스위치를 오름차순으로 출력하는 문제이다.
 - 이 문제의 핵심은 같은 스위치를 4번이상 누를 필요가 없다는 것이다.
 - 같은 스위치를 4n + k (1 <= k <= 3)번 누른 것은 k번 누른 것과 같은 효과이기때문이다.  
 - 때문에 어떤 스위치를 얼마나 눌러야하는지 찾는 문제가 되고 
 - 이는 완전탐색으로 적어도 4^9만에 찾을 수 있다. 
 
 * 코드는 생략 ^^ ~전체 코드를 보자!~
 
 
 ---
 
 **3. 백준 14927번 전구 끄기**
 <br/> <https://www.acmicpc.net/problem/14927>
 - 전구 모두 끄기 위해를 누르는 횟수의 최솟값을 구하면 된다.
 - 핵심은 모든 전구는 **1번 이하로만** 눌려야한다는 것과
 - [i-1][j]번 전구를 끄기 위해서는 [i][j]번 전구를 눌려야한다는 점이다. 
 - 즉, [0][j]번째 전구를 누를지 말지를 결정하면 전구판을 전부 끄수 있는지 여부는 결정된다.
 - 따라서 2^18번의 경우의 수를 일일이 따져보자.
 

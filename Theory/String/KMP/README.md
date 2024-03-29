# KMP algorithm
 - 대표적인 문자열 검색 알고리즘(string search algorithm)이다.
 - 문자열 검색은 주어진 문자열에서 패턴 P인 문자를 찾는 것이다.
 - KMP algorithm은 Knuth, Morris, prett 세 사람이 만든 알고리즘이라 KMP라고 불린다.
 
 ---
 
 ** 본격적으로 KMP알고리즘을 공부하기 전에 string search를 brute force(완전 탐색)을 이용해 해보자
 
## 일반적인 문자열 검색 알고리즘(Naive String Searching Algorithm)
 1. 패턴 문자를 주어진 문자열의 왼쪽에서 오른쪽으로 한 칸씩 이동하면서 비교해보자.

| text | A | B | C | A | B | A | A | B | C | A | B | A | C |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|pattern| A | B | A | A | | | | | | | | | |

 2. pattern의 문자와 text의 대응하는 문자가 일치하는지 확인한다
   ->일치하지 않으므로 오른쪽으로 한 칸!!!(두번째)

| text | A | B | C | A | B | A | A | B | C | A | B | A | C |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|pattern| |  A | B | A | A | | | | | | | | |

 3. **다시** 한칸!!(세번째) 
 
| text | A | B | C | A | B | A | A | B | C | A | B | A | C |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|pattern| | |  A | B | A | A |  | | | | | | 

4. 한번 더!!(네번째)

| text | A | B | C | A | B | A | A | B | C | A | B | A | C |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|pattern| | | |  A | B | A | A | | | | | | | | 

 5. 네번째에 pattern이 존재함을 확인할 수 있었다.
 
 6. 이러한 과정을 왼쪽끝까지 해주면 된다.
  - text의 길이가 n, pattern의 길이가 m이라고 하면, 시간복잡도는 **nm**이 된다.
 
## 예제
 - 이쯤에서 연습문제를 풀어보자
 - 백준 10769번 <https://www.acmicpc.net/problem/10769>
  * 오른쪽에서 왼쪽으로 가면서 행복이모티콘, 불행이모티콘이 있는지 확인하면 된다.
   * 문자열의 최대길이가 255이므로 충분히 1초안에 해결가능하다.
   
--- 

### ~쉬었다 가기 잠시만~

---

## KMP 알고리즘
 1. 위와 같은 알고리즘은 느리다.
 2. 빠르게 계산하기 위해서는 연산을 줄여야한다.
 3. 연산을 굳이 안해도 되는 index가 있지 않을까?
 4. 연산을 안해도 되는 부분(중복되는 부분)이 있다면 조금은 빨라질 것이다.
 
 ---
 
| text | A | B | C | A | B | A | A | B | C | A | B | A | C |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|pattern| A | B | A | A | | | | | | | | | |
 
 - 0번째 index부터 비교하면서 AB까지는 맞는 것을 확인했다.
 - 고로, 오른쪽으로 한칸 이동했을때 text의 1번 index는 B라는 것을 우리는 이미 알고, 일치하지 않는다것을 예측할 수 있다.
 - 바로 2번째 index로 넘어가자.
 
| text | A | B | C | A | B | A | A | B | C | A | B | A | C |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|pattern| | | A | B | A | A | | | | | | | | 

 - 이러한 사실을 잘 생각해보면, 검색에 실패했을 때 시작위치를 조정할 수 있다.
 - 시작 위치를 **Pi 배열(failure function)** 을 통해 알 수 있다. 
 - pi 배열은 다음과 같이 정의 되어 있다.
 
 ``` pi[i] = pattern[...i]의 접두사도 되고 접미사도 되는 문자열의 최대 길이```
 
  - KMP알고리즘의 순서는 다음과 같다.
  	1. text에서 i번째 index에서 검색을 시작한다.
 	2. 실패했을 경우, 틀린 index에서 검색을 재게하되 단어에서 몇번째 문자부터 검색해야되는지 찾는다.
  	3. 틀린 index가 i번째가 되어 검색을 시작한다.
  	4. 검색에 성공하면 종료한다.
  
  ---
  ---
  ---
  
  
  **~사실 봐도 모르니~ 예제 코드와 예시로 이해해보자!!!**
  ### 집중! 집중!
  
  
  ```
  bool kmp(string text, string pattern) {
		int n = text.size();
		int m = pattern.size();
		//검색을 시작하는 위치
		int start = 0;
		//pattern과 일치하는 문자열의 길이
		int matched = 0;
		while (start <= n - m) {
			//검색에 성공했을 때
			if (matched < m && text[start + matched] == pattern[matched]) {
				matched++;
				//정답 추가(완벽히 일치할 때)
				if (matched == m) {
					//정답
					return true;
				}
			}
			//검색에 실패했을때
			else {
				//예외: 일치하는 바가 없으면 오른쪽으로 한칸
				if (matched == 0) {
					start++;
				}
				else {
					start += matched - pi[matched - 1];
					matched = pi[matched - 1];
				}
			}
		}
		//실패
		return false;
	}
```

- text가 ABCDABCDABEE이고 pattern이 ABCDABE이라고 하자.

|index|  0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| text | A | B | C | D | A | B | C | D | A | B | E | E |
|pattern|  A | B | C | D | A | B | E | | | | | | |

```start = 0, macthed = 0```
- 처음 상태이다. 6번째 index에서 불일치가 일어났다.
- 이때, start = 0, mached = 6이고, pi[5]값을 가져오자!
- pi[5] = 2이다. (잠시후 알아볼 예정이다. **찡긋><**)
- 고로, start = 4, mached = 2인 상태로 다시 seaching하자!

|index|  0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| text | A | B | C | D | A | B | C | D | A | B | E | E |
|pattern|  | | | |A | B | C | D | A | B | E | | | | 

- 이 경우, matched = 7이된다.
- pattern의 길이가 7이므로 탐색을 종료하게 된다.

 ---
 
 ### Pi 배열
 
  - pattern 배열이 ABCDABE이라고 하자. pi배열은 다음과 같다.
 
 | patter[i] | A | B | C | D | A | B | E | 
 |:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
 |i| 0 | 1 | 2 | 3 | 4 | 5 | 6 |
 |pi[i]| 0 | 0 | 0 | 0 | 1 | 2 | 0 | 
 
 - pattern 배열에 자기자신을 KMP알고리즘을 활용해 pi 배열을 구할 수 있다.
 
 
 
 ```
 void get_pi(string pattern) {
	int len = pattern.size();
	//start = 0에서 시작하면 바로 matched = len이 된다.
	//pi[0] = 0으로 처리하자
	pi[0] = 0;
	//pi[0] = 0이므로 1부터 탐색
	int start = 1;
	int matched = 0;
	while (start + matched < len) {
		//일치할 때
		if (pattern[start + matched] == pattern[matched]) {
			pi[start + matched] = 1 + matched;
			matched++;
		}
		//일치하지 않을 때
		else {
			if (matched == 0) {
				start++;
			}
			else {
				start += (matched - pi[matched - 1]);
				matched = pi[matched - 1];
			}
		}
	}
}
```



### 연습문제를 풀어보자!!!
- 백준 1786번 찾기 <https://www.acmicpc.net/problem/1786>

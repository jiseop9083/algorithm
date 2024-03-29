# 비트 마스크 (Bit Mask)

## 비트 마스크란?
 - 컴퓨터가 이진수 연산을 빨리한다는 점을 이용해 자료를 표현하는 방식이다.
 - 비트 마스크는 빠른 수행시간, 간결한 코드, 적은 메모리 사용이라는 장점이 있다.
 - 예를 들어, boolean으로 저장해야할 데이터를 비트마스크로 저장하면 메모리를 8배 줄일 수 있다.

## 비트 마스크 사용법
- 어떤 비트의 위치가 1이면 해당 비트가 "켜져 있다"라고 하고
- 어떤 비트의 위치가 0이면 해당 비트가 "꺼져 있다"라고 한다.
- 자료를 사용하기 위해서는 비트연산자에 익숙해야 한다.
- 자료에 접근하는 방법을 정리해보자 (c++ 기준이다)

|접근법|예시|설명|
|:---:|:---:|:---:|
|공집합 구하기|int bit = (1 << 20); |0~19번째를 0으로 초기화|
|꽉 찬 집합 구하기|int bit  = (1 << 20) - 1; | 0~19번째를 1로 초기화| 
|원소 추가| bit or= (1 << P); |p번 비트를 1로 바꿈|
|원소의 포함 여부 확인|if(bit & (1 << p)) | bit안에 p번째 원소가 있으면 실행|
|원소의 삭제| bit &= ~(1 << p); | p번째 비트를 0으로 바꿈 |
|원소의 토글| bit ^= (1 << P); | p번째 비트가 켜져있으면 끄고 꺼져있으면 켜기 |
|최소 원소 찾기|int firstbit = (bit & -bit); |켜져있는 비트 중 가장 작은 비트 |
|최소 원소 지우기| bit &= (bit - 1); |켜져있는 비트 중 가장 작은 비트 끄기 |
|모든 부분 집합 순회하기|for(int subset = bit; subset; subset = ((sebset - 1) & bit))| 부분 집합 |

---

## 문제 풀자!
### 백준 2098번 외판원 순회
- 대표적인 비트마스킹 + DP문제이다.
- TSP문제라고 불리는 외판원 순회 문제에 익숙해질 필요가 있다.
- 이 문제를 풀기 위해서 특정도시를 방문한 상태를 저장해야한다.
- 도시의 방문상태를 비트마스킹을 이용하여 하나의 정수로 표현하면
- 2차원 DP를 이용해 풀 수 있다.
- int city[visit][pos]; //visit는 도시의 방문상태, pos는 현재 위치, city의 값은 최소비용
- 예를 들어, 0~3번 도시까지 있다고 가정하면 도시의 방문상태는 다음과 같이 저장할 수 있다!

|  | 이진수 | 3번 도시 | 2번 도시 | 1번 도시 | 0번 도시 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 1 | 0000 | x | x | x | x |
| 2 | 0001 | x | x | x | o |
| 3 | 0010 | x | x | o | x |
| 4 | 0011 | x | x | o | o |
| 5 | 0100 | x | o | x | x |
| 6 | 0101 | x | o | x | o |
| 7 | 0110 | x | o | o | x |
| 8 | 0111 | x | o | o | o |
| 9 | 1000 | o | x | x | x |
| 10 | 1001 | o | x | x | o |
| 11 | 1010 | o | x | o | x |
| 12 | 1011 | o | x | o | o |
| 13 | 1100 | o | o | x | x |
| 14 | 1101 | o | o | x | o |
| 15 | 1110 | o | o | o | x |
| 16 | 1111 | o | o | o | o |


- 다음의 핵심코드는 외판원 순회문제를 top-down 방식으로 구현한 것이다. 

```
int dp(int visit, int pos) {
	int& ret = city[visit][pos];
	if (ret != -1) {
		return ret;
	}
	//큰 값을 넣자
	ret = INF;
	for (int i = 0; i < n; i++) {
		//이동할 수 없거나 방문했던 곳이면 패스
		//!(visit & ( 1 << i ))는 i번째 원소가 0이면 
		if (cost[i][pos] == 0 || !(visit & (1 << i))) {
			continue;
		}
		//i번째 도시에서 오는 경로 확인 후 업데이트
		ret = min(ret, cost[i][pos] + dp(visit&(~(1 << pos)), i));
	}
	return ret;
}
```
 

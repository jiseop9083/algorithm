# 분할 정복(divide and conquer)

  ## 분할정복이란?
   1. 커다란 전체 문제를 각각의 작은 문제로 나누어(**divide**)
   2. 분할하지 않고 풀 수 있는 기저 조건(**base case**)에서 해결한 다음,
   2. 각 문제를 합쳐서 합쳐서(**conquer**) 문제 해결하는 알고리즘이다.
   3. 분할 정복의 중요한 특징 중 하나는 **각각의 부분문제를 해결하는 방식이 똑같다는 점이다**
   4. 이러한 점에서 분할 정복을 구현하기 위해 보통 재귀함수를 많이 사용하게 된다!
   
   
  ## 분할정복 특
   1. 일반적으로 큰 문제를 크기가 거의 같은 부분 문제로 나눈다.
   2. 하지만, 꼭 같은 크기로 나눌 필요는 없다. (하나의 작은 문제와 나머지로 나누어도 된다.)
   3. 꼭 큰 문제를 작은 두 문제로 누눌 필요는 없다. (세 문제, 네 문제, 그 이상으로 나누어도 된다.)
   
   ---
   
  ## 연습 문제를 보자!
   **1. 병합 정렬(merge sort)**
     - merge sort에 관해서는 정리해 놓았다.
     - 다음 자료를 참고하자!
     <br/> <https://github.com/jiseop9083/algorithm/tree/master/sort/merge%20sort>
     
   ---
     
  **2. 백준 11729번 하노이 탑 이동 순서**
     - 대표적인 작은 문제와 나머지로 나누어 해결할 수 있는 문제이다.
     - 현재 n개의 원판 있는 곳을 start, 원판을 이동시킬 목적지를 end, 남은 한 자리를 mid라고 하자.
     - start에서 end로 n개를 이동시키는 방법을 나누어 생각해보자
    <br/>
    <br/>
    **생 각 중**
    <br/>
    <br/>
    <br/>
    <br/>
    <br/>
    <br/>
    <br/>
    <br/>
    <br/>
    <br/>
    <br/>
    <br/>
    <br/>
    <br/>
 - **n-1개의 원판을 start에서 mid로 옮기고, n번째 원판을 start에서 end로, 마지막으로 n-1개의 원판을 mid에서 end로 옮기는 과정을 나눌 수 있다!!!!!!!!**
     
 - 방법을 알았으면 구현해보자!
     
  - 핵심 코드
  ```
    //원판 개수, 시작점, 남은 한 자리, 도착점
    void slove(int deep, int start, int mid, int end) {
	    //원판이 없으면 이동X
	    if (deep == 0) {
		    return;
	    }
	    //n-1개의 원판 start->end
	    slove(deep - 1, start, end, mid);
	    //n번째 원판 이동(출력)
	    cout << start << " " << end << "\n";
	    //n-1개의 원판 mid->end
	    slove(deep - 1, mid, start, end);
    }
```

---

  **3. 백준 1725번 히스토그램**
   - 히스토그램에서 가장 큰 직사각형의 넓이를 출력하면된다.
   - 브루트 포스(완전 탐색)으로 생각해보자
   - 시작점이 i번째이고 끝 점 j번째라고 생각해보자
   - 순회하면서 O(n^2)만에 문제를 해결할 수 있다.
   - 하지만 n은 10만이고 시간 제한이 2초이므로 완전 탐색으로 시간 내에 해결하는 것은 힘들다.
   - 분할 정복 알고리즘을 사용하자.
   - 가장 큰 직사각형이 왼쪽 부분에 있는 경우, 오른쪽에 있는 경우, 중간에 걸쳐있는 경우로 나눌 수 있다.
   - 이제, 핵심코드를 살펴보면서 알아보자!
   
   
```
   int histo(int start, int end) {
	//막대가 하나일때
	if (start == end) {
		return num[start];
	}
	int mid = (start + end) / 2;
	//왼쪽과 오른쪽확인
	int ret = max(histo(start, mid), histo(mid + 1, end));
	//왼쪽으로 가는 변수
	int left = mid;
	//오른쪽으로 가는 변수
	int right = mid + 1;
	int height = min(num[left], num[right]);
	ret = max(ret, height * 2);
	while (start < left || right < end) {
		//오른쪽으로 가는 경우
		//1. left가 끝까지 탐색했을 때
		//2. 오른쪽이 왼쪽보다 더 클 때
		if (right < end && (left == start || num[left - 1] < num[right + 1])) {
			right++;
			height = min(height, num[right]);
		}
		//그 외의 경우는 왼쪽으로 가자
		else {
			left--;
			height = min(height, num[left]);
		}
		//매번 직사각형 넓이 구하기
		ret = max(ret, height * (right - left + 1));
	}
	return ret;
}

```
- 위와 같이 분할정복을 이용하면 시간복잡도가 O(nlogn)이 되어 시간 내에 해결이 가능하다.
 
 
**4. 백준 2261번 가장 가까운 두 점**
  - 문제는 간단하다. 이차원 평면 상의 가장 가까운 두 점의 거리를 구하면 된다.
  - 직관적으로 떠오르는 알고리즘은 아마 브루트 포스일 것이다.
  - 하지만, n이 10만인 것을 보고 O(n^2)의 시간복잡도로는 어림도 없다는 것을 알게 된다.
  - 이 문제의 **한 가지** 풀이는 분할정복을 이용하는 것이다.
  - y축 기준으로 정렬된 점 P1, P2, .... , Pn까지 있다.
  - 

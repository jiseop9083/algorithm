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

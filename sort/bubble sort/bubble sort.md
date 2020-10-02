# 정렬 알고리즘(sort algorithm)
## 1. 정렬이란?
 - 어떠한 데이터를 순서대로 정리하는 작업
 - 정렬을 하면 원하는 데이터를 빠른 속도로 찾는데에 도움이 된다!
 - ~~물론, 정렬하는데 시간을 많이 소모한다면 정렬의 의미가 사라지겠죠~~
 
 -  **고로 정렬을 빠르게 할 필요가 있다!**

## 2. 거품정렬(bubble sort)
 - 인접한 원소를 검사하여 정렬하는 알고리즘이다
 - 마치 정렬하는 과정이 거품이 올라오는 것 같다.
 - 
 
 ### procedure buble sort
  - (a[1], a[2],....,a[n] : real number, n >= 2)
  ```
  for i= 1 to n- 1
      for j:= i to n- i
          if a[j] > a[j + 1] then interchange aj and aj+i
  return max {a[1], ...., a[n] is in increasing order}
   ```

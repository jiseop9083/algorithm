# 선택 정렬(selection sort)
  - 선택정렬은 가장 작은 원소를 선택해 차례대로 앞자리에 넣는 정렬 방법이다.
  
  ## proceure code
  ```
  for i: = 2 to n
       m = a(i)
       j = i-1
       while(j > 0 and a > m)
           a(j + 1) = a(j)
           j := j - 1
      a(j + 1) := m
  return (a,...... a(n) is in increasiong order}
          

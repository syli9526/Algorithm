# 탐욕법(GreedyAlgorithm)

그리디 알고리즘이란 "매 선택에서 지금 이 순간 당장 최적인 답을 선택하여 적합한 결과를 도출하자"라는 모토를 가지는 알고리즘 설계기법이다. 그리디 알고리즘은 한번의 선택이 다음 선택에는 전혀 무관한 값이여야 하며 매 순간의 최적해가 문제에대한 최적해여야한다.

* 예)동전나누기 = 반드시 큰 쪽은 작은 쪽 액수의 배수여야하는 성질 

![image](https://user-images.githubusercontent.com/48287388/55136696-7aceb700-5172-11e9-9492-eef115b4b787.png)

지금 A지점에 서있다고 했을때, 좌우로 적절히 이동하여 최대 높이에 다다르려고 한다. 높이가 높을수록 이득이 크다. 보다시피 m은 그 근처에서는 최대 높이 이지만 전체로 보았을때는 최대가 아니다. 

 전체 상황을 모르는 상황에서는 전체적인 최적해인지, 지역적인 최적해인지 판단하기 힘들다는 단점이 있다.

##### 

---

###### 1. 탐욕법 문제

1. 4796  캠핑 <https://www.acmicpc.net/problem/4796>

2. 1493 박스채우기 <https://www.acmicpc.net/problem/1493>

3. 13904 과제 <https://www.acmicpc.net/problem/13904>

4. 1449 수리공항승 <https://www.acmicpc.net/problem/1449>

5. 11047 동전 0 <https://www.acmicpc.net/problem/11047>

6. 1931 회의실 배정 <https://www.acmicpc.net/problem/1931>

7. 11000 강의실 배정 <https://www.acmicpc.net/problem/11000>

8. 1700 멀티탭 스케줄링 <https://www.acmicpc.net/problem/1700>

9. 2217 로프 <https://www.acmicpc.net/problem/2217>

10. 1969 DNA <https://www.acmicpc.net/problem/1969>

11. 2212 센서 <https://www.acmicpc.net/problem/2212>

      

> 백준 알고리즘


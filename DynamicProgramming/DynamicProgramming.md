# 동적계획법 (Dynamic Programming)

* 동적계획법이란, 복잡한 문제를 작은 부분문제(sub -problem)로 나누어 해결하는 기법이다. 동적 계획법의 특징 중 하나는 이미 계산된 부분문제가 다시 발생하면 새롭게 계산하지 않고 이전의 계산값을 참조하여 이용하는 것이다. 이 방법은 시간을 절약할 수 있지만, 이전 계산값을 저장해둘 공간이 필요하므로 시간과 메모리의 trade-off라고 할 수 있다.

  동적 계획법이 사용되는 대표적인 예로 피보나치 함수 계산을 보자. 피보나치 함수란 다음과 같이 정의된다.

  <center> f(N) = f(N-1)+f(N-2) (f(0) = 1, f(1) = 1) </center>

<center><img width="464" alt="스크린샷 2019-03-11 오후 12 55 01" src="https://user-images.githubusercontent.com/48287388/54100154-695e7e80-4400-11e9-896f-15d9848ee6b8.png"></center>



​	피보나치 수열을 단순 탐색으로 구현한다고 하면 위와 같이 f(3)이 2번, f(2)는 3번, f(1)은 4번 f(0)은 3번 호출이 된다.

​	f(n)에 대한 결과값은 언제나 일정하므로, 같은 파라미터를 가진 함수를 중복 호출하는것은 굉장히 비효율적이다. 

​	이를 해결할 수 있는 것이 Memoization이다.

​	Memoization이란, 한번 계산된 값을 기록해두고 이후 중복 호출되었을때 새롭게 계산하는 것이 아닌 저장해 둔 값을 가져	와 사용하는 방법이다. Memoization을 사용한다면 위 함수의 호출은 각 파라미터당 한번씩만 호출하게 된다.



######1. Top-down 과 Bottom-up

동적 계획법의 구현은 크게 Top-Down방식과 Bottom-Up방식으로 나뉘어진다. Top-Down방식은 큰 문제에서 작은 부분문제를 재귀적으로 호출하여 리턴 되는 값을 이용하여 큰 문제를 해결하는 방식이다. 중복되는 부분문제를 피하기 위해 앞서 소개한 Memoization기법을 함께 사용하며, 위에서 다룬 피보나치 함수의 구현방법 또한 이에 속한다.

반대로 Bottom-Up방식은 작은 부분문제들을 미리 계산해두고, 이 부분문제들을 모아 큰 문제를 해결하는 방식이다. 일반적으로 배열에 값을 채워나가는 형태로 구현한다.

두 가지 방법은 각각의 장단점이 있다. Top-Down방식의 경우, 재귀함수를 통해 구현되므로 함수 호출에 대한 오버헤드가 발생한다. 반면 Bottom-Up방식의 경우 반복문을 통해 구현되므로 이러한 자원에 비교적 자유로워 시간 및 메모리의 최적화가 쉽다.

하지만 Bottom-Up방식의 경우 큰 문제를 해결하기까지 어떠한 sub-problem이 요구되는지 알 수 없으므로 전체 문제를 계산하기 위해 모든 부분문제를 해결해야 한다. 하지만 Top-Down방식의 경우 큰 문제를 해결하기 위해 필요한 sub-problem만을 호출하므로 필요한 부분만 계산하게 되어 특정한 경우에는 Bottom-Up방식보다 빠르게 동작할 수 있다.

###### 2. DP 대표 코드(동전교환문제)

~~~c++
#include <iostream>
using namespace std;

int coin[100], d[10001];

int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        cin >> coin[i];
    }

    for(int i = 1; i <= k; i++) {
        d[i] = -1;
        for(int j = 0; j < n; j++) {
            if(coin[j] <= i) {
                if(d[i - coin[j]] < 0) continue;
                if(d[i] < 0) d[i] = d[i - coin[j]] + 1;
                else if(d[i - coin[j]] + 1 < d[i]) d[i] = d[i - coin[j]] + 1;
            }
        }
    }

    cout << d[k] << "\n";
    return 0;
}
~~~



----

* DP문제 

  1. 1463 1로 만들기_ver.1  <https://www.acmicpc.net/problem/1463>
     - Top - down 방식

  2. 1463 1로 만들기_ver.2  <https://www.acmicpc.net/problem/1463>
     - Bottom -up 방식

  3. 9465 스티커 <https://www.acmicpc.net/problem/9465>
     - Bottom -up 방식

  4. 11055 가장 큰 증가 부분수열 <https://www.acmicpc.net/problem/11055>
     - Bottom -up 방식

  5. 12865 평범한 배낭 <https://www.acmicpc.net/problem/12865>
     - Bottom -up 방식

  6. 2294 동전2 <https://www.acmicpc.net/problem/2294>

     

  > 출처 백준 알고리즘




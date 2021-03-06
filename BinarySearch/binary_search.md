# 이진탐색(Binary Search)

* 이진탐색(Binary Search)은 정렬된 배열에서 원하는 값을 시간복잡도 O(log N) 만에 찾아내는 탐색 방법
* 오름차순으로 정렬된 사이즈가 N인 배열 D에서 원하는값 k를 찾는 방법은 다음과 같다 (k = 10)


###### 1. 이진탐색 

| L     |       |       | M     |       |       |       | R     |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| **0** | **1** | **2** | **3** | **4** | **5** | **6** | **7** |
| -2    | -1    | 0     | 3     | 6     | 7     | 10    | 11    |

 먼저 탐색할 데이터의 범위를 두개의 인덱스 ( L, R )로 정한다.  정렬된 배열이기 떄문에 D[L]은 최솟값, D[R]은 최대값이 된다.

당연히 처음 탐색시 전체영역의 중앙값을 찾아 찾으려는 값 k와 비교한다. 중앙값은 (L+R)/2로 구한다.

중앙값인 D[M]과 k를 비교했을때, k의 값이 더 크므로 [0,M] 범위내에는 k가 존재할 수없다. 그러므로 L을 M+1로 옮겨 [M+1,R]사이에서 k값을 찾는다.

위 과정을 반복한다.                                                                                             

|       |       |       |       | L     | M     |       | R     |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| **0** | **1** | **2** | **3** | **4** | **5** | **6** | **7** |
| -2    | -1    | 0     | 3     | 6     | 7     | 10    | 11    |

|       |       |       |       |       |       | L/M   | R     |
| ----- | ----- | ----- | ----- | ----- | ----- | ----- | ----- |
| **0** | **1** | **2** | **3** | **4** | **5** | **6** | **7** |
| -2    | -1    | 0     | 3     | 6     | 7     | 10    | 11    |

이 알고리즘의 시간복잡도는 쿼리당 O(logN)으로 빠른 알고리즘이다. 

정렬 알고리즘 또한 힙 또는 퀵 정렬을 사용하면 더 효율적이다.



###### 2. 이진탐색 기본 코드

~~~c++
#include <iostream>
#include <algorithm>

#define MAX 5005

int d[MAX], n;

bool bsearch(int val){

	int l = 0, r  = n - 1;

	while(l <= r){
		int mid = (l+r)/2;

		if(val == d[mid]) return true;
		else if(val > d[mid]) l = mid + 1;
		else r = mid - 1;
	}

	return false;
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		cin >> d[i];

	sort(d, d + n);

	int query;

	cin >> query;

	while (query--) {
		int x; cin >> x;

		if (bsearch(x)) cout << "exist" << endl;
		else cout << "not exist" << endl;
	}
}
	
~~~



-----

* 이진탐색 문제
  1. [**1920 수 찾기**](https://www.acmicpc.net/problem/15732)
  2. [**15732 도토리 숨기기**](https://www.acmicpc.net/problem/15732)
  3. [**2130 수조**](https://www.acmicpc.net/problem/2130)
  4. [**10815 숫자카드**](https://www.acmicpc.net/problem/10815)
  5. [**2805 나무자르기**](https://www.acmicpc.net/problem/2805)
  6. [**1654 랜선 자르기**](https://www.acmicpc.net/problem/1654)
  7.  [**3020 개똥벌레**](https://www.acmicpc.net/problem/3020)





> 백준 알고리즘


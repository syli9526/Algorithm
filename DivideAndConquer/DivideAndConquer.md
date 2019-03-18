# 분할정복(Divide and Conquer)

분할정복(Divide and Conquer)은 말 그대로 문제를 분할한 다음, 분할한 문제들 (sub-problems)을 해결하고, 그 결과를 합쳐서 원래의 문제를 해결하는 것이다.
분할정복의 대표적인 예로는 합병 정렬(merge sort),이분탐색(binary search), 거듭제곱 연산(a^b) 고속 푸리에 변환(fast Fourier transform) 등이 있다.





##### 1. 합병정렬 예시

![image](https://user-images.githubusercontent.com/48287388/54517642-a0570600-49a5-11e9-9a48-984f3fd4c84d.png)



영역을 나눈 후, 나누어진 영역을 투 포인터(Two Pointer) 알고리즘으로 합병하는 방식으로 동작한다
투 포인터 알고리즘을 사용하려면 나눠진 영역이 정렬이 되어있어야 하기 때문에 먼저 영역을 작게 나눈 후 합치는 재귀적인 방법이 사용되며, 투 포인터 챕터에서 더 자세히 다루기로 하자.

알고리즘 수행시간은 분할할 때 ① 나누어지는 문제의 개수 ② 분할 후 문제의 크기 ③ 각 문제마다 병합단계에서 걸리는 시간에 따라 달라진다. 합병 정렬의 경우 분할할 해당 문제의 크기를 N이라고 할 때,  ① 2 , ②  N/2, ③O(N)이다. 

합병 할 때에 걸리는 시간이 해당 문제의 크기가 N일때  O(N) 이다. 각 단계별로 드는 연산 횟수를 나열해보면,

0단계 : 1*O(N)

1단계 : 2*O(N/2)

2단계 : 4*O(N/4)

...

m단계 : 2^m*O(N/(2^m)) = O(N)

각 단계에서 드는 총합 연산량은 O(N)이다. 총 단계의 수는 O(logN)이므로 합병정렬의 시간복잡도는 O(NlogN)이다. 위의 문제처럼 문제를 쉽게 해결 가능한 문제가 될 때까지 나눈 후 해결하고 합치는 과정을 반복하는 해법을 분할정복이라고 한다.

위의 경우에는 분할된 문제(sub-problem)이 중복이 되지 않지만 피보나치를 구하는 문제는 분할된 문제가 중복이 되는 경우가 있다.

![image](https://user-images.githubusercontent.com/48287388/54518586-ffb61580-49a7-11e9-885f-29c1dc4cd972.png)

위의 음영 처리된 부분은 중복된 sub-problem으로 이를 분할할 때마다 처리한다면 매우 비효율적일 것이다. 이와 같은 문제는 분할정복보다는 동적계획법의 Top-Down 접근법(Memoization)으로 접근하는 것이 효율적이다.



#####2. 분할정복 알고리즘 묘사도

![divide_conquer_3_steps](https://user-images.githubusercontent.com/48287388/54517430-05f6c280-49a5-11e9-84e6-08be79e0481a.png)







##### 3. 분할정복 기본 코드 (합병정렬)

~~~c++
#include <iostream>

#define MAX 5005

using namespace std;

int d[MAX];
int temp[MAX];

void MergeSort(int L, int R) {
	if (L >= R) return;

	int M = (L + R) / 2;

	// Divide

	MergeSort(L, M);
	MergeSort(M + 1, R);

	// Conquer

	for (int i = L, l = L, r = M + 1;
		l != M + 1 || r != R + 1;
		i++) {

		if ((r != R + 1 && l <= M && d[l] < d[r]) || r == R + 1)
			temp[i] = d[l++];
		else
			temp[i] = d[r++];
	}

	for (int i = L; i <= R; i++)
		d[i] = temp[i];
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> d[i];

	MergeSort(0, n - 1);

	for (int i = 0; i < n; i++)
		cout << d[i] << " ";
}
	
~~~

---




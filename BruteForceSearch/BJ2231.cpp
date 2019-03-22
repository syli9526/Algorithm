#include <iostream>
#include <cstdio>

using namespace std;

int N, i, j, cnt = 0, temp;

int main() {

    scanf("%d", &N);
    i = N;
    while (i) cnt++, i /= 10; // 입력 받은 숫자가 몇자리 숫자인지 확인

    // 분해합은 N과 N을 이루는 각 자리 숫자의 합이고 각자리 숫자는 최대 9이기 때문에
    // 분해합 <= 생성자 9*(자리수)임.
    for (i = N - cnt * 9; i < N; ++i) {
        temp = i;
        for (j = i; j; j /= 10) temp += j % 10;
        if (temp == N)break; // 낮은 숫자부터 체크하며 분해합이 N 이면 체크 종료
    }
    printf("%d", i != N ? i : 0);


}
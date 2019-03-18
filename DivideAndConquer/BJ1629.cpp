#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

ll A, B, C, ans = 1;


int main() {

    scanf("%lld %lld %lld", &A, &B, &C);


    while (B > 0) {

        // 제곱근의 수가 홀수인 경우 A^(B/2)*A 로 나눌 수 있음
        if(B%2 ==1) ans = (ans*A)%C;
        A = (A*A)%C;
        B /= 2;

    }

    // 시간 복잡도 O(log B)

    printf("%lld", ans);


}
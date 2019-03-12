#include <iostream>
#include <algorithm>

using namespace std;
const int MAX = 1000000;

int N, D, K;
int A[MAX], B[MAX], C[MAX];

int main() {

    scanf("%d %d %d", &N, &K, &D);

    for (int i = 0; i < K; ++i) scanf("%d %d %d", &A[i], &B[i], &C[i]);

    int L = 0, R = N;

    while (R - L > 1) {

        int M = (L + R) >> 1;
        long long ans = 0;
        for (int i = 0; i < K; ++i) {
            int temp = min(M, B[i]); // 규칙i의 상자 최대번호와 탐색할 번호 중 작은 값
            if (temp >= A[i]) ans += (temp - A[i]) / C[i] + 1;
        }
        (ans >= D ? R : L) = M;
    }

    printf("%d", R);

}
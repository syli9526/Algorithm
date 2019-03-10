#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 100001;
int N, K, v, w, dp[MAX];

int main() {

    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &w, &v);
        for (int j = K; j >= w; j--)
            dp[j] = max(dp[j - w] + v, dp[j]);
    }
    printf("%d", dp[K]);
}
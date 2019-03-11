#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 100001;
int N, K, dp[MAX];

int main() {

    scanf("%d %d", &N, &K);

    fill(dp, dp + K + 1, 100000);

    for (int i = 0, x; i < N; ++i) scanf("%d", &x), dp[x] = 1;

    for (int i = 1; i <= K; i++)
        for (int j = i - 1; j > 0; j--)
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
    printf("%d", dp[K] < 100000 ? dp[K] : -1);

}
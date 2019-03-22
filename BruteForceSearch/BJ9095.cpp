#include <iostream>
#include <cstdio>

using namespace std;

int T, N;

int dp[12] = {1,};

int main() {

    scanf("%d", &T);

    for (int i = 0; i < 12; ++i) {
        dp[i] = i - 1 >= 0 ? dp[i] + dp[i - 1] : dp[i]; // 1을 더해 만들 수 있는 개수 추가
        dp[i] = i - 2 >= 0 ? dp[i] + dp[i - 2] : dp[i]; // 2를 더해 만들 수 있는 개수 추가
        dp[i] = i - 3 >= 0 ? dp[i] + dp[i - 3] : dp[i]; // 3을 더해 만들 수 있는 개수 추가
    }
    while (T--) {
        scanf("%d", &N);
        printf("%d\n", dp[N]);
    }
}
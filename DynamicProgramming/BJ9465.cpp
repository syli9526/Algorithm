#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 100000;

int value[2][MAX], dp[3][MAX];
int N, T;

int main() {


    scanf("%d", &T);


    for (int k = 0; k < T; ++k) {

        scanf("%d", &N);

        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < N; ++j)
                scanf("%d", &value[i][j]);


        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < N; ++j)
                dp[i][j] = 0;


        dp[0][0] = value[0][0];
        dp[1][0] = value[1][0];

        for (int i = 1; i < N; ++i) {

            dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + value[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + value[1][i];
            dp[2][i] = max(dp[0][i - 1], dp[1][i - 1]);

        }

        printf("%d\n",max(dp[0][N-1],dp[1][N-1]));

    }
}

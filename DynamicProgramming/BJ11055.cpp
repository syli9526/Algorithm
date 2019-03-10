#include <iostream>

using namespace std;

const int MAX = 1000;

int arr[MAX], dp[MAX];
int N, ans;


int main() {

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) scanf("%d", &arr[i]), dp[i] = arr[i];
    
    for (int i = 0; i < N; ++i) {
        for (int j = i - 1; j >= 0; j--)
            if (arr[j] < arr[i]) dp[i] = max(dp[j] + arr[i], dp[i]);
        ans = max(ans, dp[i]);
    }

    printf("%d", ans);

    return 0;

}
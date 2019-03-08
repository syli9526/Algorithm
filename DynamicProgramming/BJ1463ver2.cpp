#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 1000001;

int main() {

    int n;
    vector<int> dp(MAX);

    scanf("%d", &n);
    fill(dp.begin(), dp.end(), 100000000000);

    dp[1] = 0;

    for (int i = 1; i < n; ++i) {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        if (i * 2 < MAX) dp[i * 2] = min(dp[i * 2], dp[i] + 1);
        if (i * 3 < MAX) dp[i * 3] = min(dp[i * 3], dp[i] + 1);
    }

    printf("%d",dp[n]);


}




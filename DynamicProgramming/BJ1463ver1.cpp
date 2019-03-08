#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1000001;
int dp[MAX];

int function(int n) {


    if (n == 1) return 0;
    if (dp[n] != -1) return dp[n];

    int temp = function(n - 1) + 1;

    if (n % 3 == 0) temp = min(temp, function(n / 3) + 1);
    if (n % 2 == 0) temp = min(temp, function(n / 2) + 1);

    dp[n] = temp;

    return temp;
}


int main() {

    int n;
    scanf("%d", &n);
    fill(dp, dp + n + 1, -1);
    printf("%d", function(n));

}




/*
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long ll;
const int MAX = 10000;

int k, n;
ll map[MAX], l = 0, r = LLONG_MAX,ans;

int main() {

    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> k >> n;

    for (int i = 0; i < k; ++i) cin >> map[i] ;

    while (l <= r) {

        ll m = (r + l) >> 1;
        int cnt = 0;

        for (int i = 0; i < k; ++i) cnt += (map[i] / m);

        if(cnt >= n) l = m + 1,ans = max(ans,m);
        else r = m - 1;


    }

    cout << ans;


}

 */

#include <cstdio>

using namespace std;
const int MAX = 10000;
int k, n;
long map[MAX], l = 0, r = ((long)2<<31);

int main() {


    scanf("%d %d", &k, &n);

    for (int i = 0; i < k; ++i) scanf("%ld", &map[i]);

    while (l <= r) {
        long m = (r + l) >> 1;
        int cnt = 0;
        for (int i = 0; i < k; ++i) cnt += (map[i] / m);
        if (cnt >= n) l = m + 1;
        else r = m - 1;
    }

    printf("%ld", r);

}
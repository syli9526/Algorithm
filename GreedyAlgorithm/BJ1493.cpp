#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {


    int len, wid, hei, n;
    int cube[20] = {0,};
    ll temp = 0, cnt = 0, result = 0;

    scanf("%d %d %d %d", &len, &wid, &hei, &n);

    for (int i = 0, a, b; i < n; ++i) scanf("%d %d", &a, &b), cube[a] = b;

    for (int i = 19; i >= 0; i--) {

        cnt <<= 3;
        temp = min((ll)cube[i], (ll)(len >> i) * (wid >> i) * (hei >> i) - cnt);
        cnt += temp, result += temp;

    }

    printf("%lld",cnt == (ll)len * wid *hei ? result : -1);



}
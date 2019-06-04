#include <iostream>
using namespace std;
int n, h, map[500002], m = 1e9, now, cnt;
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> n >> h;
    for (int x; n--;) {
        cin >> x;
        if (n % 2 == 0) map[h - x + 1]++, map[h + 1]--;
        else map[1]++, map[x + 1]--;

    }
    for (int i = 1; i <= h; i++) {
        now += map[i];
        if (now < m) m = now, cnt = 1;
        else if (now == m) cnt++;
    }
    cout << m << ' ' << cnt;
}
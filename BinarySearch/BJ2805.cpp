/*
// 나무자르기 ver 1.
 
#include <cstdio>
#include <algorithm>

typedef long long ll;
using namespace std;
const int MAX = 1000000;
int n, m;
ll map[MAX], bottom = 0, top = 0, ans;


int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i)scanf("%lld", &map[i]), top = max(top, map[i]);


    while (bottom <= top) {

        ll mid = (bottom + top) / 2;
        ll temp = 0;

        for (int i = 0; i < n; ++i) map[i] - mid > 0 ? temp += (map[i] - mid) : temp;

        if (temp == m) {
            ans = mid;
            break;

        } else if (m < temp) bottom = mid + 1;
        else top = mid - 1;

    }

    if (bottom > top) printf("%lld", top);
    else printf("%lld", ans);


}

 */

//나무 자르기 ver 2.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n = 0, m = 0;
    int max_val = 0;
    int ans = 0;
    //scanf("%d %d",&n, &m);
    cin >> n >> m;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        //scanf("%d", &h[i]);
        cin >> h[i];

        if (h[i] > max_val)
        {
            max_val = h[i];
        }//max_val = max(max_val, h[i]);과 속도 동일!
    }

    long long left = 0;
    long long right = max_val-1;
    long long mid;
    while (left <= right)
    {
        mid = (left + right) >> 1;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (h[i] > mid)
            {
                sum += h[i] - mid;
                if (sum > m)
                {
                    break;
                }//시간 : 236ms -> 208ms
            }
        }

        if (sum < m)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
            ans = mid;
        }
    }

    //printf("%d", ans);
    cout << ans;
    return 0;
}

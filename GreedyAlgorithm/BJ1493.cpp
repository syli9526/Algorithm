// BJ1493 박스채우기
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {


    int len, wid, hei, n;
    int cube[20] = {0,};
    ll temp = 0, cnt = 0, ans = 0;

    scanf("%d %d %d %d", &len, &wid, &hei, &n);

    for (int i = 0, a, b; i < n; ++i) scanf("%d %d", &a, &b), cube[a] = b;

    for (int i = 19; i >= 0; i--) { //제일 큰 큐브의 길이 2^19 부터 시

        cnt <<= 3; // cnt * 8 의 shift 연산, 이미 넣었던 큐브들을 해당 순서의 큐브로 자르는 과정 (4*4*4)는 (2*2*2)가 8개 있는 것과 같음
        //크기에 해당하는 큐브의 개수와 , (해당 크기로 들어갈 수 있는 최대 개수 - 이전에 넣었던 큐브 개수)중 작은 값을 선택해 넣어줌
        temp = min((ll) cube[i], (ll) (len >> i) * (wid >> i) * (hei >> i) - cnt);
        cnt += temp, ans += temp; // 개수에 추가함

    }

    printf("%lld", cnt == (ll) len * wid * hei ? ans : -1);


}
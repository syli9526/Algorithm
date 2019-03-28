#include <cstdio>
// BJ1700 멀티탭 스케줄링 : 플러그를 빼는 최소 횟수를 구하라
using namespace std;
int N, K;
int tap[101],plug[101];
int pos = 0, ans = 0; // pos : 플러그가 꽂힌 멀티탭 구의 최대 위치

int main() {

    scanf("%d %d", &N, &K);
    for (int i = 0; i < K; ++i) scanf("%d", &plug[i]);

    for (int i = 0; i < K; ++i) { // 주어진 전기 용품 순서대로 탐색
        int j;

        // plug가 tap에 꽂혀있지 않다면, 플러그가 꽂힌 멀티탭 구의 최대 위치까지 탐색
        for (j = 0; j < pos && tap[j] != plug[i]; ++j);

        if (j == N) { // 멀티탭 구에가 꽉 차있는경우
            int mxi = 0, temp;
            int t;
            for (j = 0; j < pos; ++j) { // 멀티탭에 꽂혀있는 플러그 종류들을 탐색

                // 탭에 꽂인 플러그종류가 앞으로 나올 플러그 종류와 같을 때가지 검사 , 만약 없다면 끝까지 탐색
                for (t = i + 1; t < K && plug[t] != tap[j]; ++t);

                // 만약 탐색한거리가 이전에 탐색한 거리보다 길다면 멀티탭 종류를 저장해둠
                if (t > mxi) mxi = t, temp = j;
            }

            // 멀티탭에 꽂힌 플러그 종류를 교체
            tap[temp] = plug[i];
            // 교체회수 추가
            ans++;
        } else if (j == pos) tap[pos++] = plug[i]; // 멀티탭에 플러그를 꽂아줌
    }
    printf("%d", ans);
}

/*
const int MAX = 101;
int N, K, ans;
int schedule[MAX], plug[MAX];

int main() {

    scanf("%d %d", &N, &K);

    for (int i = 0; i < K; i++) scanf("%d", &schedule[i]);

    for (int i = 0; i < K; i++) {
        bool pluggedIn = false;

        for (int j = 0; j < N; j++)

            if (plug[j] == schedule[i]) {
                pluggedIn = true;
                break;
            }

        if (pluggedIn) continue;

        for (int j = 0; j < N; j++)

            if (plug[j] == 0) {
                plug[j] = schedule[i];
                pluggedIn = true;
                break;
            }
        if (pluggedIn) continue;
        int idx, deviceIdx = -1;

        for (int j = 0; j < N; j++) {

            int lastIdx = 0;

            for (int k = i + 1; k < K; k++) {
                if (plug[j] == schedule[k]) break;
                lastIdx++;
            }
            if (lastIdx > deviceIdx) idx = j, deviceIdx = lastIdx;
    }

    ans++;
    plug[idx] = schedule[i];

}

printf("%d",ans);
return 0;

}
 */


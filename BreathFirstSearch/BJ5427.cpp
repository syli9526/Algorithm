#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int h, w;
char map[1001][1001];

const int dh[] = {-1, 1, 0, 0};
const int dw[] = {0, 0, 1, -1};

queue<pair<int, int>> fire; // 불위치 저장
pair<int, int> start; // 시작 좌표저장


int bfs(pair<int, int> a) {

    queue<pair<pair<int, int>, int>> q;

    q.push({a, 0});

    while (!q.empty()) {

        int ch, cw, cnt;
        int size;

        size = fire.size();

        // 불 상하좌우를 불로 바꿈
        while (size--) {

            ch = fire.front().first;
            cw = fire.front().second;

            fire.pop();

            for (int i = 0; i < 4; ++i) {
                if (ch + dh[i] < 0 || ch + dh[i] >= h || cw + dw[i] < 0 || cw + dw[i] >= w) continue;
                if (map[ch + dh[i]][cw + dw[i]] == '.' || map[ch + dh[i]][cw + dw[i]] == '@') {
                    map[ch + dh[i]][cw + dw[i]] = '*';
                    fire.push({ch + dh[i], cw + dw[i]});
                }

            }
        }

        size = q.size();

        // 이동 할수있는 곳 이동 후 저장
        while (size--) {

            ch = q.front().first.first;
            cw = q.front().first.second;
            cnt = q.front().second;

            q.pop();

            for (int i = 0; i < 4; ++i) {

                if (ch + dh[i] < 0 || ch + dh[i] >= h || cw + dw[i] < 0 || cw + dw[i] >= w) {
                    return cnt;
                }
                if (map[ch + dh[i]][cw + dw[i]] == '.') {
                    map[ch + dh[i]][cw + dw[i]] = '@';
                    q.push({{ch + dh[i], cw + dw[i]}, cnt+1});
                }
            }

        }

    }

    return -1;

}

int main() {

    int T;

    scanf("%d", &T);

    while (T--) {

        // 불 저장 값 초기화
        while (!fire.empty()) fire.pop();

        scanf("%d %d", &w, &h);

        for (int i = 0; i < h; ++i) {
            scanf("%s", map[i]);

            for (int j = 0; j < w; ++j) {
                if (map[i][j] == '*') fire.push({i, j});
                else if (map[i][j] == '@') start.first = i, start.second = j;
            }
        }

        int ans = bfs(start);

        if (ans == -1) printf("IMPOSSIBLE\n");
        else printf("%d\n", ans+1);


    }


}
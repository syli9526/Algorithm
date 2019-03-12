#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int T, M, N, K;
int ans;
vector<vector<int>> v;

void dfs(int x, int y) {

    v[x][y] = 2;
    int px, py, qx, qy;
    px = x + 1 < N ? x + 1 : x;
    py = y + 1 < M ? y + 1 : y;
    qx = x - 1 >= 0 ? x - 1 : x;
    qy = y - 1 >= 0 ? y - 1 : y;
    if (v[px][y] != 1 && v[x][py] != 1 && v[qx][y] != 1 && v[x][qy] != 1)
        return;

    if (v[px][y] == 1)
        dfs(px, y);
    if (v[x][py] == 1)
        dfs(x, py);
    if (v[qx][y] == 1)
        dfs(qx, y);
    if (v[x][qy] == 1)
        dfs(x, qy);


}

int main() {

    scanf("%d", &T);

    for (int i = 0; i < T; ++i) {
        ans = 0;
        scanf("%d %d %d", &M, &N, &K);
        v.resize(N);
        for (int j = 0; j < N; ++j) v[j].resize(M, 0);
        for (int j = 0, x, y; j < K; ++j) scanf("%d %d", &y, &x), v[x][y] = 1;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {

                if (v[i][j] == 1) {
                    dfs(i, j);
                    ans++;
                }
            }
        }

        printf("%d\n", ans);

    }


}
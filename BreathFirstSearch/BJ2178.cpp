#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 101;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int N, M, nx, ny;

int matrix[MAX][MAX];

void bfs(int x, int y) {

    queue<pair<int, int>> q;
    q.push(make_pair(x, y));

    while (!q.empty()) {

        x = q.front().first;
        y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; ++i) {

            nx = x + dx[i];
            ny = y + dy[i];
            if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if (matrix[nx][ny] == 1) {
                q.push(make_pair(nx, ny));
                matrix[nx][ny] = matrix[x][y] + 1;
            }
        }
    }
}

int main() {

    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            scanf("%1d", &matrix[i][j]);

    bfs(1, 1);
    printf("%d\n", matrix[N][M]);


}
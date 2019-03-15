#include <iostream>

#include <string>

#include <queue>

#include <cstring> //memset

using namespace std;
const int MAX = 30;
typedef struct {

    int z, y, x;

} Dir;

Dir dp[6] = {{1,  0,  0}, // 위
             {-1, 0,  0}, //아래
             {0,  1,  0}, // 남
             {0,  -1, 0}, // 북
             {0,  0,  1}, // 동
             {0,  0,  -1}}; //서

int L, R, C;

pair<pair<int, int>, int> start, finish;

int map[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];

int BFS(pair<pair<int, int>, int> start) {

    queue<pair<pair<int, int>, pair<int, int>>> q; //z, y, x, cnt

    q.push({{start.first.first, start.first.second},
            {start.second,      0}});

    memset(visited, false, sizeof(visited));

    visited[start.first.first][start.first.second][start.second] = true;


    while (!q.empty()) {

        int z = q.front().first.first;
        int y = q.front().first.second;
        int x = q.front().second.first;
        int cnt = q.front().second.second;

        q.pop();

        //도착했을 경우
        if (z == finish.first.first && y == finish.first.second && x == finish.second)
            return cnt;


        for (int i = 0; i < 6; i++) {

            int nz = z + dp[i].z;
            int ny = y + dp[i].y;
            int nx = x + dp[i].x;



            //범위 내에 있고 방문하지 않았으며 벽이 아닌 공간일 떄만 큐에 넣는다
            if (0 <= nz && nz < L && 0 <= ny && ny < R && 0 <= nx && nx < C)
                if (!visited[nz][ny][nx] && map[nz][ny][nx] == 0) {
                    visited[nz][ny][nx] = true;
                    q.push({{nz, ny},
                            {nx, cnt + 1}});
                }
        }
    }

    return -1; //도착하지 못할 경우

}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0); //cin 속도 향상



    while (1) {

        memset(map, 0, sizeof(map));

        cin >> L >> R >> C;

        if (!L && !R && !C)

            break;



        //맵 정보 입력
        for (int z = 0; z < L; z++)
            for (int y = 0; y < R; y++) {
                string temp;
                cin >> temp;

                for (int x = 0; x < temp.length(); x++)
                    if (temp[x] == 'S') {
                        start.first.first = z;
                        start.first.second = y;
                        start.second = x;
                    } else if (temp[x] == '#') //벽
                        map[z][y][x] = 1;
                    else if (temp[x] == 'E') //도착점
                    {
                        finish.first.first = z;
                        finish.first.second = y;
                        finish.second = x;
                    }
            }


        int result = BFS(start);

        if (result == -1) cout << "Trapped!" << "\n";
        else cout << "Escaped in " << result << " minute(s).\n";

    }

    return 0;

}

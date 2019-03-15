#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1000001;

int N, K; // 처음위치, 나중위치
bool visited[MAX] = {false,}; // 방문 했는지 안했는지 체크

queue<pair<int, int>> q; // {위치,시간}

int main() {

    cin >> N >> K;

    q.push(make_pair(N, 0));

    // bfs 시작
    while (!q.empty()) {

        int pos = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (pos < 0 || pos > MAX) continue; // 범위를 벗어난경우

        if (visited[pos]) continue; // 방문을 했던 경우

        visited[pos] = true; // 방문 체크


        if (pos == K) { // 원하는 위치에 도착하면 출력후 종료
            cout << cnt;
            return 0;

        }

        q.push(make_pair(pos * 2, cnt + 1));
        q.push(make_pair(pos + 1, cnt + 1));
        q.push(make_pair(pos - 1, cnt + 1));
    }

    return 0;

}




# BFS(Breadth_First Search넓이우선탐색)

너비 우선 탐색은 그래프의 모든 정점들을 특정한 순서에 따라 방문하는 알고리즘 중 하나이다. 현재 정점과 인접한 간선들을 검사하다가 방문하지 않은 정점들을 발견하면 그 간선을 통해 방문하지 않은 정점들을 자료구조 큐에 넣는다. 그리고 큐의 front 정점을 방문하고 pop한다.
또 해당 정점에서 인접한 간선을 검사해 방문하지 않은 정점들을 큐에 넣고 방문하기는 과정을 반복하다가 더 이상 방문할 수 있는 정점이 없으면종료한다. 이러한 과정을 반복하여 큐에 더 이상 정점이 존재하지 않을 때까지 실행하여 그래프의 모든 정점을 방문하는 알고리즘이 BFS 알고리즘이다.



###### 1. BFS개념도

![99F3173359CD120E2D](https://user-images.githubusercontent.com/48287388/54264417-6efdc500-45b6-11e9-8d38-c9148b0aacbc.gif)

![algorithm_7-2](https://user-images.githubusercontent.com/48287388/54264473-8a68d000-45b6-11e9-85a8-7e9f70b4f811.jpg)

###### BFS 기본코드

~~~c++
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > edge;
vector<bool> visited;
int N, M;
int u, v;

void bfs(int cur) {
    queue<int> q;
    visited[cur] = true;
    q.push(cur);
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        cout << here << ' ';
        for (int i = 0; i < edge[here].size(); i++) {
            int there = edge[here][i];
            if (visited[there]) continue;
            visited[there] = true;
            q.push(there);
        }
    }
}

int main() {
    cin >> N >> M;
    edge.resize(N + 1);
    visited.resize(N + 1);
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        edge[u].push_back(v);
    }
    bfs(1);
}
~~~

---



* BFS문제

  1. 2178 미로탐색 <https://www.acmicpc.net/problem/2178>

  2. 1697 숨바꼭질 <https://www.acmicpc.net/problem/1697>

  3. 6593 상범빌딩 <https://www.acmicpc.net/problem/6593>

  4. 5427 불 <https://www.acmicpc.net/problem/5427>

     

  >백준 알고리즘
# DFS(Depth-First Search, 깊이 우선 탐색)

* 깊이 우선 탐색은 그래프의 모든 정점들을 특정한 순서에 따라 방문하는 알고리즘 중 하나이다. 
* 현재 정점과 인접한 간선들을 검사하다가 방문하지 않은 정점을 발견하면 그 간선을 통해 방문하지 은 정점으로 이동한다.
  이 과정을 반복하다가 더 이상 방문할 수 있는 정점이 없으면 마지막으로 통과한 간선을 통해 뒤로 돌아가서 해당 정점에서 방문할 수 있는 정점을 탐색한다. 이러한 과정을 반복하여 그래프의 모든 정점을 방문하는 알고리즘이 DFS 알고리즘이다.



###### 1. DFS 개념도

<center><img width="431" alt="DFS" src="https://user-images.githubusercontent.com/48287388/54182594-4954bb00-44e5-11e9-88db-99320885018b.png"></center>



###### 2. DFS 기본코드

~~~c++
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> edge;
vector<bool> visited;
int N, M;
int u, v;

void dfs(int cur) {
    visited[cur] = true;
    cout << cur << ' ';
    for (int i = 0; i < edge[cur].size(); i++) {
        int there = edge[cur][i];
        if (visited[there]) continue;
        dfs(there);
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
    dfs(1);
}
~~~



----

* DFS 문제

  1. 1012 유기농 배추 <https://www.acmicpc.net/problem/1012>

  

  > 출처 백준 알고리즘








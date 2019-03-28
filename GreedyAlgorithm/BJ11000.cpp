#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>

//BJ11000 강의실 배정 : 모든 강의를 배정할때 필요한 강의실 수를 출력하라
using namespace std;

int N;
vector<pair<int, int>> v; // {시작시간,종료시간}
int main() {

    priority_queue<int, vector<int>, greater<int>> q; // 우선순위 큐 -> 오름차순정렬이용

    scanf("%d", &N);

    for (int i = 0, a, b; i < N; ++i) scanf("%d %d", &a, &b), v.push_back({a, b});

    sort(v.begin(), v.end()); // 강의 시작 시간 기준으로 오름차순 정렬

    q.push(v[0].second); // 첫 강의의 종료시간을 큐에 넣음

    // 큐에 종료시간을 넣어주고, 배정된 강의의 종료시간보다 시작시간이 크면 큐에있는 종료시간을 뺌.
    // 이과정을 반복하면 큐에 남아있는 개수가 필요한 강의의 최대 개수가 됨
    for (int i = 1; i < N; ++i) if (q.top() <= v[i].first)q.pop(), q.push(v[i].second);

    printf("%ld", q.size());
}


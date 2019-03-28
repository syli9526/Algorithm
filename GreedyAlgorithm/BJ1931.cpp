#include <cstdio>
#include <algorithm>
#include <vector>
// BJ1931 회의실 배정 : 최대로 넣을수 있는 회의 수를 출력하라
using namespace std;

int N, start = 0, ans = 0;
vector<pair<int, int>> v; // {회의종료,회의시작}

int main() {

    scanf("%d", &N);

    for (int i = 0, a, b; i < N; ++i) scanf("%d %d", &a, &b), v.push_back({b, a});

    sort(v.begin(), v.end()); // 회의 종료시간을 기준으로 오름차순 정렬

    // 전에 넣은 회의 종료시간<= 다음 회의 시작시간이면 회의를 넣고 전에 넣은 종료시간(start) 갱신
    // 종료시간이 빠른것일수록 앞으로 넣을 수 있는 시간이 많으므로 종료시간이 빠른것부터 순차적으로 탐색함
    for (int i = 0; i < v.size(); ++i) if (start <= v[i].second) start = v[i].first, ans++;

    printf("%d\n", ans);

}
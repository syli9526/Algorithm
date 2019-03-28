#include <algorithm>
#include <stdio.h>
#include <vector>

// BJ13094 과제
//과제를 해서 얻을 수 있는 최대 점수를 구하라

using namespace std;
int N, ans = 0;
int d[1000] = {0,}; // 과제를 할 날을 배정
vector <pair<int, int>> v; //{마감일까지 남은 일수, 과제 점수}

// 두번째 원소 기준으로 내림차순 정렬
bool compare(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }

int main() {


    scanf("%d", &N);

    for (int i = 0, a, b; i < N; ++i) scanf("%d %d", &a, &b), v.push_back(pair<int, int>(a, b));

    sort(v.begin(), v.end(), compare);


    for (int i = 0; i < N; ++i) { // 과제 점수가 큰것부터 탐색
        for (int j = v[i].first; j > 0; j--) { // 마감일부터 현재까지의 날짜를 검색함
            if (d[j] == 0) {  //해당 날짜에 해야할 과제가 없다면
                d[j] = v[i].second, ans += v[i].second; // 과제를 배당하고 , 점수에 추가시킴
                break;
            }
        }
    }

    printf("%d", ans);

}
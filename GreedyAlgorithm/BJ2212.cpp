#include <cstdio>
#include <queue>
#include <algorithm>
// BJ2212 센서
//집중국의 수신 가능 영역의 길이의 합의 최솟값을 출력하라
using namespace std;

const int MAX = 10000;

int N,K, ans =0, sensor[MAX];

int main() {

    priority_queue<int> q;

    scanf("%d %d",&N,&K);

    for (int i = 0; i < N; ++i) scanf("%d",&sensor[i]); // 센서의 위치를 입력받음

    sort(sensor,sensor+N); // 센서의 위치를 오름차순 정렬

    for (int i = 1; i < N; ++i) { // 위치 차이를 큐에 저장
        if(sensor[i]- sensor[i-1])
            q.push(sensor[i]- sensor[i-1]);
    }
    K--;
    // 위치 차이가 큰것들부터 빼주면 위치가 분할이 됨 (1개빼면 2개로 분할 2개뺴면 3개로 분할)
    while(K-- && !q.empty()) q.pop();
    // 큰것들을 집중국 개수 -1 까지 뺴주고 나머지를 다 더해줌
    while(!q.empty()) ans += q.top(), q.pop();

    printf("%d",ans);

}
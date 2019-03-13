// 위상정렬 활용해 사이클을 체크함

#include <iostream>
#include <stdio.h>

using namespace std;

const int MAX = 100001;

int stu[MAX], inEg[MAX]; // inEg = 들어오는 간선의 개수를 담는 배열
bool visited[MAX];


int main() {


    int T;
    scanf("%d", &T); // 케이스 개수

    while (T--) {

        int n = 0, temp = 0, ans = 0;
        scanf("%d", &n);

        // 정보 초기화
        for (int i = 1; i <= n; ++i) visited[i] = false, inEg[i] = 0, scanf("%d", &stu[i]);
        for (int i = 1; i <= n; ++i) inEg[stu[i]]++;

        for (int i = 1; i <= n; ++i) {
            temp = i;

            //
            while (!inEg[temp] && !visited[temp]) { // 들어오는 간선이 없고 , 방문도 한적이 없다면 사이클에 포함된 노드가 아니다!
                ans++;
                inEg[stu[temp]]--; // temp 노드에서 뻣어나가는 간선을 삭제함
                visited[temp] = true; // 방문 기록 남김
                temp = stu[temp]; // temp가 가르켰던 노드를 temp로 바꿔줌
            }
        }

        printf("%d\n", ans);
    }
}
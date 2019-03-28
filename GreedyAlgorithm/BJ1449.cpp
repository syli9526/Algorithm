#include <cstdio>
#include <algorithm>
/*
 * BJ1449 수리공 항승
파이프에서 물이 새는 곳은 신기하게도 가장 왼쪽에서 정수만큼 떨어진 거리만 물이 샌다.
항승이는 길이가 L인 테이프를 무한개 가지고 있다.
항승이는 테이프를 이용해서 물을 막으려고 한다. 항승이는 항상 물을 막을 때,
적어도 그 위치의 좌우 0.5만큼 간격을 줘야 물이 다시는 안 샌다고 생각한다.
물이 새는 곳의 위치와, 항승이가 가지고 있는 테이프의 길이 L이 주어졌을 때,
항승이가 필요한 테이프의 최소 개수를 구하는 프로그램을 작성하시오.
 * */

using namespace std;

const int MAX = 1001;

int N, L; // 물이 새는곳 개수, 테이프 길이

int pos[MAX], fin = 0, ans = 0;

int main() {

    scanf("%d %d", &N, &L);

    for (int i = 0; i < N; ++i) scanf("%d", &pos[i]);

    sort(pos, pos + N); //위치를 오름차순 정렬
    fin = pos[0]; // 처음 물이 새는 위치
    ans++;

    for (int i = 1; i < N; ++i) {

        if (fin + L - 1 < pos[i]) { // 전에 붙인 테이프로 수리를 할 수 없는경우
            ans++; // 테이프 개수+1
            fin = pos[i]; // 테이프를 붙일 시작 위치
        }
    }

    printf("%d", ans);


}
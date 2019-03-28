#include <cstdio>
#include <algorithm>

// BJ2217 로프 : 로프들을 이용해 버틸 수 있는 최대 중량을 구해라
// 해결법 : 가장 많이 들 수 있는 로프부터 검사하며
// (이전로프 + 현재로프)/개수 = 현재 로프까지 들 수 있는 최대 중량이 되고, 이전의 최대중량과 비교해 큰값을 저장하면 됨
using namespace std;
int N, w = 0, rp[10001] = {0}; // rp의 인덱스 : 중량 ,rp의 값 : 개수

int main() {

    scanf("%d", &N);
    for (int i = 0, a; i < N; ++i)scanf("%d", &a), rp[a]++;

    for (int i = 10000; i >= 0; i--) {
        rp[i] += rp[i + 1];
        if (rp[i] != rp[i + 1]) w = w < rp[i] * i ? rp[i] * i : w;
    }
    printf("%d", w);

}
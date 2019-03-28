#include <cstdio>
//BJ11047 동전 0 : 필요 동전의 최소 개수 출력하라

int N, K, coin[10], ans;

int main() {

    scanf("%d %d", &N, &K); // 동전 종류, 만들어야할

    for (int i = 0; i < N; i++)scanf("%d", coin + i);

    for (int i = N - 1; i >= 0; i--) {  //들어갈 수 있는 동전의 최대치를 넣고 K에서 빼줌
        ans += K / coin[i];
        K %= coin[i];
    }

    printf("%d", ans);
}
#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 50;
int N, M, ans = 100000;
int bw = 0, wb = 0;
char map[MAX][MAX];


int main() {

    scanf("%d %d", &N, &M);//행,렬 개수 입력 받음

    for (int i = 0; i < N; ++i) scanf("%s", map[i]);


    for (int i = 0; i <= N - 8; ++i) {
        for (int j = 0; j <= M - 8; ++j) {
            bw = 0, wb = 0;
            for (int k = i; k < i + 8; ++k) {
                for (int l = j; l < j + 8; ++l) {
                    if ((k + l) % 2 == 0) map[k][l] == 'B' ? bw++ : wb++;
                    else if ((k + l) % 2 == 1)map[k][l] == 'B' ? wb++ : bw++;
                }
            }
            ans = min(ans, min(bw, wb));
        }
    }

    printf("%d",ans);

}
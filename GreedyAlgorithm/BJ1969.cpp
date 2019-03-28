#include <string.h>
#include <cstdio>
//BJ1969 DNA
//첫째 줄에 Hamming Distance의 합이 가장 작은 DNA 를 출력하고, 둘째 줄에는 그 Hamming Distance의 합을 출력하시오
using namespace std;

char a[] = {'A', 'C', 'G', 'T'};
int cnt[4][50] = {0,};
char str[51];

int n, m, ans = 0;

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; ++i) {

        scanf("%s", str);

        for (int j = 0; j < strlen(str); ++j) { // 각 위치에서 문자의 종류에따라 개수를 추가해줌
            if (str[j] == 'A') cnt[0][j]++;
            else if (str[j] == 'C')cnt[1][j]++;
            else if (str[j] == 'G')cnt[2][j]++;
            else cnt[3][j]++;
        }
    }


    for (int i = 0; i < m; ++i) {
        int temp = 0;
        int mx = 0;
        for (int j = 0; j < 4; ++j) {
            mx = cnt[mx][i] >= cnt[j][i] ? mx : j; // 각 위치에서 최대 개수인 문자를 찾음
        }
        ans += n - cnt[mx][i];
        printf("%c", a[mx]);

    }

    printf("\n%d\n", ans);
}
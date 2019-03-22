#include <iostream>
#include <cstdio>

using namespace std;

int T, n;
bool ans;

int main() {

    scanf("%d", &T);

    while (T--) {

        scanf("%d", &n); // 입력숫자가 최대 1000이므로 45까지만 확인하면 됨
        ans = false;
        for (int i = 1; i <= 45; ++i) {
            for (int j = i; j <= 45; ++j) {
                for (int k = i; k <= 45; ++k) {
                    int temp = (i * (i + 1) + j * (j + 1) + k * (k + 1)) / 2; //삼각수계산
                    if (temp == n) ans = true; // 입력갑이랑 일치할떄
                    if(ans) break;
                }
                if(ans) break;
            }
            if(ans) break;
        }

        printf("%d\n", ans);

    }

}
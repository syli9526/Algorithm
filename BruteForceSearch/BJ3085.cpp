#include <cstdio>
#include <algorithm>

using namespace std;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int n, ans = 0;
char arr[50][50];

int check(int cx, int cy, int nx, int ny) {
    if (!arr[cy][cx]) return 0; // 배열의 범위를 넘어가면 0 리턴
    if (arr[cy][cx] == arr[cy + ny][cx + nx]) return 1 + check(cx + nx, cy + ny, nx, ny); //현재값이랑 옆 값이랑 같으면 +1;
    else return 1;// 현재 값이랑 옆 값이랑 다르면 1 리턴
}

int main() {
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) scanf("%s", arr[i]);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                swap(arr[i][j], arr[i + dy[k]][j + dx[k]]); // 사탕 위치 교환
                ans = max(ans, check(j, i, -1, 0) + check(j, i, 1, 0) - 1); // 교환 후 최대 길이 체크
                ans = max(ans, check(j, i, 0, -1) + check(j, i, 0, 1) - 1); // 교환 후 최대 길이 체크
                swap(arr[i][j], arr[i + dy[k]][j + dx[k]]); // 사탕 위치 원위치
            }
        }
    }
    printf("%d", ans);
    return 0;
}
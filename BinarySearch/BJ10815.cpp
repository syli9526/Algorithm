#include <cstdio>
#include <algorithm>

using namespace std;
const int MAX = 500000;
int n, A[MAX], m,a;

int main() {

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &A[i]);
    sort(A, A + n);
    scanf("%d", &m);
    while (m--) {
        scanf("%d", &a);
        if (binary_search(A,A+n,a)) printf("1 ");
        else printf("0 ");
    }

}
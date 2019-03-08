#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int N, S;
int ans = 0;
vector<int> v;

void search(int idx, int sum) {

    sum += v[idx];

    if (idx >= N) return;
    if (sum == S) ans++;

    search(idx + 1, sum - v[idx]);
    search(idx + 1, sum);

}

int main() {

    scanf("%d %d", &N, &S);

    for (int i = 0, a; i < N; ++i) scanf("%d", &a), v.push_back(a);

    search(0, 0);

    printf("%d", ans);


}
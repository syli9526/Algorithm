#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {

    return a.second > b.second;

}

int main() {


    int N, ans = 0;
    int d[1000] = {0,};
    vector<pair<int, int>> v;


    scanf("%d", &N);

    for (int i = 0, a, b; i < N; ++i) scanf("%d %d", &a, &b), v.push_back(pair<int, int>(a, b));

    sort(v.begin(), v.end(), compare);


    for (int i = 0; i < N; ++i) {

        for (int j = v[i].first; j > 0; j--) {
            if (d[j] == 0) {
                d[j] = v[i].second, ans += v[i].second;
                break;
            }
        }
    }

    printf("%d", ans);

}
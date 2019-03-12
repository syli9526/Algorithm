#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;
const int MAX = 50000;

int N, mx, v, b[MAX], h[MAX], w[MAX], d[MAX];
int overflow;

int main() {

    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        scanf("%d %d %d %d", b + i, h + i, w + i, d + i);
        mx = max(mx, b[i] + h[i]);
        overflow += h[i] * w[i] * d[i];
    }

    scanf("%d", &v);

    if (overflow < v) {
        printf("OVERFLOW\n");
        return 0;
    }

    double L = 0, R = mx;

    while (R - L > 0.001) {

        double M = (R + L) / 2, sum = 0;

        for (int i = 0; i < N; ++i) {

            double temp = min(M - (double) b[i], (double) h[i]);
            if (temp > 0) sum += temp * w[i] * d[i];

        }

        (sum >= v ? R : L) = M;
    }

    printf("%.2lf", R);

}
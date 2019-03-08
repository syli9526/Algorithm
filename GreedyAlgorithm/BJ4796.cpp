#include <iostream>
#include <stdio.h>

using namespace std;

int main() {

    int P, L, V;
    int Q, R;
    int count = 0, result;


    while (1) {


        scanf("%d %d %d",&L,&P,&V);
        count++;

        if (L == 0 && P == 0 && V == 0) break;

        Q = V / P;
        R = V % P;

        if (R > L) result = Q * L + L;
        else result = Q * L + R;

        cout << "Case " << count << ": " << result << endl;

    }

}
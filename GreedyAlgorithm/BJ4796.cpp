#include <iostream>
#include <cstdio>

/*
 BJ4796 캠핑
 캠핑장을 연속하는 P일 중, L일동안만 사용할 수 있다.
 강산이는 이제 막 V일짜리 휴가를 시작했다. 강산이가 캠핑장을 최대 며칠동안 사용할 수 있을까? (1 < L < P < V)

 * */

using namespace std;

int P, L, V;
int Q, R;
int count = 0, result;

int main() {

    while (1) {

        scanf("%d %d %d",&L,&P,&V);
        count++; // case 숫자
        if (L == 0 && P == 0 && V == 0) break;
        Q = V / P;
        R = V % P;
        // 휴가 첫날부터 캠핑장을 사용하면 된다. (P일의 횟수*L일) 과 나머지 일수를 더해주면 됨
        result = R > L ? Q * L + L :  Q * L + R;
        cout << "Case " << count << ": " << result << "\n";

    }

}
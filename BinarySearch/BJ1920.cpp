#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, temp;

int main() {

    scanf("%d", &n);
    vector<int> arr(n);

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    scanf("%d", &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (binary_search(arr.begin(), arr.end(), temp)) printf("1\n");
        else printf("0\n");
    }

}
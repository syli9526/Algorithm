#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> height(9, 0);
    int sum = 0, temp = 0;


    for (int i = 0; i < 9; ++i) {
        cin >> height[i];
        sum += height[i];
    }

    sort(height.begin(), height.end());

    for (int j = 0; j < 9; ++j) {
        for (int i = j + 1; i < 9; ++i) {
            temp = sum - height[j] - height[i];


            if (temp == 100) {

                for (int k = 0; k < 9; ++k) {
                    if (k != i && k != j) {
                        cout << height[k] << endl;
                    }
                }
                break;

            }
        }
    }

}
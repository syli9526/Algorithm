//
//  main.cpp
//  BJ1725
//
//  Created by 소율 on 03/09/2019.
//  Copyright © 2019 소율. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX 100000

using namespace std;
int N, histogram[MAX];

int f(int start, int end){
    
    if (start == end) return 0;
    if (start +1 == end) return histogram[start];
    
    int mid = (start + end) >> 1;
    
    int result = max(f(start,mid), f(mid,end));
    int width = 1, height = histogram[mid], left = mid, right = mid;
    
    while(right - left + 1 < end - start){
        
        int a = left > start ? min(height, histogram[left-1]) : 0;
        int b = right < end ? min(height, histogram[right+1]) : 0;
        
        if(a > b) height = a, left--;
        else height = b, right++;
        
        result = max(result, (++width)*height);
    }
    
    return result;
}

int main(int argc, const char * argv[]) {

    scanf("%d",&N);
    
    for (int i = 0; i < N; i++ ) {
        scanf("%d", &histogram[i]);
    }
    printf("%d",f(0,N));
}

//
//  main.cpp
//  BJ6236
//
//  Created by 소율 on 03/09/2019.
//  Copyright © 2019 소율. All rights reserved.
//

#include <iostream>
#define MAX 100000
using namespace std;

int N,M,map[MAX], l = 0, r = 0, ans;


int main(int argc, const char * argv[]) {
    
    scanf("%d %d",&N,&M);
    
    for (int i =0 ; i<N; i++) {
        scanf("%d",&map[i]);
        r += map[i];
    }
    
    while(l <= r){
        
        int mid = (l + r) >> 1;
        int count = 1, temp = mid;
        bool flag = true;
        
        
        for(int i = 0; i < N; i++){
            
            if(map[i]>mid) {
                flag = false;
                break;
            }
            
            if(temp - map[i] < 0) temp = mid, count++;
            
            temp -= map[i];
            
        }
        if(flag) flag = count <= M ? true: false;
        
        if(flag) ans = mid, r = mid -1;
        else l = mid +1;
        
    }
    
    printf("%d",ans);
    
}

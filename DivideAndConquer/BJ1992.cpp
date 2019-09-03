//
//  main.cpp
//  BJ1992
//
//  Created by 소율 on 03/09/2019.
//  Copyright © 2019 소율. All rights reserved.
//

#include <iostream>
#include <string>
#define MAX 64

using namespace std;

int map[MAX][MAX],N;

string f (int y, int x, int size){
    
    
    if (size == 1) {
 
        return to_string(map[y][x]);
    }
    
    
    string a = f(y, x, size >> 1);
    string b = f(y, x + (size >> 1), size >> 1);
    string c = f(y + (size >> 1), x, size >> 1);
    string d = f(y + (size >> 1), x + (size >> 1), size >> 1);
    
    if(a.compare(b) == 0  && a.compare(c) == 0 && a.compare(d) == 0 && a.size() == 1) {
        return a;
    }else {
        return "("+a+b+c+d+")";
    }
}

int main() {
    
    scanf("%d",&N);
    
    for (int i = 0; i< N; i++) {
        for (int j = 0 ; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    
    string result = f(0,0,N);
    
    cout << result <<"\n";
    
    
}

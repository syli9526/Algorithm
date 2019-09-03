//
//  main.cpp
//  BJ14503
//
//  Created by 소율 on 02/09/2019.
//  Copyright © 2019 소율. All rights reserved.
//

#include <iostream>

using namespace std;

#define MAX 51

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int back_dx[4] = {1,0,-1,0};
int back_dy[4] = {0,-1,0,1};

int ans;
int map[MAX][MAX];
int n, m, r, c, d;


void f(int x, int y, int direction)
{
 
    if (map[x][y] == 1) return;
    

    if (map[x][y] == 0)
    {
        map[x][y] = 2;
        ans++;
    }
    
    // 네 방향 검사
    for (int k = 0; k < 4; k++)
    {
        int next_direction = direction - 1 < 0 ? 3 : direction-1;
        int next_x = x + dx[next_direction], next_y = y + dy[next_direction];
 
        if (map[next_x][next_y] == 0){
            f(next_x, next_y, next_direction);
         
            return;
        }
        else
        {
            direction = next_direction;
        }
    }

    int next_x = x + back_dx[direction], next_y = y + back_dy[direction];
    
    f(next_x, next_y, direction);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    cin >> r >> c >> d;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    
    f(r, c, d);
    
    cout << ans << "\n";
    
    return 0;
}

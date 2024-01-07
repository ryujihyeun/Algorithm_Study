#include <bits/stdc++.h>
using namespace std;
const int n = 3;
int a[n][n], visited[n][n];

const int dy[] = {0,0,1,-1};
const int dx[] = {1,-1,0,0};

void go(int y, int x){
    visited[y][x] = 1;
    cout << "(" << y << ", " << x << ")" << '\n';

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if(!a[ny][nx]) continue;
        if(visited[ny][nx]) continue;
        go(ny, nx);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    a[0][0] = 1;
    a[0][2] = 1;
    a[1][0] = 1;
    a[1][2] = 1;
    a[2][1] = 1;
    a[2][2] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] && !visited[i][j]) go(i,j);
        }
    }

    return 0;
}
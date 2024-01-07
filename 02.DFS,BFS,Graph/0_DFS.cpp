#include <bits/stdc++.h>
using namespace std;
const int n = 5, m = 5;
int ret = 0;
int a[100][100], visited[100][100];

const int dy[] = {0,0,1,-1};
const int dx[] = {1,-1,0,0};

void go(int y, int x){
    visited[y][x] = 1;

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
    a[0][4] = 1;
    a[1][0] = 1;
    a[1][1] = 1;
    a[1][4] = 1;
    a[2][3] = 1;
    a[2][4] = 1;
    a[3][3] = 1;
    a[3][4] = 1;
    a[4][1] = 1;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] && !visited[i][j]){
                ret++;
                go(i,j);
            }
        }
    }

    cout << ret <<'\n';

    return 0;
}
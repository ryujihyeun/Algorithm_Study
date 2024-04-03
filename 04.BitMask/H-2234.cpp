#include <bits/stdc++.h>
using namespace std;
int n,m,cnt, maxarea, area, newmaxarea, num, adjarea;
int a[50][50], visited[50][50], areas[2500];
int dy[] = {0,-1,0,1};
int dx[] = {-1,0,1,0};

void dfs(int y, int x){
    visited[y][x] = num;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny > n || nx < 0 || nx >= m) continue;
        if(a[y][x] & (1<<i)){
            if(visited[ny][nx] && visited[ny][nx] != num) adjarea = max(adjarea,areas[visited[ny][nx]]);
        }
        if(visited[ny][nx]) continue;
        if(!(a[y][x] & (1<<i))){
            dfs(ny,nx);
        }
    }
    area++;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j]) continue;
            cnt++; area = 0; adjarea = 0; num++;
            dfs(i,j);
            areas[num] = area;
            newmaxarea = max(newmaxarea, area + adjarea);
            maxarea = max(maxarea, area);
        }
    }

    cout << cnt << '\n' << maxarea << '\n' << newmaxarea;

    return 0;
}
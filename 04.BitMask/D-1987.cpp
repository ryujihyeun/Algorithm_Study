#include <bits/stdc++.h>
using namespace std;
int n,m,ret,tmp,check=0;
char a[20][20];
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
int visited[20][20];

void dfs(int y, int x){
    ret = max(ret,tmp);
    visited[y][x] = 1;
    //cout << a[y][x] << " " << tmp <<'\n';
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(visited[ny][nx]) continue;
        if(check & (1 << (a[ny][nx] - 'A'))) continue;
        check |= (1 << (a[ny][nx] - 'A'));
        tmp++; visited[ny][nx] = 1;
        dfs(ny,nx);
        tmp--; visited[ny][nx] = 0;
        check &= ~(1 << (a[ny][nx] - 'A'));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    check |= (1 << (a[0][0] - 'A'));
    tmp = 1;
    dfs(0,0);
    cout << ret;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n, m, k, ret;
char road[5][5];
int visited[5][5];
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void go(int y, int x, int cnt){
    cout << y << ":" << x << " cnt: " << cnt << '\n';
    if(cnt > k) return;
    if(cnt == k && y == 0 && x == m-1){
        ret++; return;
    }
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
        if(road[ny][nx] == 'T') continue;
        visited[ny][nx] = 1;
        go(ny,nx,++cnt);
        cnt--;
        visited[ny][nx] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> road[i][j];
        }
    }
    visited[n-1][0] = 1;
    go(n-1,0,1);
    cout << ret;

    return 0;
}
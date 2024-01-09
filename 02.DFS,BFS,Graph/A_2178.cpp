#include <bits/stdc++.h>
using namespace std;
int n, m, ret;
int visited[100][100], a[100][100];

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

int main(){
    //ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%1d",&a[i][j]);
        }
    }

    queue<pair<int,int>> q;
    int x, y;
    q.push({0,0});
    visited[0][0] = 1;

    while(q.size()){
        tie(y,x) = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >=n || nx < 0 || nx >=m || a[ny][nx] == 0) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }

    cout << visited[n-1][m-1];

    return 0;
}
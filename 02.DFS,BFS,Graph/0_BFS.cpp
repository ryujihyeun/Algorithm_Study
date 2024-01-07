#include <bits/stdc++.h>
using namespace std;
int n, m, ret, sy, sx, ey, ex;
int a[100][100], visited[100][100];

const int dy[] = {0,0,1,-1};
const int dx[] = {1,-1,0,0};

void bfs(){
    queue<pair<int,int>> q;
    int y, x;
    visited[sy][sx] = 1;
    q.push({sy,sx});
    while(q.size()){
        tie(y,x) = q.front(); 
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >=n || nx < 0 || nx >= m || a[ny][nx] == 0) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    cin >> sy >> sx;
    cin >> ey >> ex;

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cin >> a[i][j];
		}
	}

    bfs();

    cout << visited[ey][ex] <<'\n';

    return 0;
}
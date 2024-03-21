#include <bits/stdc++.h>
using namespace std;
int n,m,ret,sx,sy,ex,ey;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
int visited[301][301];
char zmap[301][301];


void print(){
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <=m; j++){
            cout << zmap[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void bfs(){
    queue<pair<int,int>> q;
    q.push({sy,sx});
    visited[sy][sx] = 1;
    int y, x;
    while(q.size()){
        tie(y,x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 1 || ny >= n+1 || nx < 1 || nx >= m+1) continue;
            if(visited[ny][nx]) continue;
            if(zmap[ny][nx] == '0'){
                visited[ny][nx] = 1;
                q.push({ny,nx});
            }
            if(zmap[ny][nx] == '1'){
                zmap[ny][nx] = '0';
                visited[ny][nx] = 1;
            }
            if(zmap[ny][nx] == '#'){
                zmap[ny][nx] = '2';
            }
        }
    }
    fill(&visited[0][0], &visited[0][0] + 301*301, 0);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    cin >> sy >> sx >> ey >> ex;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> zmap[i][j];
        }
    }
    if(ey == sy && ex == sx){
        cout << 0;
        return 0;
    }

    while(true){
        if(zmap[ey][ex] == '2') break;
        ret++;
        bfs();
        //print();
    }

    cout << ret;
    
    return 0;
}
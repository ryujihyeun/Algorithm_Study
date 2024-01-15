#include <bits/stdc++.h>
using namespace std;
int n,m,rtime = 0, tarea = 0,rarea = 0;
int a[100][100], visited[100][100];
vector<pair<int,int>> melt;

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void printmap(){
    cout << '\n';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

void bfs(int sy, int sx){
    queue<pair<int,int>> q;
    int x,y;
    visited[sy][sx] = 1;
    q.push({sy,sx});
    while (q.size())
    {
        tie(y,x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(visited[ny][nx]) continue;
            if(a[ny][nx] == 1){
                melt.push_back({ny,nx});
                continue;
            }
            visited[ny][nx] = 1;
            q.push({ny,nx});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 1) rarea++;
        }
    }

    while(true){
        bfs(0,0);
        if(melt.size() == 0)break;
        rtime++;
        for(auto it: melt){
            a[it.first][it.second] = 0;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 1) tarea++;
            }
        }
        if(tarea == 0) break;
        else rarea = min(rarea,tarea);
        
        // initialize
        melt.clear();
        fill(&visited[0][0], &visited[0][0] + 100*100, 0);
        tarea = 0;
    }

    cout << rtime << '\n';
    cout << rarea << '\n';

    return 0;
}
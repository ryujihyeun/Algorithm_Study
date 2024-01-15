#include <bits/stdc++.h>
using namespace std;
int n,m,ret,tret;
int a[8][8], visited[8][8];
vector<pair<int,int>> wall, virus, nwall;

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void printmap(){
    cout << '\n';
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}

void dfs(int y, int x){
    visited[y][x] = 1;
    tret++;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if(visited[ny][nx]) continue;
        if(a[ny][nx] == 0) {
            dfs(ny,nx);
        }
    }
}

void bfs(int idx1,int idx2,int idx3){
    // new wall
    int x,y;
    tie(y,x) = nwall[idx1];
    visited[y][x] = 99;
    tie(y,x) = nwall[idx2];
    visited[y][x] = 99;
    tie(y,x) = nwall[idx3];
    visited[y][x] = 99;
    // set queue for virus
    queue<pair<int,int>> q;
    for(auto it: virus){
        q.push(it);
        visited[it.first][it.second] = 1;
    }
    // bfs for virus
    while(q.size()){
        tie(y,x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 1) continue;
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
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 0) nwall.push_back({i,j});
            if(a[i][j] == 1) wall.push_back({i,j});
            if(a[i][j] == 2) virus.push_back({i,j});
        }
    }

    ret = 0;
    for(int i = 0; i < nwall.size(); i++){
        for(int j = i + 1; j < nwall.size(); j++){
            for(int k = j + 1; k < nwall.size(); k++){
                // bfs
                bfs(i,j,k);
                // dfs
                for(int iy = 0; iy < n; iy++){
                    for(int ix = 0; ix < m; ix++){
                        if(a[iy][ix]==0 && !visited[iy][ix]) dfs(iy,ix);
                    }
                }
                ret = max(ret,tret);
                // initialized
                tret = 0;
                fill(&visited[0][0], &visited[0][0] + 8*8, 0);
            }
        }
    }

    cout << ret << '\n';

    return 0;
}
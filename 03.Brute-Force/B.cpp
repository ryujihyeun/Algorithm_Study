#include <bits/stdc++.h>
using namespace std;
int n,m,ret = 0;
int tmap[50][50], visited[50][50];
vector<pair<int,int>> land;

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void print(vector<int> v){
	for(int i : v) cout << i << " ";
	cout << '\n';
}

void bfs(int sy, int sx){
    int x,y;
    queue<pair<int,int>> q;
    q.push({sy,sx});
    visited[sy][sx] = 1;

    while(q.size()){
        tie(y,x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(visited[ny][nx]) continue;
            if(tmap[ny][nx] == 1){
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny,nx});
            } 
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) ret = max(ret,visited[i][j]-1);
    }

    fill(&visited[0][0], &visited[0][0] + 50*50, 0);
    return;
}


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < m; j++){
            if(str[j] == 'L'){
                tmap[i][j] = 1;
                land.push_back({i,j});
            }
            else tmap[i][j] = 0;
        }
    }
    
    for(int i = 0; i < land.size()-1; i++){
        int sy,sx;
        tie(sy,sx) = land[i];
        //cout << "sy,sx " << sy << ":" << sx << '\n';
        bfs(sy,sx);
        //cout << "ret: " << ret << '\n';
    }

    cout << ret;

    return 0;
}
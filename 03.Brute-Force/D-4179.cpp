#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int r,c,x,y,sx,sy,ret = 0;
string str;
char mp[1004][1004];
int visited[1004][1004], firecheck[1004][1004];
vector<pair<int,int>> fire;

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    fill(&firecheck[0][0], &firecheck[0][0] + 1004 * 1004, INF); 
    queue<pair<int,int>> q;
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> mp[i][j];
            if(mp[i][j] == 'J'){
                sy = i; sx = j;
            }
            else if(mp[i][j] == 'F'){
                q.push({i,j}); firecheck[i][j] = 1;
            }
        }
    }
    
    // Fire
    while(q.size()){
        tie(y,x) = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if(firecheck[ny][nx] != INF || mp[ny][nx] == '#') continue;
            firecheck[ny][nx] = firecheck[y][x] + 1;
            q.push({ny,nx});
        }
    }
    // JiHoon
    q.push({sy,sx});
    visited[sy][sx] = 1;

    while(q.size()){
        tie(y,x) = q.front(); q.pop();
        if(y == r-1 || y == 0 || x == c-1 || x == 0){
            ret = visited[y][x];
            break;
        }
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if(visited[ny][nx] || mp[ny][nx] == '#') continue;
            if(firecheck[ny][nx] <= visited[y][x]+1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny,nx});
        }
    }

    if(ret != 0) cout << ret << "\n";
	else cout << "IMPOSSIBLE \n";

    return 0;
}
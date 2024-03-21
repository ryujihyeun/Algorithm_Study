#include <bits/stdc++.h>
using namespace std;
int n, ret = 987654321;
int garden[10][10], visited[10][10];
vector<pair<int,int>> seed;

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

int sum(int y, int x){
    int tmp = garden[y][x];
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        tmp += garden[ny][nx];
    }
    return tmp;
}

void go(int here, vector<pair<int,int>> v){
    if(v.size() == 3){
        int x,y,tmp = 0;
        for(int i = 0; i < 3; i++){
            tie(y,x) = v.back(); v.pop_back();
            tmp += sum(y,x);
        }
        ret = min(ret, tmp);
        return;
    }
    for(int i = here; i < n-1; i++){
        for(int j = 1; j < n-1; j++){
            if(visited[i][j] || visited[i][j-1] || visited[i][j+1] || visited[i-1][j] || visited[i+1][j]) continue;
            visited[i][j] = 1; visited[i][j-1] = 1; visited[i][j+1] = 1;
            visited[i-1][j] = 1; visited[i+1][j] = 1;
            v.push_back({i,j});
            go(i,v);
            v.pop_back();
            visited[i][j] = 0; visited[i][j-1] = 0; visited[i][j+1] = 0;
            visited[i-1][j] = 0; visited[i+1][j] = 0;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> garden[i][j];
        }
    }
    vector<pair<int,int>> v;
    go(1,v);
    cout << ret;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n,l,r,flag = 1,ret=0;
int up, un;
int a[50][50], visited[50][50], unit[50][50];
vector<pair<int,int>> moveidx;

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void findUnion(int y, int x, int num){
    visited[y][x] = 1;
    unit[y][x] = num;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if(visited[ny][nx]) continue;
        int diff = abs(a[y][x] - a[ny][nx]);
        if(diff >= l && diff <= r){
            findUnion(ny,nx,num);
        }
    }
}

void popMove(int y, int x){
    visited[y][x] = 1;
    up += a[y][x];
    un++;
    moveidx.push_back({y,x});
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if(visited[ny][nx]) continue;
        if(unit[ny][nx] == unit[y][x]){
            popMove(ny,nx);
        }
    }
}

void go(){
    int num = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                findUnion(i,j,num);
                num++;
            }
        }
    }

    if(num > n*n){
        flag = 0;
        return;
    }

    fill(&visited[0][0], &visited[0][0] + 50*50, 0);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                un = 0; up = 0;
                moveidx.clear();
                popMove(i,j);
                int tmp = up/un;
                for(auto it: moveidx) a[it.first][it.second] = tmp;
            }
        }
    }
    fill(&visited[0][0], &visited[0][0] + 50*50, 0);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    
    while(true){
        go();
        if(flag == 0) break;
        ret++;
    }

    cout << ret;

    return 0;
}
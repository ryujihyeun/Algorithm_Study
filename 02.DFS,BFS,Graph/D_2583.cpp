#include <bits/stdc++.h>
using namespace std;
int m,n,k,ret,reta, rx,ry, lx,ly;
int a[100][100], visited[100][100];
vector<int> area;

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void print(){
    cout << '\n';
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            cout << visited[i][j] << " ";
        }
        cout << '\n';
    }
}

void dfs(int y, int x){
    visited[y][x] = 1;
    reta++;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] == 1) continue;
        if(visited[ny][nx]) continue;
        dfs(ny,nx);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;

    for(int i = 0; i < k; i++){
        cin >> lx >> ly >> rx >> ry;
        for(int c = ly; c < ry; c++){
            for(int d = lx; d < rx; d++){
                a[c][d] = 1;
            }
        }
    }

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j++){
            if(!a[i][j] && !visited[i][j]){
                ret++;
                dfs(i,j);
                area.push_back(reta);
                reta = 0;
            }
        }
    }

    sort(area.begin(),area.end());

    cout << ret <<'\n';
    for(auto it: area){
        cout << it << " ";
    }

    return 0;
}
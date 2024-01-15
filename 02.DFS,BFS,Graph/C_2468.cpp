#include <bits/stdc++.h>
using namespace std;
int n;
int a[100][100], visited[100][100];

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void dfs(int y, int x, int h){
    visited[y][x] = 1;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if(visited[ny][nx]) continue;
        if(a[ny][nx] <= h) continue;
        dfs(ny,nx,h);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int maxh = 1, minh = 1, tmp = 0;
    int ret = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            if(maxh < a[i][j]) maxh = a[i][j];
            if(minh > a[i][j]) minh = a[i][j];
        }
    }
    
    for(int h = minh; h <= maxh; h++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(!visited[i][j] && a[i][j] > h){
                    tmp++;
                    dfs(i,j,h);
                }
            }
        }
        if(tmp > ret) ret = tmp;
        tmp = 0;
        fill(&visited[0][0], &visited[0][0] + 100*100, 0);
    }
    
    if(maxh==1) ret = 1;
    cout << ret <<'\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int test,m,n,k,ret;
int visited[50][50], a[50][50];

int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};

void dfs(int y, int x){
    visited[y][x] = 1;

    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >=n || nx < 0 || nx >=m || a[ny][nx] == 0) continue;
        if(visited[ny][nx]) continue;
        dfs(ny,nx);
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> test;

    for(int i = 0; i < test; i++){
        // get input
        cin >> m >> n >> k;
        for(int j = 0; j < k; j++){
            int x ,y;
            cin >> x >> y;
            a[y][x] = 1;
        }
        // dfs
        for(int c = 0; c < n; c++){
            for(int d = 0; d < m; d++){
                if(a[c][d] && !visited[c][d]){
                    ret++;
                    dfs(c,d);
                }
            }
        }
        cout << ret << '\n';

        // initialized
        ret = 0;
        fill(&a[0][0], &a[0][0] + 50*50, 0);
        fill(&visited[0][0], &visited[0][0] + 50*50, 0);
    }
    return 0;
}
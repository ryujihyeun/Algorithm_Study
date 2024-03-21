#include <bits/stdc++.h>
using namespace std;
int n,m,h,ret = 987654321;
int visited[30][10];
// 0: down / 1: right / 2: left

bool check(){
    for(int i = 1; i <= n; i++){
        int start = i;
        for(int j = 1; j <= h; j++){
            if(visited[j][start]) start++;
            else if(visited[j][start-1]) start--;
        }
        if(start != i) return false;
    }
    return true;
}

void go(int here, int cnt){
    if(cnt > 3 || cnt >= ret) return;
    if(check()){
        ret = min(ret,cnt); return;
    }
    for(int i = here; i <= h; i++){
        for(int j = 1; j <= n; j++){
            if(visited[i][j] || visited[i][j-1] || visited[i][j+1]) continue;
            visited[i][j] = 1;
            go(i,cnt++);
            visited[i][j] = 0;
        }

    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> h;

    for(int i = 1; i <= m ; i++){
        int a ,b;
        cin >> a >> b; visited[a][b] = 1;
    }

    go(1,0);
    cout << ret << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n,m,ret;
int a[9][9];
int dy[] = {0,-1,0,1};
int dx[] = {1,0,-1,0};
vector<pair<int,int>> v;

void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void go(int here){
    if(here == v.size()){
        print();
        int tmp = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == 0) tmp++;
            }
        }
        ret = min(ret,tmp);
        cout << "tmp: " << tmp <<'\n';
        return;
    }
    
    int x,y;
    tie(y,x) = v[here];
    int cctv = a[y][x];
    int dir = 4;
    vector<int> checkdir = {0};
    if(cctv == 2) {dir -= 2; checkdir.push_back(2);}
    if(cctv == 5) {dir -= 3; checkdir.push_back(1);}
    if(cctv >= 4) checkdir.push_back(2);
    if(cctv >= 3) checkdir.push_back(3);
    
    // 돌릴수 있는 경우의 수
    for(int i = 0; i < dir; i++){
        vector<pair<int,int>> restore;
        // cctv 종류에 따라 확인
        for(int j = 0; j < checkdir.size(); j++){
            int cy = y, cx = x;
            while(1){
                int ny = cy + dy[checkdir[j]];
                int nx = cx + dx[checkdir[j]];
                if(ny < 0 || ny >=n || nx < 0 || nx >= m) break;
                if(a[ny][nx] == 6) break;
                if(a[ny][nx] != cctv){
                    a[ny][nx] = 7;
                    restore.push_back({ny,nx});
                }
                cy = ny;
                cx = nx;
            }
            // 회전
            checkdir[j] = (checkdir[j] +1)%4;
        }
        // 다음 cctv 확인
        cout << "here: " << here << '\n';
        print();
        
        go(here+1);
        while(restore.size()){
            int ry,rx;
            tie(ry,rx) = restore.back(); restore.pop_back();
            a[ry][rx] = 0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    ret = n*m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] != 0 && a[i][j] != 6) v.push_back({i,j});
            if(a[i][j] != 0) ret--;
        }
    }

    go(0);
    cout << ret << '\n';

    return 0;
}
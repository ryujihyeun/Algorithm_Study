#include <bits/stdc++.h>
using namespace std;
int n,m,sy,sx,ey,ex,ret;
int dy[] = {0,0,1,-1};
int dx[] = {1,-1,0,0};
char a[1500][1500];
int water[1500][1500], swan[1500][1500];
queue<pair<int,int>> waterQ, waterTQ, swanQ, swanTQ;

void print(int arr[1500][1500]){
    for(int i = 0; i < n; i ++){
        for(int j = 0; j <m; j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}
void print(char arr[1500][1500]){
    for(int i = 0; i < n; i ++){
        for(int j = 0; j <m; j++){
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}
   
void waterMelting(){
    int x,y;
    while(waterQ.size()){
        tie(y,x) = waterQ.front(); waterQ.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(water[ny][nx]) continue;
            if(a[ny][nx] == 'X'){
                a[ny][nx] = '.';
                waterTQ.push({ny,nx});
                water[ny][nx] = 1;
            }
        }
    }
}

bool findSwan(){
    int x,y;
    while(swanQ.size()){
        tie(y,x) = swanQ.front(); swanQ.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if(swan[ny][nx]) continue;
            swan[ny][nx] = 1;
            if(a[ny][nx] == '.') swanQ.push({ny,nx});
            else if(a[ny][nx] == 'X') swanTQ.push({ny,nx});
            else if(a[ny][nx] == 'L') return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] == 'L'){sy = i; sx = j;}
            if(a[i][j] == '.' || a[i][j] == 'L'){
                waterQ.push({i,j}); water[i][j] = 1;
            }
        }
    }
    swanQ.push({sy,sx});
    swan[sy][sx] = 1;

    while(true){
        if(findSwan()) break;
        
        // check melting point
        waterMelting();
        waterQ = waterTQ;
        swanQ = swanTQ;
        while(!waterTQ.empty()) waterTQ.pop();
        while(!swanTQ.empty()) swanTQ.pop();
        ret++;
        //memset(water,0,sizeof(water));
        //memset(swan,0,sizeof(swan));
        //print(water);
        //print(a);
    }
    cout << ret;

    return 0;
}
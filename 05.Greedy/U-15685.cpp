#include <bits/stdc++.h>
using namespace std;
int n,ret;
int a[101][101];

int dy[] = {0,-1,0,1};
int dx[] = {1,0,-1,0};

void print(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) cout << a[i][j] << " ";
        cout << '\n';
    }
    cout << '\n';
}

void dragon(int x, int y, int d, int g){
    vector<int> dir;
    int ny ,nx;
    a[y][x] = 1;
    int sx = x + dx[d];
    int sy = y + dy[d];
    a[sy][sx] = 1;
    dir.push_back(d);

    while(g){
        vector<int> tmp = dir;
        while(tmp.size()){
            int nd = (tmp.back() + 1) % 4;
            tmp.pop_back();
            dir.push_back(nd);
            ny = sy + dy[nd];
            nx = sx + dx[nd];
            a[ny][nx] = 1;
            sy = ny; sx = nx;
        }
        g--;
        //print();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;

    for(int i = 0; i < n; i++){
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        dragon(x,y,d,g);
    }
    //print();
    for(int i = 0; i < 100; i++){
        for(int j = 0; j <100; j++){
            if(a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1]) ret++;
        }
    }
    cout << ret << '\n';

    return 0;
}
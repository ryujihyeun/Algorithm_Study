#include <bits/stdc++.h>
using namespace std;
int n, ret;

struct board{
    int a[21][21];

    void rotate90(){
        int temp[21][21];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                temp[i][j] = a[n-j-1][i];
            }
        }
        memcpy(a,temp,sizeof(a));
    }

    void move(){
        int temp[21][21];
        for(int i = 0; i < n; i++){
            int c = -1, d = 0;
            for(int j = 0; j < n; j++){
                if(a[i][j] == 0) continue;
                else if(d && a[i][j] == temp[i][c]) temp[i][c] *=2, d = 0;
                else temp[i][++c] = a[i][j], d = 1;
            }
            for(c++; c < n; c++) temp[i][c] = 0;
        }
        memcpy(a, temp, sizeof(a));
    }

    void getmax(){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ret = max(ret,a[i][j]);
            }
        }
    }

};

void go(int cnt, board b){
    if(cnt == 5){
        b.getmax();
        return;
    }

    for(int i = 0; i < 4; i++){
        board c = b;
        c.move();
        go(cnt+1, c);
        b.rotate90();
    }
}


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    board brd;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> brd.a[i][j];
        }
    }

    go(0,brd);
    cout << ret << '\n';

    return 0;
}
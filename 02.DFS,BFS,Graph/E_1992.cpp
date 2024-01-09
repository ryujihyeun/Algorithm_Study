#include <bits/stdc++.h>
using namespace std;
int n;
int a[64][64];
string ret;
char ch('(');
char ch2(')');

void quad(int y, int x, int m){
    //cout << "y:x:m " << y << " : " << x << " : " << m << '\n';
    int st = a[y][x];
    int flag = 0;

    for(int i = y; i < y+m; i++){
        for(int j = x; j < x+m; j++){
            int cur = a[i][j];
            if(cur != st){
                flag = 1;
                break;
            }
        }
        if(flag == 1) break;
    }
    if(flag == 1){
        // 왼위
        //cout << m << " 왼위\n";
        ret.push_back(ch);
        quad(y,x,m/2);
        // 오위
        //cout << m << " 오위\n";
        quad(y, x + m/2, m/2);
        // 왼아
        //cout << m << " 왼아\n";
        quad(y+m/2,x,m/2);   
        // 오아
        //cout << m << " 오아\n";
        quad(y+m/2,x+m/2,m/2);
        ret.push_back(ch2);
        //cout << ret << '\n';
    }
    else{
        char ch1('0');
        ch1 += st;
        ret.push_back(ch1);
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%1d", &a[i][j]);
        }
    }
    quad(0,0,n);

    cout << ret;

    return 0;
}
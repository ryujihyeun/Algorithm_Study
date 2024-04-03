#include <bits/stdc++.h>
using namespace std;
int n,m,k,ret = 987654321;
int a[51][51],tmparr[51][51];
int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
vector<int> v[6], idx;

void print(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void findvalue(){
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 1; j <= m; j++) sum += a[i][j];
        ret = min(ret,sum);
    }
}

void rotateA(int r, int c, int s){
    int i = 0;
    int y = r-s, x = c-s, tmp;
    int prev = a[y][x];
    while(1){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(nx == c+s && ny == r-s) i++;
        if(nx == c+s && ny == r+s) i++;
        if(nx == c-s && ny == r+s) i++;
        tmp = a[ny][nx];
        a[ny][nx] = prev;
        prev = tmp;
        y = ny, x = nx;
        if(nx == c-s && ny == r-s){
            s--; i = 0;
            y = r-s, x = c-s;
            prev = a[y][x];
        }
        if(s == 0) break;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=m; j++){
            cin >> a[i][j];
        }
    }
    int r,c,s;
    for(int i = 0; i < k; i++){
        cin >> r >> c >> s;
        v[i].push_back(r);
        v[i].push_back(c);
        v[i].push_back(s);
        idx.push_back(i);
    }

    do{
        memcpy(tmparr,a,sizeof(a));
        for(int i : idx){
            //cout << i << "\n";
            rotateA(v[i][0], v[i][1], v[i][2]);
            //print();
        }
        //cout << '\n';
        findvalue();
        memcpy(a,tmparr,sizeof(a));
    } while(next_permutation(idx.begin(),idx.end()));

    cout << ret << '\n';

    return 0;
}
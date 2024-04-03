#include <bits/stdc++.h>
using namespace std;
int n,m,t,ret;
deque<int> disk[51];

void print(){
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            cout << disk[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

void average(){
    int sum = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            if(disk[i][j] == -1) continue;
            sum += disk[i][j];
            cnt++;
        }
    }
    float av = (float)sum/cnt;
    //cout << "average: " << av << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            if(disk[i][j] == -1) continue;
            if(disk[i][j] > av) disk[i][j] -= 1;
            else if(disk[i][j] < av) disk[i][j] += 1;
        }
    }
}

void checkadj(int i, int j, vector<pair<int,int>> &idx){
    int num = disk[i][j];
    int size = idx.size();
    if(j == 0){
        if(disk[i][1] == num) idx.push_back({i,1});
        if(disk[i][m-1] == num) idx.push_back({i,m-1});
    }
    else if(j == m-1){
        if(disk[i][m-2] == num) idx.push_back({i,m-2});
        if(disk[i][0] == num) idx.push_back({i,0});
    }
    else{
        if(disk[i][j-1] == num) idx.push_back({i,j-1});
        if(disk[i][j+1] == num) idx.push_back({i,j+1});
    }

    if(i == 1){
        if(disk[2][j] == num) idx.push_back({2,j});
    }
    else if(i == n){
        if(disk[n-1][j] == num) idx.push_back({n-1,j});
    }
    else{
        if(disk[i-1][j] == num) idx.push_back({i-1,j});
        if(disk[i+1][j] == num) idx.push_back({i+1,j});
    }
    
    if(idx.size() != size) idx.push_back({i,j});
}

void check(){
    vector<pair<int,int>> idx;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            if(disk[i][j] == -1) continue;
            checkadj(i,j,idx);
        }
    }

    if(idx.size()){
        for(int i = 0; i < idx.size(); i++){
            int x,y;
            tie(y,x) = idx[i];
            disk[y][x] = -1;
        }
    }
    else average();
}

void rotate(int x, int d, int k){
    if(d == 0){
        while(k){
            int tmp = disk[x].back();
            disk[x].pop_back();
            disk[x].push_front(tmp);
            k--;
        }
    }
    else{
        while(k){
            int tmp = disk[x].front();
            disk[x].pop_front();
            disk[x].push_back(tmp);
            k--;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            int tmp;
            cin >> tmp;
            disk[i].push_back(tmp);
        }
    }

    for(int i = 0; i < t; i++){
        int x,d,k;
        cin >> x >> d >> k;
        for(int i = x; i <=n; i+=x){
            rotate(i,d,k);
        }
        //print();
        check();
        //print();
    }

    for(int i = 1; i <=n; i++){
        for(int j = 0; j < m; j++){
            if(disk[i][j] > 0) ret += disk[i][j];
        }
    }
  
    cout << ret << '\n';

    return 0;
}
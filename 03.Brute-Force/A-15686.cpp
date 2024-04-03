#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll ret = 10000000000000;
vector<pair<int,int>> house, chicken;

ll usum(pair<int,int> h, pair<int,int> c){
    ll sumret = 0;
    sumret = abs(h.first - c.first) + abs(h.second - c.second);
    return sumret;
}

void print(vector<int> v){
	for(int i : v) cout << i << " ";
	cout << '\n';
}

void go2(int idx, vector<int> v){
    if(v.size() > m) return;
    if(idx == chicken.size()){
        //print(v);
        ll sum = 0;
        for(auto h: house){
            ll md = 1000000000;
            for(int i : v) md = min(md, usum(h,chicken[i]));
            sum += md;
        }
        ret = min(ret,sum);
        return;
    }
    go2(idx+1, v);
    v.push_back(idx);
    go2(idx+1, v);
}


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int tmp;
            cin >> tmp;
            if(tmp == 1) house.push_back({i,j});
            if(tmp == 2) chicken.push_back({i,j});
        }
    }

    vector<int> v;
    go2(0, v);
    
    cout << ret << '\n';

    return 0;
}
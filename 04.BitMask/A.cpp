#include <bits/stdc++.h>
using namespace std;
int n, mp, mf, ms, mv, pi,fi,si,vi,ci,ret=987654321;
int food[16][5];
int nutri[4];
vector<int> retnum(15);

void count(vector<int> v){
    int tmp = 0, cnt = 0;
    for(int i = 0; i < 4; i++){
        for(int it : v) tmp += food[it][i];
        if(tmp < nutri[i]) return;
        tmp = 0;
    }
    for(int it : v) cnt += food[it][4];
    if(ret > cnt){
        ret = cnt;
        retnum.clear();
        for(int it: v) retnum.push_back(it);
    }
    if(ret == cnt){
        int minsize = min(v.size(),retnum.size());
        for(int i = 0; i < minsize; i++){
            if(v[i] < retnum[i]){
                ret = cnt;
                retnum.clear();
                for(int it: v) retnum.push_back(it);
                return;
            }
            if(v[i] > retnum[i]) return;
        }
        if(retnum.size() < v.size()) return;
        else{
            ret = cnt;
            retnum.clear();
            for(int it: v) retnum.push_back(it);
        }
    }
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < 4; i++) cin >> nutri[i];
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 5; j++) cin >> food[i][j];
    }

    for(int i = 0; i < (1 << n); i++){
        vector<int> v;
        for(int j = 0; j < n; j++){
            if(i & (1<<j)) v.push_back(j+1);
        }
        count(v);
        v.clear();
    }


    if(ret == 987654321){
        cout << -1;
        return 0;
    }
    else{
        cout << ret << '\n';
        for(auto it : retnum) cout << it << " ";
    }

    return 0;
}
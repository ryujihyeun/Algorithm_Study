#include <bits/stdc++.h>
using namespace std;
int n,from,to,ret,idx;
vector<pair<int,int>> v;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> from >> to;
        v.push_back({to,from});
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        //cout << v[i].first << ":" << v[i].second << '\n';
        if(idx > v[i].second) continue;
        idx = v[i].first;
        ret++;
        //cout << "ret: " << ret << " idx: " << idx << '\n';
    }

    cout << ret << '\n';

    return 0;
}
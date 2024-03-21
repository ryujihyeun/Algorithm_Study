#include <bits/stdc++.h>
using namespace std;
int n,at,t,cur,ret;
vector<pair<int,int>> v;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> at >> t;
        v.push_back({at, t});
    }
    sort(v.begin(),v.end());

    for(int i = 0; i < v.size(); i++){
        //cout << v[i].first << ":" << v[i].second << '\n';
        if(ret >= v[i].first) ret += v[i].second;
        else ret = v[i].first + v[i].second;
    }

    cout << ret << '\n';

    return 0;
}
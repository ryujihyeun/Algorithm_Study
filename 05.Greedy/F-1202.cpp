#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,ret;
priority_queue<ll> pq;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    vector<pair<int,int>> gem(n);
    vector<int> bag(k);
    for(int i = 0; i < n; i++){
        cin >> gem[i].first >> gem[i].second;
    }
    for(int i = 0; i < k; i++) cin >> bag[i];

    sort(gem.begin(),gem.end());
    sort(bag.begin(),bag.end());

    int j = 0;
    for(int i = 0; i < k; i++){
        while(j < n && gem[j].first <= bag[i]) pq.push(gem[j++].second);
        if(pq.size()){
            ret += pq.top(); pq.pop();
        }
    }

    cout << ret << '\n';

    return 0;
}
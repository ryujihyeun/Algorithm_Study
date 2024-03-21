#include <bits/stdc++.h>
using namespace std;
int n,l,r,ret;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        pq.push({x,y});
    }
    l = pq.top().first;
    r = pq.top().second;
    pq.pop();
    while(pq.size()){
        if(pq.top().first > r){
            ret += r-l;
            l = pq.top().first;
            r = pq.top().second;
        } // 이전 l,r과 겹치지 않을 때
        else{
            if(pq.top().second > r) r = pq.top().second;
        }
        pq.pop();
    }
    ret += r-l;
    cout << ret << '\n';

    return 0;
}
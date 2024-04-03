#include <bits/stdc++.h>
using namespace std;
int n,l,ret;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        int s,e;
        cin >> s >> e;
        pq.push({s,e});
    }
    
    int s,e;
    int boardend = 0;
    while(pq.size()){
        //cout << pq.top().first << ":" << pq.top().second << '\n';
        if(boardend >= pq.top().second) {pq.pop(); continue;}
        if(boardend > pq.top().first) s = boardend;
        else s = pq.top().first;
        e = pq.top().second;
        
        // count boards;
        //cout << "s:e " << s << ":" << e << '\n';
        int cnt = (e-s)/l;
        if(cnt*l < (e-s)) cnt++;
        ret += cnt;
        boardend = s + cnt*l;
        pq.pop();
    }
     
    cout << ret << '\n';

    return 0;
}
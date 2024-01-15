#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,ret,maxv = 0;
vector<int> adj[10001];
int visited[10001], leaf[10001];

void dfs(int here){
    visited[here] = 1;
    ret++;
    for(int it : adj[here]){
        if(visited[it]) continue;
        dfs(it);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        adj[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        dfs(i);
        leaf[i] = ret;
        maxv = max(maxv, ret);
        ret = 0;
        fill(&visited[0], &visited[0] + 10001, 0);
    }

    for(int i = 1; i <= n; i++){
        if(leaf[i] == maxv) cout << i << " ";
    }

    return 0;
}
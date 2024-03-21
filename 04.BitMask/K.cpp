#include <bits/stdc++.h>
using namespace std;
int t,n,e,ret,visited[1001],adj[1001];

void dfs(int here){
    visited[here] = 1;

    for(int i = 1; i <= n; i++){
        if(visited[i])continue;
        if(adj[here] & (1<<(i-1))){
            dfs(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for(int i = 0; i < t; i++){
        fill(adj, adj+1001,0);
        cin >> n;
        cin >> e;
        string str = "tree";
        if(e != n-1) str = "graph";
        for(int j = 0; j < e; j++){
            int a,b;
            cin >> a >> b;
            if(adj[a] & (1<<(b-1))) str = "graph";
            if(adj[b] & (1<<(a-1))) str = "graph";
            adj[a] |= (1<<(b-1));
            adj[b] |= (1<<(a-1));
        }

        if(str == "tree"){
            dfs(1);
            for(int c = 1; c <= n; c++){
                if(visited[c] == 0){
                    str = "graph";
                    break;
                }
            }
        }
        cout << str << '\n';
    }
    return 0;
}
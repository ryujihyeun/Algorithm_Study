#include <bits/stdc++.h>
using namespace std;
int n, ret = 987654321, totalpop;
int pop[11], visited[11], comp[11];
vector<int> adj[11];

pair<int,int> dfs(int here, int number){
    visited[here] = 1;
    pair<int,int> result = {1,pop[here]};

    for(int there : adj[here]){
        if(visited[there]) continue;
        if(comp[there] != number) continue;
        pair<int,int> tmp = dfs(there, number);
        result.first += tmp.first;
        result.second += tmp.second;
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> pop[i];
        totalpop += pop[i];
    }
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        for(int j = 0; j < a; j++){
            int idx;
            cin >> idx;
            adj[i].push_back(idx);
        }
    }

    for(int i = 1; i < (1<<n)-1; i++){
        fill(comp, comp + 11, 0);
        fill(visited, visited + 11, 0);
        int red = -1, blue = -1;
        for(int j = 0; j < n; j++){
            if(i & (1<<j)) {
                comp[j+1] = 1;
                red = j+1;
            }
            else blue = j+1;
        }
        pair<int,int> comp1 = dfs(red,1);
        pair<int,int> comp2 = dfs(blue,0);
        if(comp1.first + comp2.first == n) ret = min(ret,abs(comp1.second - comp2.second));
    }

    cout << (ret == 987654321 ? -1:ret);

    return 0;
}
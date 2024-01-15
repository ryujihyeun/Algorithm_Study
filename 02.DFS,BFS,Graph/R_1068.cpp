#include <bits/stdc++.h>
using namespace std;
int n,e,root,ret=0;
vector<int> adj[54];
int visited[54];

void postorder(int here){
    if(here == e) return;
    //cout << "here: " << here << '\n';
    if(visited[here] == 0){
        if(adj[here].size() == 0) ret++;
        else{
            if(adj[here].size() == 1 && adj[here][0] == e){
                ret++;
            }
            else{
                for(int i = 0; i < adj[here].size(); i++){
                    postorder(adj[here][i]);
                }
            }
        }      
        visited[here] = 1;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i =0; i<n; i++){
        int tmp;
        cin >> tmp;
        if(tmp == -1) root = i;
        else adj[tmp].push_back(i);
        
    }
    cin >> e;

    postorder(root);
    if(root == e){
        cout << 0 << "\n"; return 0;
    } 
    cout << ret << '\n';
    return 0;
}
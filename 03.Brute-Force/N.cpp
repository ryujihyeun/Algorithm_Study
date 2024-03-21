#include <bits/stdc++.h>
using namespace std;
int k,num,root,tmp,visited[1040];
vector<int> tree[1040];
queue<int> q;


void go(vector<int> v){
    int center = v.size()/2;
    if(v.size() == 3){
        tree[v[center]].push_back(v[0]);
        tree[v[center]].push_back(v[2]);
        return;
    }

    vector<int> left;
    vector<int> right;

    for(int i = 0; i < v.size(); i++){
        if(i < center) left.push_back(v[i]);
        if(i > center) right.push_back(v[i]);
    }
    tree[v[center]].push_back(v[left.size()/2]);
    tree[v[center]].push_back(v[center + right.size()/2 + 1]);

    go(left);
    go(right);
}

void printtree(){
    visited[root] = 1; q.push(root);
    cout << root << '\n';
    int cnt = 1, level = 2;
    while(q.size()){
        int p = q.front(); q.pop();
        for(int it : tree[p]){
            if(visited[it]) continue;
            cout << it << " ";
            q.push(it); visited[it] = 1; cnt++;
        }
        if(pow(2,level)-1 == cnt){
            cout << "\n";
            level++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> k;
    num = pow(2,k) - 1;
    vector<int> v;
    for(int i = 0; i < num; i++){
        cin >> tmp;
        v.push_back(tmp);
    }

    go(v);
    root = v[num/2];
    printtree();
    return 0;
}
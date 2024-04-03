#include <bits/stdc++.h>
using namespace std;
int n, visited[10];
vector<string> ret;
vector<char> arr = {0,1,2,3,4,5,6,7,8,9};
vector<char> ineq;

void print(vector<int> v){
    for(auto it: v){
        cout << it << " ";
    }
    cout << '\n';
}

bool check(char a, char b, char op){
    if(a < b && op == '<') return true;
    if(a > b && op == '>') return true;
    return false;
}

void go(int idx, string num){
    if(idx == n+1){
        ret.push_back(num);
        return;
    }

    for(int i = 0 ; i < 10; i++){
        if(visited[i]) continue;
        if(idx == 0 || check(num[idx-1], i + '0', ineq[idx-1])){
            visited[i] = 1;
            go(idx+1, num + to_string(i));
            visited[i] = 0;
        }
    }
}



int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    char tmp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        ineq.push_back(tmp);
    }

    go(0,"");
    sort(ret.begin(), ret.end());
    cout << ret[ret.size()-1] << '\n' << ret[0] << '\n';
    return 0;
}
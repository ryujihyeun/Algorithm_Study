#include <bits/stdc++.h>
using namespace std;
int n, ret, check[200001], cnt;
string s;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;

    for(int i = 0; i < n; i++){
        if(s[i] == '(') v.push_back(i);
        else if(v.size()){
            check[i] = check[v.back()] = 1;
            v.pop_back();
        }
    }

    for(int i = 0; i < n; i++){
        if(check[i]){
            cnt++;
            ret = max(ret,cnt);
        }
        else cnt = 0;
    }

    cout << ret;

    return 0;
}
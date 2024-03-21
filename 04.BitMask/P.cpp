#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ret, tmp;
stack<pair<ll,ll>> stk;


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        int cnt = 1;
        while(stk.size() && stk.top().first <= tmp){
            ret += stk.top().second;
            if(stk.top().first == tmp){
                cnt = stk.top().second + 1;
            }
            else cnt = 1;
            stk.pop();
        }
        if(stk.size()) ret++;
        stk.push({tmp,cnt});
    }
    cout << ret << '\n';

    return 0;
}
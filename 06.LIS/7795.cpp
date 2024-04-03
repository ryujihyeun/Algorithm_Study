#include <bits/stdc++.h>
using namespace std;
int t,n,m,tmp,ret;
vector<int> a,b;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        // initialized
        a.clear();
        b.clear();
        ret = 0;
        // get input
        for(int j = 0; j < n; j++){
            cin >> tmp;
            a.push_back(tmp);
        }
        for(int j = 0; j < m; j++){
            cin >> tmp;
            b.push_back(tmp);
        }
        // sort
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        // find lower bound
        for(int j = 0; j < n; j++){
            auto lower_pos = lower_bound(b.begin(),b.end(),a[j]);
            if(*lower_pos == 0) ret += m;
            else ret += lower_pos-b.begin();
        }

        cout << ret << '\n';

    }

    return 0;
}
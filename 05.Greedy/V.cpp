#include <bits/stdc++.h>
using namespace std;
int n,m,pizza,ret;
int a[1001], b[1001], psum_a[2002], psum_b[2002];
map<int,int> acnt, bcnt;

void countpizza(int n, int psum[], map<int,int> &mp){
    for(int interval = 1; interval <= n; interval++){
        for(int start = interval; start <= n+interval-1; start++){
            int sum = psum[start] - psum[start-interval];
            mp[sum]++;
            if(interval == n) break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> pizza;
    cin >> m >> n;
    for(int i = 1; i <= m; i++){
        cin >> a[i];
        psum_a[i] = psum_a[i-1] + a[i];
    }
    for(int i = 1; i <=m; i++) psum_a[i+m] = psum_a[i+m-1] + a[i];

    for(int i = 1; i <= n; i++){
        cin >> b[i];
        psum_b[i] = psum_b[i-1] + b[i];
    }
    for(int i = 1; i <= n; i++) psum_b[i+n] = psum_b[i+n-1] + b[i];
    
    countpizza(m,psum_a,acnt);
    countpizza(n,psum_b,bcnt);
    ret = acnt[pizza] + bcnt[pizza];

    for(int i = 1; i < pizza; i++){
        ret += (acnt[i] * bcnt[pizza-i]);
    }
    cout << ret << '\n';

    return 0;
}
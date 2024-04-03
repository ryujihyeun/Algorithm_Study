#include <bits/stdc++.h>
using namespace std;
int n,ret;
long psum[4000001];
bool notprime[4000001];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    int idx=1,cnt=0;
    for(int i = 2; i <= n; i++){
        if(notprime[i]) continue;
        psum[idx] = psum[idx-1] +i; 
        idx++; cnt++;
        for(int j = 2*i; j <= n; j+=i){
            notprime[j] = 1;
        }
    }

    int l = 0, r = cnt;
    while(l<r){
        if(psum[r] - psum[l] == n){
            //cout << l << ":" << r << '\n';
            r++, l++, ret++;
        }
        else if(psum[r] - psum[l] > n) r--;
        else if(psum[r] - psum[l] < n) l++,r++;
    }

    //for(int i = 0; i <= cnt; i++) cout << psum[i] << " ";
    //cout << '\n';

    cout << ret << '\n';

    return 0;
}
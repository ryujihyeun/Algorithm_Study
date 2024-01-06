#include <bits/stdc++.h>
using namespace std;
int n,k,ret,temp;
int psum[1000001];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    ret = -100000000;
    psum[0] = 0;

    cin >> n >> k;
    for(int i = 1; i <= n; i ++){
        cin >> temp;
        psum[i] = psum[i-1] + temp;
        if(i >= k) ret = max(ret, psum[i] - psum[i-k]);
    }
    
    cout << ret << '\n';
    return 0;
}
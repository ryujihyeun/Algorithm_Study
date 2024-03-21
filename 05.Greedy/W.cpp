#include <bits/stdc++.h>
using namespace std;
int n, ret;
int psum[100001], a[100001];


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
    }

    ret = psum[n];
    int l=0,r=1;

    while(r <= n){
        ret = max(ret, psum[r] - psum[l]); 
        if(psum[r] - psum[l] < 0) l = r;
        r++;
    }

    cout << ret << '\n';

    return 0;
}
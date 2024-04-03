#include <bits/stdc++.h>
using namespace std;
long n, ret, arr[100001], cnt[100001],l,r;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];

    while(r < n){
        if(!(cnt[arr[r]])){
            cnt[arr[r]]++;
            r++;
        }
        else{
            ret += (r-l);
            cnt[arr[l]]--;
            l++;
        }
    }

    ret += (r-l)*(r-l+1)/2;

    cout << ret << '\n';

    return 0;
}
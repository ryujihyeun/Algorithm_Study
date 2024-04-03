#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s,c,ret,a[1000001],mn=1000000000,sum;

bool check(int mid){
    ll cnt = 0, onion = 0, tmp = 0;

    for(int i = 0; i < s; i++){
        onion = a[i];
        while(1){
            if(onion < mid || cnt >= c) break;
            cnt++;
            onion -= mid;
        }
        tmp += onion;
    }
    //cout << "green onion: " << mid << " remain: " << tmp << " count: " << cnt <<'\n';
    if(cnt == c) ret = min(ret,tmp);
    
    return cnt >= c;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> s >> c;
    for(int i = 0; i < s; i++){
        cin >> a[i];
        mn = min(mn,a[i]);
        sum += a[i];
    }
    ret = sum;
    ll l = 0, h = mn;
    while(l<=h){
        ll mid = (l+h)/2;
        if(check(mid)){
            l = mid+1;
        }
        else h = mid-1;
    }
    
    cout << ret << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n,m,ret=0,a[100001],sum,mx;

bool check(int mid){
    if(mx > mid) return false;
    int tmp = mid;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cout << "   mid & cnt: " << mid << " " << cnt << '\n';
        if(mid - a[i]< 0){
            mid = tmp;
            cnt++;
        }
        mid -= a[i];
    }
    if(mid != tmp) cnt++;
    return cnt <= m;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
        mx = max(mx,a[i]);
    }

    int mid, l = 0, r = sum;

    while(l <= r){
        mid = (l+r)/2;
        cout << "mid: " << mid << '\n';
        if(check(mid)){
            ret = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    
    
    cout << ret << '\n';

    return 0;
}
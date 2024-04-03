#include <bits/stdc++.h>
using namespace std;
long x,y,z,ret;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> x >> y;
    z = (y*100)/x;
    
    if(x == y || z == 99){
        cout << -1 << '\n';
        return 0;
    }

    long l = 0, h = x;
    while(l <= h){
        long mid = (l+h)/2;
        long tmp = (y+mid)*100/(x+mid);
        if(tmp > z) h = mid -1, ret = mid;
        else l = mid+1;
    }

    cout << ret << '\n';

    return 0;
}
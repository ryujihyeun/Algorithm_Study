#include <bits/stdc++.h>
using namespace std;
int n, maxret = -2147483648, minret = 2147483647;
int a[101], op[4];

void go(int here, int ret){
    if(here == n-1){
        minret = min(minret,ret);
        maxret = max(maxret,ret);
        return;
    }

    for(int i = 0; i < 4; i++){
        if(op[i]){
            op[i] = op[i] - 1;
            if(i == 0)  go(here+1,ret + a[here+1]);
            if(i == 1)  go(here+1,ret - a[here+1]);
            if(i == 2)  go(here+1,ret * a[here+1]);
            if(i == 3)  go(here+1,ret / a[here+1]);
            op[i] = op[i] + 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < 4; i++){
        cin >> op[i];
    }

    go(0,a[0]);

    cout << maxret << '\n' << minret << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int t,n,m,ret,tmp;
vector<int> a,b;

int check(int mid){
    if(b.front() > mid) return 0;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        if(b[i] < mid) cnt++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> tmp;
            a.push_back(tmp);
        }
        for(int i = 0; i < m; i++){
            cin >> tmp;
            b.push_back(tmp);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int lo = 0, hi = n-1;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(check(a[mid])){
                hi = mid-1;
            }
            else lo = mid+1;
            
        }

    }

    cout << ret << '\n';

    return 0;
}
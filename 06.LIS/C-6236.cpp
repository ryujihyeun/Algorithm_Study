#include <bits/stdc++.h>
using namespace std;
int n,m,ret,mx,sum,arr[100001];

bool check(int mid){
    int cnt = 0;
    int remain = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > remain){
            cnt++;
            remain = mid;
        }
        remain -= arr[i];
    }
    return cnt > m;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mx = max(mx,arr[i]);
        sum += arr[i];
    }
    
    int l = mx, h = sum;
    while(l<=h){
        int mid = (l+h)/2;
        if(check(mid)){
            l = mid+1;
        }
        else h = mid-1, ret = mid; 
    }
    cout << ret << '\n';

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n,k,ret;
int arr[1001];

void rotate(int idx, int rot){
    int flag  = 0;
    if(rot == 1){
        if(arr[idx] & (1<<7)) flag = 1;
        arr[idx] = (arr[idx] << 1);
        if(flag) arr[idx] |= 1;
    }
    else{
        if(arr[idx] & 1) flag = 1;
        arr[idx] = (arr[idx] >> 1);
        if(flag) arr[idx] |= (1<<7);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        string bit;
        int tmp = 0;;
        cin >> bit;
        for(int j = 0; j < 8; j++){
            if(bit[j] == '1') tmp |= (1<<j);
        }
        arr[i] = tmp;
    }
    cin >> k;
    for(int i = 0; i < k; i++){
        int idx, rot;
        cin >> idx >> rot;
        // 2,6 확인
        vector<int> v;
        for(int j = idx; j < n; j++){
            int a=0,b=0;
            if(arr[j] & (1<<2)) a = 1;
            if(arr[j+1] & (1<<6))b = 1;
            if(a ^ b) v.push_back(j+1);
            else break;
        }
        for(int j = idx; j > 1; j--){
            int a=0,b=0;
            if(arr[j] & (1<<6)) a = 1;
            if(arr[j-1] & (1<<2))b = 1;
            if(a ^ b) v.push_back(j-1);
            else break;
        }
        // rotate
        rotate(idx,rot);
        for(int it : v){
            if(idx%2 == it%2) rotate(it,rot);
            else rotate(it,rot*-1);
        }
    }

    for(int i = 1; i <= n; i++){
        if(arr[i] & 1) ret++;
    }
    /*
    for(int i = 1; i <= n; i++){
        cout << bitset<8>(arr[i]) << '\n';
    }
    */

    cout << ret << '\n';

    return 0;
}
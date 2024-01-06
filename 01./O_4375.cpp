#include <bits/stdc++.h>
using namespace std;

int n;

void go(int n){
    int cnt = 1, ret = 1;  
    while(true){
        if(cnt % n == 0){
            cout << ret << '\n';
            break;
        }
        else{
            cnt = (cnt * 10) + 1;
            cnt %= n;
            ret++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    while(cin >> n){
        go(n);
    }

    return 0;
}
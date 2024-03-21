#include <bits/stdc++.h>
using namespace std;
int n, ret= 987654321;
int coin[44];

void go(int here){
    if(here == n){
        int sum = 0;
        for(int i = 1; i <= (1 << (n-1)); i*=2){
            int cnt = 0;
            for(int j = 1; j <= n; j++) if(coin[j] & i) cnt++;
            sum += min(cnt,n-cnt);
        }
        ret = min(ret,sum);
        return;
    }

    go(here +1);
    coin[here] = ~coin[here];
    go(here +1);
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i =1; i <= n; i++){
        //cout << str << '\n';
        string str;
        int tmp = 1;
        cin >> str;
        for(int j = 0; j < str.size(); j++){
            if(str[j] == 'T') coin[i] |= tmp;
            tmp *= 2;
        }
    }

    go(1);

    cout << ret;

    return 0;
}
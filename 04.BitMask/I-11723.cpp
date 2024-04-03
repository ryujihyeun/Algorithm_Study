#include <bits/stdc++.h>
using namespace std;
int n, x, s, all;
string oper;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= 20; i++) all |= (1<<i);
    for(int i = 0; i < n; i++){
        cin >> oper;
        if(oper == "all") s |= all;
        else if(oper == "empty") s &= 0;
        else cin >> x;
        
        if(oper == "add") s |= (1<<x);
        else if(oper == "remove") s &= ~(1<<x);
        else if(oper == "toggle") s ^= (1<<x);
        else if(oper == "check") cout << ((s & (1<<x)) ? 1:0) << '\n';
    }

    return 0;
}
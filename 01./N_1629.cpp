#include <bits/stdc++.h>
using namespace std;
long long a,b,c;
typedef long long ll;

ll go(ll a, ll b){
    if(b == 1) return a % c;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b >> c;
    cout << go(a,b) << '\n';
    return 0;
}
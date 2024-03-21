#include <bits/stdc++.h>
using namespace std;
int n, ret, p, d;
priority_queue<pair<int,int>> pq;
int check[10000] = {0,};

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p >> d;
        pq.push({p,d});
    }

    for(int i = 0; i < n; i++){
        tie(p,d) = pq.top(); pq.pop();
        //cout << p << ":" << d << '\n';
        for(int j = d; j > 0; j--){
            if(check[j] == 0){
                ret += p;
                check[j] = 1;
                break;
            }
        }
    }

    cout << ret << '\n';

    return 0;
}
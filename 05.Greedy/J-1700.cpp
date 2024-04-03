#include <bits/stdc++.h>
using namespace std;
int n,k,ret,a[101],con[101];
queue<int> q[101];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        cin >> a[i];
        q[a[i]].push(i);
    }
    /*
    for(int i = 0; i < k; i++){
        cout << a[i] << " " << q[a[i]].front() << '\n';
        q[a[i]].pop();
    }
    */

    for(int i = 0; i < k; i++){
        int cur = a[i], idx = -1, cnt = 0;
        for(int c = 0; c < n; c++) cout << con[c] << " ";
        cout << '\n';
        for(int j = 0; j < n; j++){
            if(con[j] == cur) {q[con[j]].pop(); break;}
            else if(!con[j]) {con[j] = cur; break;}
            else{
                cnt++;
                if(cnt == n){
                    if(q[con[j]].empty()) {idx = j; break;}
                    else if(q[con[j]].front() > idx) idx = j;
                }
            }
        }

        if(idx != -1){
            cout << "remove: " << cur << " " << idx << " " << con[idx] << '\n';
            ret++;
            con[idx] = cur;
            if(q[con[idx]].empty()) continue;
            q[con[idx]].pop();
        }
    }


    cout << ret << '\n';

    return 0;
}
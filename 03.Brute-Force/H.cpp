#include <bits/stdc++.h>
using namespace std;
int n,k;
const int MAX = 200000;
int visited[MAX + 4];
int cnt[MAX+4];
int cnt2[MAX+4];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;

    if(n == k){
        cout << 0 << '\n';
        cout << n << '\n';
        return 0;   
    }

    visited[n] = 1;
    cnt[n] = 1;
    cnt2[n] = n;
    queue<int> q;
    q.push(n);

    while(q.size()){
        int now = q.front(); q.pop();
        for(int next: {now+1, now -1, now*2}){
            if(0 <= next && next <= MAX){
                if(!visited[next]){
                    q.push(next);
                    visited[next] = visited[now] + 1;
                    cnt[next] += cnt[now];
                    cnt2[next] = now;
                }
                else if(visited[next] == visited[now]+1){
                    cnt[next] += cnt[now];
                }
            }
        }
    }

    int arr[visited[k]];
    arr[visited[k]-1] = k;
    int idx = k;
    for(int i = visited[k]-1; i > 0; i--){
        idx = cnt2[idx];
        arr[i-1] = idx;
    }

    cout << visited[k] - 1 << '\n';
    for(int i : arr) cout << i << " ";

    return 0;
}
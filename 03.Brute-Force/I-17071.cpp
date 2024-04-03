#include <bits/stdc++.h>
using namespace std;
int n,k;
const int MAX = 1000000;
int visited[MAX + 4], sister[MAX + 4];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;

    if(n == k){
        cout << 0 << '\n';
        return 0;   
    }

    queue<int> q;
    q.push(k);
    sister[k] = 1;
    int speed = 1;

    while(q.size()){
        int now = q.front(); q.pop();
        int next = now + speed;
        if(0 <= next && next <= MAX){
            q.push(next);
            speed++;
            sister[next] += sister[now];
        }
    }

    visited[n] = 1;
    q.push(n);

    while(q.size()){
        int now = q.front(); q.pop();
        for(int next: {now+1, now -1, now*2}){
            if(0 <= next && next <= MAX){
                if(!visited[next]){
                    q.push(next);
                    visited[next] = visited[now] + 1;
                }
                if(sister[next] && sister[next] == visited[now]){
                    cout << sister[next] << '\n';
                }
            }
        }
    }


    cout << visited[k] - 1 << '\n';

    return 0;
}
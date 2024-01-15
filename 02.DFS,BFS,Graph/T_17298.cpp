#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000001];
int nge[1000001];
stack<int> s;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    memset(nge, -1, sizeof(nge));
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        while(s.size() && a[s.top()] < a[i]){
            nge[s.top()] = a[i]; s.pop();
            for(int i = 1; i <= n; i++) cout << nge[i] << " ";
            cout << '\n';
        }
        s.push(i);
    }
    for(int i = 1; i <= n; i++) cout << nge[i] << " ";
    return 0;
}
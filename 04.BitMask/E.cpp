#include <bits/stdc++.h>
using namespace std;
int n,l,ret;
int a[100][100], b[100][100];

void solve(int c[100][100]){
    for(int i = 0; i < n; i++){
        int cnt = 1, j;
        for(j = 0; j < n-1; j++){
            if(c[i][j] == c[i][j+1]) cnt++;
            else if(c[i][j] + 1 == c[i][j+1] && cnt >= l) cnt = 1;
            else if(c[i][j] - 1 == c[i][j+1] && cnt >= 0) cnt = 1-l;
            else break;
        }
        if(j == n-1 && cnt >= 0) ret++;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }

    solve(a); solve(b);
    cout << ret;

    return 0;
}
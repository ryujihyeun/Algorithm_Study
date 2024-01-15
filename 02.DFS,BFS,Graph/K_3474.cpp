#include <bits/stdc++.h>
using namespace std;
int t,n;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        int ret5 = 0;
        for(int j = 5; j <= n; j *=5){
            ret5 += n/j;
        }
        cout << ret5 << "\n";
    }

    return 0;
}
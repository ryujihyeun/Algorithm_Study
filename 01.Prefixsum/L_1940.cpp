#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a(15000);
int ret = 0;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for(int i =0; i < n; i++){
        cin >> a[i];
    }

    int sum;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            sum = a[i] + a[j];
            if(sum == m) {
                ret++;
                break;
            }
        }
    }

    cout << ret << '\n';
    return 0;
}
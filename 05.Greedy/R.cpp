#include <bits/stdc++.h>
using namespace std;
int n,ret,a[11];
vector<int> v[4] = {
                    {2,4,6,8,10,12,14,16,18,20,30,32,34,36,38,40},
                    {2,4,6,8,10,12,14,16,18,20,30,28,27,26,25,30,35,40},
                    {2,4,6,8,10,12,14,16,18,20,22,24,25,30,35,40},
                    {2,4,6,8,10,13,16,19,25,30,35,40}
                    };
vector<int> arr[4];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    for(int i = 0; i < 10; i++){
        cin >> a[i];
    }

    
    

    cout << ret << '\n';

    return 0;
}
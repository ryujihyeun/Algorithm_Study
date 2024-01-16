#include <bits/stdc++.h>
using namespace std;
int n;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    int num = 2400, i = 0;
    while(true){
        if(to_string(num).find("2400") != string::npos) i++;
        if(i == n) break;
        num++;
    }

    cout << num << '\n';

    return 0;
}
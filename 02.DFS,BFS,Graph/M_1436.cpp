#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> num;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    int i = 0;
    int num = 665;
    while(i != n){
        num++;
        if(to_string(num).find("666") != string::npos) i++;
    }
    cout << num;

    return 0;
}
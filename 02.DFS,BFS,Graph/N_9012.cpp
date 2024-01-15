#include <bits/stdc++.h>
using namespace std;
int t;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    for(int i = 0; i < t; i++){
        string tcase;
        vector<char> vps;
        vps.push_back('x');
        cin >> tcase;
        for(auto it: tcase){
            char a = vps.back();
            if(a == '(' && it == ')') vps.pop_back(); 
            else vps.push_back(it);
        }
        if(vps.back() == 'x') cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
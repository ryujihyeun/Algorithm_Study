#include <bits/stdc++.h>
using namespace std;
string str, bomb, ret;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> str;
    cin >> bomb;

    for(char a : str){
        ret += a;
        if(ret.size() >= bomb.size() && ret.substr(ret.size()-bomb.size(), bomb.size()) == bomb){
            ret.erase(ret.end()-bomb.size(), ret.end());
        }
    }
    
    if(ret == "") ret = "FRULA";
    cout << ret << '\n';

    return 0;
}
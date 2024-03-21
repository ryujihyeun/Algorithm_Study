#include <bits/stdc++.h>
using namespace std;
string a,b,ret,tmp;
int carry = 0, sum = 0;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;

    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int minsize = min(a.size(),b.size());
    
    for(int i = 0; i < minsize; i++){
        sum = stoi(a.substr(i,1)) + stoi(b.substr(i,1)) + carry;
        if(sum >= 10){
            sum -= 10;
            ret.push_back(sum + '0'); carry = 1;
        }
        else{
            ret.push_back(sum + '0'); carry = 0;
        }
    }

    if(a.size() > b.size()) tmp = a.substr(minsize);
    else tmp = b.substr(minsize);

    for(int i = 0; i < tmp.size(); i++){
        sum = stoi(tmp.substr(i,1)) + carry;
        if(sum >= 10){
            sum -= 10;
            ret.push_back(sum + '0'); carry = 1;
        }
        else {ret.push_back(sum + '0'); carry = 0;}
    }

    if(carry == 1) ret.push_back('1');

    reverse(ret.begin(), ret.end());
    cout << ret;
    return 0;
}
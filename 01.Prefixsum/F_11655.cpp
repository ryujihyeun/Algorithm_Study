#include <bits/stdc++.h>
using namespace std;
string s1;
string ret;

int main(){
    getline(cin, s1);
    ret.clear();

    for(int it: s1){
        if('A' <= it && it <= 'Z'){
            if(it > 'Z' - 13){
                ret.push_back('A' + 12 + it - 'Z');
            }
            else ret.push_back(it + 13); 
        }

        else if('a' <= it && it <= 'z'){
            if(it > 'z' - 13){
                ret.push_back('a' + 12 + it - 'z');
            }
            else ret.push_back(it + 13);
        }
        else ret.push_back(it);
    }
    cout << ret ;
    return 0;
}
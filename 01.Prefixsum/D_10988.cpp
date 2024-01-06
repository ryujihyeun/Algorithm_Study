#include <bits/stdc++.h>
using namespace std;
string word;

int main(){
    cin >> word;
    // check length 1
    int w_length = word.length();
    if(w_length == 1) cout << "1" << '\n';

    else{
        string prev = word;
        string suff = word;

        // 문자열 반으로 나누기
        int tmp = w_length/2;
        if(w_length % 2 == 1) tmp++;

        prev = prev.substr(0, w_length/2);
        suff = suff.substr(tmp);
        reverse(suff.begin(), suff.end());

        if(prev.compare(suff) == 0) cout << "1";
        else cout << "0";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<int> alpha(26);
string word;

int main(){
    //입력
    cin >> word;
    int tmp = 0;
    for(auto it : word){
        //cout << int(it) << ' ';
        tmp = int(it) -97;
        alpha[tmp]++;
    }
    // print
    for(auto it: alpha){
        cout << it << " ";
    }
    return 0;
}
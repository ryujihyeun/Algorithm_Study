#include <bits/stdc++.h>
using namespace std;
string str;
map<char, int> alphabet;


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> str;
    for(char it: str){
        if(alphabet.find(it) == alphabet.end()) alphabet.insert({it,1});
        else alphabet[it]++;
    }

    string prev;
    string middle = "";
    int npos = 0;
    for(auto it : alphabet){
        if(it.second % 2 == 1){
            npos++; 
            middle = it.first;
        } 
        if(npos > 1){
            cout << "I'm Sorry Hansoo" << '\n';
            return 0;
        }
        for(int i = 0; i < it.second/2; i++){
            prev.push_back(it.first);
        }
    }
    string suff = prev;
    reverse(suff.begin(), suff.end());
    cout << prev << middle << suff;
    
    return 0;
}
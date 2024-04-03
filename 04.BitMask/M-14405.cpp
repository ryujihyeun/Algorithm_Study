#include <bits/stdc++.h>
using namespace std;
string str;
vector<string> pikachu = {"pi","ka","chu"};

bool find(){
    int pos = -1, length = -1;
    string tmp = str;
    for(int i = 0; i < str.size();){
        for(string it: pikachu){
            //cout << it << '\n';
            //cout << tmp.find(it) << '\n';
            if(tmp.find(it) == 0){
                length = it.size();
                pos = 0;
            }
        }
        //cout << "pos: " << pos << " length: " << length << '\n';
        if(pos != 0 || length == -1) return false;
        tmp.erase(0,length);
        i += length; 
        //cout << i << ":" << tmp << "\n";
        pos = length = -1;
    }
    return true;
}


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> str;

    if(find()) cout << "YES";
    else cout << "NO";

    return 0;
}
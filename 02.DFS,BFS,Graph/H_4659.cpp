#include <bits/stdc++.h>
using namespace std;
string pw;
vector<char> vow = {'a','e','i','o','u'};

void check(string str){
    int flag1 = 0, flag2 = 0, flag3 = 0;
    for(int i = 0; i < str.size(); i++){
        if(find(vow.begin(), vow.end(), str[i]) != vow.end()) flag1 = 1;
        if(i >= 1 && str[i] == str[i-1]){
            if(str[i] == 'e' || str[i] == 'o') flag2 = 0;
            else flag2 = 1;
        }
        if(i > 1){
            if(find(vow.begin(), vow.end(), str[i]) != vow.end()){
                if(find(vow.begin(), vow.end(), str[i-1]) != vow.end()){
                    if(find(vow.begin(), vow.end(), str[i-2]) != vow.end()) flag3 = 1;
                }
            }
            else{
                if(find(vow.begin(), vow.end(), str[i-1]) == vow.end()){
                    if(find(vow.begin(), vow.end(), str[i-2]) == vow.end()) flag3 =1;
                }
            }
        }
    }

    if(flag1 == 1 && flag2 == 0 && flag3 == 0) cout << "<" << str << "> is acceptable.\n";
    else cout << "<" << str << "> is not acceptable.\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> pw;
    while (pw != "end"){
        check(pw);
        cin >> pw;
    }
    
    return 0;
}
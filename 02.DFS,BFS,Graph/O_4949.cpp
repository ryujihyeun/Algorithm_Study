#include <bits/stdc++.h>
using namespace std;
vector<int> check = {'[',']','(',')'};

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    vector<char> bal;
    bal.push_back('x');

    while(true){
        string s;
        getline(cin, s); 
        if(s == ".") break;

        for(auto it : s){
            if(it == '.'){
                if(bal.back() == 'x') cout << "yes\n";
                else cout << "no\n";
                bal.clear(); bal.push_back('x');
                break;
            }
            if(find(check.begin(),check.end(),it) != check.end()){
                char a = bal.back();
                if(a == '(' && it == ')') bal.pop_back();
                else if(a == '[' && it == ']') bal.pop_back();
                else bal.push_back(it);
            }
        }
    }

    return 0;
}
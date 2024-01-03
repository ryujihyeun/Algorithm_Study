#include <bits/stdc++.h>
using namespace std;
int n,m;
map<int,string> poks_num;
map<string,int> poks_str;
vector<string> problems;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    string pok;
    string q;
    int num;
    
    for(int i = 1; i <= n; i++){
        cin >> pok;
        poks_num.insert({i,pok});
        poks_str.insert({pok,i});
        pok.clear();
    }   

    for(int i = 0; i < m; i++){
        cin >> q;
        if(q[0] <= 57){
            num = stoi(q);
            cout << poks_num.find(num)->second << '\n';
        }
        else{
            cout << poks_str.find(q)->second << '\n';
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int test_num, num;
map<string, int> clothes;
string type, name;

int sol(int n){
    string tmp;
    int ret = 1;
    
    for(int i = 0; i < n; i++){
        cin >> name >> type;
        if(clothes.find(type) == clothes.end()) clothes.insert({type,1});
        else clothes[type] +=1;
        type.clear();
    }
    
    for(auto it: clothes){
        ret *= (it.second + 1);
    }
    ret -= 1;
    cout << ret << "\n";
    // initialized
    tmp.clear();
    clothes.clear();
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> test_num;

    for(int i = 0; i < test_num; i++){
        cin >> num;
        sol(num);
    }

    return 0;
}
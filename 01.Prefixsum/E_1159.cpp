#include <bits/stdc++.h>
using namespace std;
int N = 0;
vector<int> alphabet(26);
int ret = 0;

int main(){
    string name;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> name;
        alphabet[name[0] - 'a']++;
    }

    for(int i = 0; i < 26; i++){
        if(alphabet[i] >= 5){
            ret++;
            cout << char(i+'a');
        }
    }

    if(ret == 0) cout << "PREDAJA";

    return 0;
}
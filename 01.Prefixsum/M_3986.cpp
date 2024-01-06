#include <bits/stdc++.h>
using namespace std;
int n;
int ret = 0;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    char good('X');
    vector<char> v{good};

    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;

        if(tmp.size() % 2 == 1) continue;
        else{
            for(char it : tmp){
                char cur = v.back();
                if(cur != it) v.push_back(it);
                else v.pop_back();     
            }
            if(v.back() == good) ret++;
            v.clear();
            v.push_back(good);
        }
    }

    cout << ret << '\n';
    return 0;
}
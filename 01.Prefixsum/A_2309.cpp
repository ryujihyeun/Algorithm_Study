#include <bits/stdc++.h>
using namespace std;  
vector<int> v(9);
vector<int> ret;

int main(){
    // 변수 입력
    for(int i = 0; i < 9; i++){
        cin >> v[i] ;
    }
    // 정렬
    sort(v.begin(), v.end());
    // 조합
    int tmp = 0;
    do{
        for(auto it = 0; it < 7; it++){
            ret.push_back(v[it]);
            tmp += v[it];
        }
        if(tmp == 100) break;
        tmp = 0;
        ret.clear();
    } while(next_permutation(v.begin(), v.end()));

    for(auto it : ret){
        cout << it << '\n';
    }
    return 0;
}
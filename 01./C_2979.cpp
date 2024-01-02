#include <bits/stdc++.h>
using namespace std;
int A,B,C;
vector<int> fee(100);
int ret = 0;

int main(){
    cin >> A >> B >> C;
    int a,d = 0;
    for(int i = 0; i <3; i++){
        cin >> a >> d ;
        for(int j = a; j < d; j++){
            fee[j]++;
        }
    }

    for(auto it : fee){
        if(it){
            if(it == 1) ret += A;
            if(it == 2) ret += 2*B;
            if(it == 3) ret += 3*C;
        }
    }

    cout << ret;
    return 0;
}
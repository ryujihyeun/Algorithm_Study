#include <bits/stdc++.h>
using namespace std;
int n,t;
string p,arr;

void reversearr(){
    if(arr.find(",") == string::npos) return;
    string ret = "[";
    int pos = arr.size()-2;
    for(int i = arr.size(); i >= 0; i--){
        if(arr[i] == ','){
            ret += arr.substr(i+1,pos-i) + ',';
            pos = i-1;
        }
        if(arr[i] == '['){
            ret += arr.substr(1,pos) + ']';
        }
    }
    arr = ret;
    return;
}

int main(){
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> p >> n >> arr;
        int rev = 0, del = 0, m = n, flag = 0;
        for(int j = 0; j < n; j++) del |= (1<<j);
        for(char it : p){
            if(it == 'R') rev = ~rev;
            if(it == 'D' && rev == 0){
                if(del == 0) flag = 1;
                int idx = (del & -del)-1;
                del &= ~(1<<idx);
            }
            if(it == 'D' && rev != 0){
                if(del == 0) flag = 1;
                del &= ~(1<<(m-1));
                m--;
            }
        }
        // print error
        if(flag == 1) {cout << "error" << '\n'; continue;}
        // remove numbers
        int check = 0;
        for(int j = 0; j < n; j++){
            if(del & (1<<j)) {check = 1; continue;}
            int point = arr.find(",");
            if(arr.find(",") == string::npos) point = 1;
            if(check == 0) arr.erase(1, point);
            if(check == 1) {
                point = arr.rfind(",");
                arr.erase(point, arr.size()-point-1); 
            }
        }
        // reverse arr
        if(rev != 0) reversearr(); 
        cout << arr;
        cout << '\n';
    }

    return 0;
}
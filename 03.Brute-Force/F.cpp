#include <bits/stdc++.h>
using namespace std;
int n, ret = -100000000;
vector<int> num;
vector<char> op;

int val(int a, int b, char c){
    if(c == '-') return a-b;
    if(c == '+') return a+b;
    if(c == '*') return a*b;
    return 0;
}

void go(int idx, int sum){
    //cout << "idx: " << idx << " sum: " << sum << '\n';
    if(idx == num.size() - 1){
        //cout << "ret idx: " << idx << " sum: " << sum << '\n';
        ret = max(ret, sum);
        return;
    }
    go(idx+1, val(sum, num[idx+1],op[idx]));
    if(idx + 2 <= num.size() -1){
        int tmp = val(num[idx+1], num[idx+2], op[idx+1]);
        go(idx+2, val(sum, tmp , op[idx]));
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++){
        char tmp;
        cin >> tmp;
        if(i%2 == 1) num.push_back(tmp - '0');
        if(i%2 == 0) op.push_back(tmp);
    }

    go(0, num[0]);

    cout << ret << '\n';

    return 0;
}
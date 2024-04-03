#include <bits/stdc++.h>
using namespace std;
int n, ret;
deque<int> sticks;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    sticks.push_back(64);
    int flag = 0;
    if(n == 64){
        cout << 1;
        return 0;
    }
    while(true){
        sort(sticks.begin(),sticks.end());
        int sstick = sticks.front(); sticks.pop_front();
        if(sstick/2 <= n) sticks.push_back(sstick/2);
        sticks.push_back(sstick/2);

        for(int i = 0; i < (1<<sticks.size()); i++){
            int sum = 0;
            ret = 0;
            //cout << "val: " ;
            for(int j = 0; j < sticks.size(); j++){
                if(i & (1<<j)){
                    //cout << sticks[j] << " ";
                    sum += sticks[j]; ret++;
                }
            }
            //cout << "sum: " << sum << "\n";
            if(sum == n){
                flag = 1;
                break;
            }
        }
        if(flag == 1) break;
    }

    cout << ret;

    return 0;
}
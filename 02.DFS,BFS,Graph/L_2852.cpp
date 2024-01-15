#include <bits/stdc++.h>
using namespace std;
int n, team, score_1 = 0, score_2 = 0;
vector<int> total(3);

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    int prev = 0;
    int prev_t = 0;
    for(int i = 0; i < n; i++){
        string time;
        cin >> team >> time;
        string min = time.substr(0,2);
        string sec = time.substr(3,2);

        if(team == 1) score_1++;
        else score_2++;
        int cur = stoi(min) * 60 + stoi(sec);
        total[prev_t] += cur - prev;
        
        if(score_1 == score_2){
            prev = 0; prev_t = 0;
        }
        else{
            if(score_1 > score_2) prev_t = 1;
            else prev_t = 2;
            prev = cur;
        }
    }
    total[prev_t] += 48*60 - prev;
    string m1="", s1="", m2="", s2="";
    if(total[1]/60 < 10) m1 = '0';
    if(total[1]%60 < 10) s1 = '0';
    if(total[2]/60 < 10) m2 = '0';
    if(total[2]%60 < 10) s2 = '0';

    cout << m1 <<total[1]/60 << ":" << s1 << total[1]%60 << "\n";
    cout << m2 <<total[2]/60 << ":" << s2 << total[2]%60 << "\n";

    return 0;
}
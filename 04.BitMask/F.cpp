#include <bits/stdc++.h>
using namespace std;
int n,k,ret,alpha = 0, mink=5, maxalpha;
string anta = "antatica", str;
int words[50] = {0,};

int count(int m){
    int i;
    for(i = 0; m!=0;i++) m&=(m-1);
    return i;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    for(auto it : anta){
        alpha |= (1<<(it-'a'));
    }
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> str;
        for(char it : str){
            if(~alpha & (1<<(it-'a'))) words[i] |= (1<<(it-'a'));
        }
        maxalpha |= words[i];
    }
    /*
    for(int i = 0; i < n; i ++){
        cout << bitset<26>(words[i]) << " ";
        cout << count(words[i]) << "\n";
    }
    */

    if(k < mink) {cout << ret << '\n'; return 0;}

    int num = count(maxalpha);
    int tmp = maxalpha;
    int idx[num], iidx=0;
    for(int i = 0; i < 26; i++){
        if(tmp & 1) {idx[iidx] = i; iidx++;}
        tmp = tmp >> 1;
    }

    for(int i = 0; i < (1<<num); i++){
        vector<int> v;
        for(int j = 0; j < num; j++){
            if(i & (1<<j)) v.push_back(j);
            if(v.size() > k-mink) break;
        }

        if(v.size() <= k-mink){
            int key = 0, tret = n;
            for(int it : v) key |= (1<<idx[it]);
            key |= alpha;
            for(int j = 0; j < n; j++){
                if((words[j] | key) != key) tret--;
            }
            ret = max(ret,tret);
        }
    }

    cout << ret << '\n';

    return 0;
}
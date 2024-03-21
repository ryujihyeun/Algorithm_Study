#include <bits/stdc++.h>
using namespace std;
int n, ret = 1000000000;
vector<int> mutal;

void print(vector<int> v){
	for(int i : v) cout << i << " ";
	cout << '\n';
}

void go(vector<int> a, int num){
    //cout << "[start num]: " << num << '\n';
    if(num >= ret) return;
    vector<int> attack;
    if(a.size() == 3) attack = {1,3,9};
    if(a.size() == 2) attack = {3,9};
    if(a.size() == 1) attack = {9};
    do{
        // make attack vector
        vector<int> damged = a;
        // start attack
        num++;
        if(num >= ret) return;
        for(int i = 0; i < a.size(); i++){
            damged[i] -= attack[i];
        }
        // remove dead mutal
        vector<int> removedmutal;
        for(auto it: damged) if(it > 0) removedmutal.push_back(it);

        if(removedmutal.size() == 0){
            ret = min(ret, num);
            return;
        }

        go(removedmutal, num);
        num--;
    } while (next_permutation(attack.begin(),attack.end()));
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        mutal.push_back(tmp);
    }

    int flag = 1;
    int num = 0;
    int attack[3] = {9,3,1};
    
    while(true){
        sort(mutal.begin(), mutal.end());
        reverse(mutal.begin(), mutal.end());
        for(int i = 0; i < mutal.size(); i++){
            if(mutal[i] - 13 <= 0){
                flag = 0;
                break;
            }
        }
        if(flag == 0) break;
        for(int i = 0; i < mutal.size(); i++){
            mutal[i] -= attack[i];
        }
        num++;
    }
    
    //print(mutal);
    go(mutal,num);

    cout << ret <<'\n';
    return 0;
}
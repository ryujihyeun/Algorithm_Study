#include <bits/stdc++.h>
using namespace std;
int n,c;
map<int,int> m1; // key, count
map<int,int> m2; // key, first i

bool cmp(const pair<int,int>& a, const pair<int,int>& b) {
	if (a.second == b.second) return m2[a.first] < m2[b.first];
	return a.second > b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> c;

    for(int i = 0; i < n; i++){
        int key;
        cin >> key;
        if(m1.count(key) == 0){
            m1.insert({key,1});
            m2.insert({key,i});
        }
        else{
            map<int,int>::iterator it = m1.find(key);
            it->second += 1; 
        }
    }

    vector<pair<int,int>> vec(m1.begin(), m1.end());
    sort(vec.begin(), vec.end(), cmp);

    for(auto it: vec){
        for(int i= 0; i < it.second; i++){
            cout << it.first << " ";
        }
    }

    return 0;
}
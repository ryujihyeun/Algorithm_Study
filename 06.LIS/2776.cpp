#include <bits/stdc++.h>
using namespace std;
int n,m,t,tmp;

int check(int find, vector<int> &v){
    int l = 0, h = v.size()-1;
    while(l<=h){
        int mid = (l+h)/2;
        if(v[mid] > find) h = mid -1;
        else if(v[mid] < find) l = mid +1;
        else return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for(int i = 0; i < t; i++){
        vector<int> v1;
        cin >> n;
        for(int j = 0; j < n; j++){
            cin >> tmp;
            v1.push_back(tmp);
        }
        sort(v1.begin(),v1.end());

        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> tmp;
            cout << check(tmp, v1) << '\n';
        }
    }
    

    return 0;
}
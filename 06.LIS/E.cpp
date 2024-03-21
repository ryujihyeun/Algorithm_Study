#include <bits/stdc++.h>
using namespace std;
int anum,bnum,ret,tmp;
vector<int> a,b;

int check(int tmp, vector<int> &v){
    int lo = 0, hi = v.size()-1;
    while(lo <= hi){
        int mid = (lo + hi)/2;
        if(v[mid] > tmp) hi = mid-1;
        else if(v[mid] < tmp) lo = mid+1;
        else return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> anum >> bnum;
    for(int i = 0; i < anum; i++){
        cin >> tmp;
        a.push_back(tmp);
    }
    for(int i = 0; i < bnum; i++){
        cin >> tmp;
        b.push_back(tmp);
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int bcnt = bnum, acnt = anum;
    for(int i = 0; i < anum; i++){
        bcnt -= check(a[i],b);
    }
    for(int i = 0; i < bnum; i++){
        acnt -= check(b[i],a);
    }
    
    ret = bcnt + acnt;

    cout << ret << '\n';

    return 0;
}
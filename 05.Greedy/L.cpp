#include <bits/stdc++.h>
using namespace std;
int n,ret = 987654321, syn[21][21];

int go(vector<int> &link, vector<int> &start){
    pair<int,int> sum;
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < n/2; j++){
            if(i == j) continue;
            sum.first += syn[link[i]][link[j]];
            sum.second += syn[start[i]][start[j]];
        }
    }
    return abs(sum.first - sum.second);
}


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> syn[i][j];
        }
    }

    for(int i = 0; i < (1<<n); i++){
        if(__builtin_popcount(i) != n / 2) continue;
        vector<int> start, link;
        for(int j = 0; j < n; j++){
			if(i & (1 << j))start.push_back(j);
			else link.push_back(j);
		}
		ret = min(ret, go(start, link));
    }

    cout << ret << '\n';

    return 0;
}
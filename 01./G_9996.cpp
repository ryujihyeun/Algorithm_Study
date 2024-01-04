#include <bits/stdc++.h>
using namespace std;
int n;
string pattern, tmp;
vector<string> str;


int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    cin >> pattern;

    int pos = pattern.find("*");
    string start = pattern.substr(0,pos);
    string end = pattern.substr(pos + 1);

    for(int i = 0; i < n; i++){
        cin >> tmp;

        if(start.size() + end.size() > tmp.size()){
            cout << "NE\n";
        }
        else{
            if(start == tmp.substr(0,start.size()) && end == tmp.substr(tmp.size() - end.size())) cout << "DA\n";
            else cout << "NE\n";
        }
    }

    return 0;
}
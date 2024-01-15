#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> ret;

bool cmp(const string& a, const string& b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

void find(string input){
    string token = "";
    int start = -1;
    for(int i = 0; i < input.size(); i++){
        if(input[i] <= '9'){
            if(start == -1) start = i;
            if((i < input.size()-1 && input[i + 1] > '9') || i == input.size()-1){
                if(i == start) token = input.substr(start, 1);
                else token = input.substr(start, i - start + 1);
                // eliminate '0'
                if(token.size() > 1 && token.find('0') == 0){
                    int idx = -1;
                    for(int i = 0; i < token.size(); i++){
                        if(token[i] != '0') break;
                        idx++;
                    }
                    if(idx == token.size()-1) token = token.substr(idx);
                    else token = token.substr(idx+1);
                }
                ret.push_back(token);
                start = -1;
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        find(word);
    }
    sort(ret.begin(),ret.end(),cmp);

    for(auto it: ret){
        cout << it << '\n';
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int h,w;
int sky[100][100];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> h >> w;
    int check = 0;
    int time = 0;
    for(int i = 0; i < h; i++){
        string tmp;
        cin >> tmp;
        for(int j =0; j < w; j++){
            if(check == 0){
                if(tmp[j] == 'c') {
                    check++;
                    sky[i][j] = 0;
                    time = 1;
                    continue;
                }
                else sky[i][j] = -1;
            }
            else if(tmp[j] == 'c'){
                sky[i][j] = 0;
                time = 1;
            }
            else {
                sky[i][j] = time;
                time++;
            }
        }
        check = 0;
        time = 0;
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << sky[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
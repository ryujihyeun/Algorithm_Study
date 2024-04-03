#include <bits/stdc++.h>
using namespace std;
int n,k,l,ret,board[101][101];
queue<pair<int,char>> bam;
queue<pair<int,int>> snake;
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

void print(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i = 0; i < k; i++){
        int a,b;
        cin >> a >> b;
        board[a][b] = 1;
    }
    cin >> l;
    for(int i = 0; i < l; i++){
        int sec;
        char dir;
        cin >> sec >> dir;
        bam.push({sec,dir});
    }

    board[1][1] = 2;
    snake.push({1,1});
    int idx = 1;
    while(1){
        ret++;
        //cout << "ret: " << ret ;
        //cout << " idx: " << idx << '\n';

        int cy,cx,ny,nx;
        tie(cy,cx) = snake.back();
        ny = cy + dy[idx];
        nx = cx + dx[idx];
        
        // 벽이나 몸에 부딪히면 종료
        if(board[ny][nx] == 2 || ny < 1 || ny >= n+1 || nx < 1 || nx >= n+1) break;
        // 뱀 이동 및 보드 정보 입력
        //cout << ny << ":" << nx << '\n';
        snake.push({ny,nx});

        if(board[ny][nx] == 1){
            board[ny][nx] = 2; // 머리 이동
        }
        else{
            board[ny][nx] = 2; // 머리 이동
            board[snake.front().first][snake.front().second] = 0; // 꼬리 이동
            snake.pop(); // 꼬리 이동
        } 

        // 방향 전환
        if(bam.size()!=0 && ret == bam.front().first){
            //cout << "change dir\n";
            if(bam.front().second == 'L') idx = (idx+1)%4;
            else idx = (idx+3)%4;
            bam.pop();
        }

    }

    cout << ret << '\n';

    return 0;
}
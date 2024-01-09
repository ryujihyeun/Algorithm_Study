#include <bits/stdc++.h>
using namespace std;
int n,m,j,ret;
int a[11];

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    cin >> j;
    int m_coor = 1;
    for(int i = 0; i < j; i++){
        int coor;
        cin >> coor;
        if(m_coor <= coor && coor <= m_coor + (m-1))  continue; //cout << "not move\n";
        else{
            //cout << "m_coor, coor, ret: " << m_coor << coor << ret <<'\n';
            int prev = m_coor;
            int end = m_coor + (m-1);
            if(coor < m_coor) m_coor = coor;
            else m_coor = m_coor + abs(coor - end);
            ret += abs(prev - m_coor);
            //cout << "m_coor,ret " << m_coor << ret << '\n';
        }
    }

    cout << ret <<'\n';

    return 0;
}
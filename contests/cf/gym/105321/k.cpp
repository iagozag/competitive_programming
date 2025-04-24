#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int n,m;
vector<vector<int>> v;

void foundt(int a, int b){
    for(int j = b-1; j <= b+1; j++) v[a-4][j] = 0;
    for(int i = a-3; i <= a; i++) v[i][b] = 0;
}

void founda(int a, int b){
    for(int i = a-4; i <= a; i++) v[i][b] = 0;
    for(int i = a-4; i <= a; i++) v[i][b+2] = 0;
    v[a-4][b+1] = v[a-2][b+1] = 0;
}

void foundp(int a, int b){
    for(int i = a-4; i <= a; i++) v[i][b] = 0;
    for(int i = a-4; i <= a-2; i++) v[i][b+2] = 0;
    v[a-4][b+1] = v[a-2][b+1] = 0;
}

void printt(){
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cout << v[i][j] << " \n"[j==m-1];
}

int32_t main() { _

    cin >> n >> m;
    v = vector<vector<int>>(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++) v[i][j] = (s[j] == '#');
    }

    vector<int> ans(3);
    for(int i = n-1; i >= 4; i--) for(int j = 0; j < m; j++) if(v[i][j]){
        if(!v[i-2][j+1]) ans[0]++, foundt(i, j);
        else if(!v[i][j+2]) ans[2]++, foundp(i, j);
        else ans[1]++, founda(i, j);

        //cout << endl;
        //for(int l = 0; l < 3; l++) cout << ans[l] << endl;
        //cout << endl;

        //printt();
    }
    
    for(int i = 0; i < 3; i++) cout << ans[i] << ' ';
    cout << endl;
}
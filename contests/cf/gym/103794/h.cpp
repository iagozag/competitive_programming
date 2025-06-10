#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define ff first 
#define ss second
#define sz(x) (int)x.size()
#define int ll

int n, m;

vector<pair<int, int>> moves = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};

bool val(int i,int j){
    return i >= 0 and i < n and j >= 0 and j < m;
}

int32_t main() { _
    cin >> n >> m;
    int v[n][m];
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> v[i][j];
    int a, b; cin >> a >> b; --a, --b;

    if(n == 1 and m == 1)
{
    cout << v[0][0] << endl;
    return 0;
}
    for(int k = 0; k < n+m; k++){
        int qnt = 0;
        for(auto [x, y]: moves){
            x += a, y += b;
            qnt += val(x, y);
        }

        int toys = v[a][b]/qnt;
        v[a][b] -= toys*qnt;

        int ma = 0;
        for(auto [x, y]: moves){
            x += a, y += b;
            if(!val(x, y)) continue;
            v[x][y] += toys;
            ma = max(ma, v[x][y]);
        }

        for(auto [x, y]: moves){
            x += a, y += b;
            if(!val(x, y)) continue;
            if(v[x][y] == ma){ a = x, b = y; break; }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) ans = max(ans, v[i][j]);
    cout << ans << endl;
}
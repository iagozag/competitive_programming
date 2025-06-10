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

int32_t main() { _
    int n, m, k, q; cin >> n >> m >> k >> q;
    vector<tuple<int, int, int>> v(q);
    for(auto& [a, b, c]: v) cin >> a >> b >> c, --a, --b;
    
    int l = 0, r = 1e9+1, ans = 1e9+1;
    while(l <= r){
        int mid = l+(r-l)/2;

        int mat[n][m]; memset(mat, 0, sizeof mat);
        for(auto [a, b, c]: v) if(c <= mid) mat[a][b] = 1;

        int pref[n+1][m+1]; memset(pref, 0, sizeof pref);
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
            pref[i][j] = mat[i][j]+(i ? pref[i-1][j] : 0)+(j ? pref[i][j-1] : 0)-(i and j ? pref[i-1][j-1] : 0);
        }

        bool can = 0;
        for(int i = k-1; i < n; i++) for(int j = k-1; j < m; j++) 
            if(pref[i][j]-(i-k >= 0 ? pref[i-k][j] : 0)-(j-k >= 0 ? pref[i][j-k] : 0)+(i-k >= 0 and j-k >= 0 ? pref[i-k][j-k] : 0) == k*k){
                can = 1;
                break;
            }
    
        if(can) ans = mid, r = mid-1;
        else l = mid+1;
    }


    cout << (ans == 1e9+1 ? -1 : ans) << endl;
}
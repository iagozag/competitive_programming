#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, k;
vector<int> v, memo;

void solve(){
    cin >> n >> k;
    v = vector<int>(n+1); memo = vector<int>(n+1, -1);
    int m; cin >> m; 
    for(int i = 0; i < m; i++){ int x; cin >> x; v[x] = -1; }
    cin >> m; 
    for(int i = 0; i < m; i++){ int x; cin >> x; v[x] = 1; }

    memo[0] = 1;
    for(int i = 0; i < n; i++){
        if(v[i] == -1) memo[i] = -1;
        if(i+1 <= n) memo[i+1] = max(memo[i+1], (int)(memo[i] == 1 or v[i] == 1));
        if(i+k <= n) memo[i+k] = max(memo[i+k], (int)(memo[i] == 1 or v[i] == 1));
    }
    
    cout << (memo[n] == 1 ? "Sim" : "Nao") << endl;

	exit(0);
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}


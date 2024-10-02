#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

string s; int n, d;
vector<vector<vector<ll>>> memo;

void sm(ll& a, ll b){
    a %= MOD, a += MOD, a += b, a %= MOD;
}

ll dp(int i, int sum, int ma){
    ll& p = memo[i][sum][ma];
    if(p != -1) return p;
    if(i == n) return p = (sum == 0);

    p = 0;
    if(!ma)
        for(int j = 0; j <= 9; j++) sm(p, dp(i+1, (sum+j)%d, 0));
    else
        for(int j = 0; j <= (s[i]-'0'); j++) sm(p, dp(i+1, (sum+j)%d, j == (s[i]-'0')));

    return p;
}

void solve(){
    cin >> s >> d; n = s.size();
    memo = vector<vector<vector<ll>>>(n+1, vector<vector<ll>>(d, vector<ll>(2, -1)));

    ll ans = 0;
    for(int i = 0; i <= (s[0]-'0'); i++) sm(ans, dp(1, i%d, i == (s[0]-'0')));
    ans--, sm(ans, MOD);
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

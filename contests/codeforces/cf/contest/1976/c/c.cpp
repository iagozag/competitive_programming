#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a.size())
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    ll n, m, sum; cin >> n >> m; sum = n+m+1;
    vector<pll> a(sum);
    rep(i, 0, sum) cin >> a[i].ff;
    rep(i, 0, sum) cin >> a[i].ss;

    vl ans(sum); vi pos(sum); int c1 = 0, c2 = 0; ll cur = 0;
    rep(i, 0, sum-1){
        if(c2 == m) cur += a[i].ff;
        else if(c1 == n) cur += a[i].ss, pos[i] = 1;
        else if(a[i].ff > a[i].ss) cur += a[i].ff, c1++;
        else cur += a[i].ss, c2++, pos[i] = 1;
    }
    ans[sum-1] = cur, pos[sum-1] = -1;

    int pref[2][sum]; memset(pref, -1, sizeof pref);
    repr(i, sum-1, 1){
        if(pos[i] == 0 and a[i].ss > a[i].ff) pref[1][i-1] = i;
        else if(pos[i] == 1 and a[i].ss < a[i].ff) pref[0][i-1] = i;
        else pref[0][i-1] = pref[0][i], pref[1][i-1] = pref[1][i];
    }

    repr(i, sum-2, 0){
        int p = pos[i];
        ans[i] = cur-(!p ? a[i].ff : a[i].ss);
        if(pref[p][i] == -1) ans[i] += (!p ? a[sum-1].ff : a[sum-1].ss);
        else ans[i] += abs(a[pref[p][i]].ff-a[pref[p][i]].ss)+(p ? a[sum-1].ff : a[sum-1].ss);
    }

    rep(i, 0, sum) cout << ans[i] << " \n"[i == sum-1];
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

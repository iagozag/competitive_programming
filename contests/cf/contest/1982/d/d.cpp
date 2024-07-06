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
    ll n, m, k; cin >> n >> m >> k;
    vector<vl> val(n, vl(m)); vector<vi> team(n, vi(m));
    rep(i, 0, n) rep(j, 0, m) cin >> val[i][j];
    rep(i, 0, n){
        string s; cin >> s;
        rep(j, 0, m) team[i][j] = s[j] == '1';
    }

    ll sum = 0;
    rep(i, 0, n) rep(j, 0, m){
        if(team[i][j]) sum += val[i][j];
        else sum -= val[i][j];
    }
    sum = abs(sum);

    if(sum == 0) return yes();

    vector<vector<vl>> pref(2, vector<vl>(n, vl(m+1)));
    rep(i, 0, n){
        rep(j, 1, m+1){
            pref[0][i][j] = pref[0][i][j-1];
            pref[1][i][j] = pref[1][i][j-1];
            if(team[i][j-1]) pref[1][i][j]++;
            else pref[0][i][j]++;
        }
    }

    set<ll> st;
    int i = 0, j = k;
    while(i+k <= n){
        int diff = 0;
        rep(l, i, i+k){
            diff += pref[1][l][j]-pref[1][l][j-k];
            diff -= pref[0][l][j]-pref[0][l][j-k];
        }
        diff = abs(diff);
        st.insert(diff), j++;
        if(j == m+1) j = k, i++;
    }

    ll g = 0;
    forr(x, st) if(x){
        g = x;
        break;
    }

    if(!g) return no();

    forr(x, st) if(x) g = __gcd(g, x);

    if(sum%g == 0) return yes();
    return no();
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}


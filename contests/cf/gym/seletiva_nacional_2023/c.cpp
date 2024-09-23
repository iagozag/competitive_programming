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

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const ll MAX = 6e5+10, p1 = 131, p2 = 137, mod1 = 1e9+7, mod2 = 1e9+9;

vl ps1(MAX), ps2(MAX);

void prec(){
    ps1[0] = 1;
    rep(i, 1, MAX) ps1[i] = ps1[i-1]*p1%mod1;
    ps2[0] = 1;
    rep(i, 1, MAX) ps2[i] = ps2[i-1]*p2%mod2;
}

ll hashf1(string s){
    ll h = 0;
    rep(i, 0, sz(s)){
        h = (h+(s[i]-'a'+1)*ps1[i])%mod1;
    }

    return h;
}

ll hashf2(string s){
    ll h = 0;
    rep(i, 0, sz(s)){
        h = (h+(s[i]-'a'+1)*ps2[i])%mod2;
    }

    return h;
}

void solve(){
    int n, m; cin >> n >> m;

    prec();

    set<pair<ll, ll>> db;
    rep(i, 0, n){
        string s; cin >> s;
        ll h1 = hashf1(s), h2 = hashf2(s);
        db.insert({h1,h2});
    }

    rep(i, 0, m){
        string s; cin >> s;
        ll h1 = hashf1(s), h2 = hashf2(s);

        bool can = false;
        rep(j, 0, sz(s)){
            for(int l = 'a'; l <= 'c'; l++){
                if(s[j] == l) continue;

                ll tmp1 = h1, tmp2 = h2;
                tmp1 -= (s[j]-'a'+1)*ps1[j];
                tmp1 = tmp1%mod1;
                tmp1 += mod1;
                tmp1 = tmp1%mod1;
                tmp1 = (tmp1+(l-'a'+1)*ps1[j])%mod1;
                tmp2 -= (s[j]-'a'+1)*ps2[j];
                tmp2 = tmp2%mod2;
                tmp2 += mod2;
                tmp2 = tmp2%mod2;
                tmp2 = (tmp2+(l-'a'+1)*ps2[j])%mod2;

                if(db.count({tmp1, tmp2})){ can = 1; break; }
            }
            if(can) break;
        }
        if(can) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

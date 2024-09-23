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

void no(){ cout << "0" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 998244353;

bool is_p(string s){
    for(int i = 0, j = sz(s)-1; i < j; i++, j--){
        if(s[i] != s[j]) return false;
    }
    return true;
}

void solve(){
    ll n, k; cin >> n >> k;
    string s; cin >> s;

    map<string, ll> mp;
    if(string(1, s[0]) == "?") mp["A"] = 1, mp["B"] = 1;
    else mp[string(1, s[0])] = 1;

    rep(i, 1, n){
        string ns, ns2;
        map<string, ll> mp2 = mp;
        mp.clear();

        for(auto [key, val]: mp2){
            if(s[i] == '?'){
                ns = key+"A", ns2 = key+"B";
                if(sz(ns) < k){
                    mp[ns] = (mp[ns]+val)%MOD;
                    mp[ns2] = (mp[ns2]+val)%MOD;
                } else{
                    string subns = ns.substr(1,k-1), subns2 = ns2.substr(1,k-1);
                    if(!is_p(ns)) mp[subns] = (mp[subns]+val)%MOD;
                    if(!is_p(ns2)) mp[subns2] = (mp[subns2]+val)%MOD;
                }
            } else{
                ns = key+s[i];
                if(sz(ns) < k) mp[ns] = (mp[ns]+val)%MOD;
                else{
                    string subns = ns.substr(1,k-1);
                    if(!is_p(ns)) mp[subns] = (mp[subns]+val)%MOD;
                }
            }
        }
    }

    ll ans = 0;
    forr(x, mp) ans = (ans+x.ss)%MOD;
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

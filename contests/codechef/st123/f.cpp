#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ff first
#define ss second
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void DBG() {
    cerr << "]" << endl;
}

void DBGC() {
    cerr << "]" << endl;
}

template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t)) cerr << ", ";
    DBG(t...);
}

template<class H, class... T> void DBGC(H h, T... t) {
    for(auto& x: h) cerr << x << " ";
    if(sizeof...(t)) cerr << "], [ ";
    DBGC(t...);
}

#ifndef _DEBUG
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define dbgc(...) cerr << "["<< #__VA_ARGS__ << "]: [ "; DBGC(__VA_ARGS__) 
#else
#define dbg(...) 0
#define dbgc(...) 0
#endif

const int MAX = 2e5+10;

void solve(){
    int n, q; cin >> n >> q;
    ll sum = 0; vi v(n); forr(x, v) cin >> x;
    sort(all(v)); rep(i, 0, n-1) sum += v[i]+v[i+1];

    map<ll, ii> mp; mp[sum] = {0, n-1};
    rep(i, 0, n){
        sum += v[0], sum -= v[i], swap(v[0], v[i]);
        repr(j, n-1, 0){
            if(i == j) continue;
            sum += v[n-1], sum -= v[j], swap(v[n-1], v[j]);

            if(!mp.count(sum)) mp[sum] = {i, j};

            sum -= v[n-1], sum += v[j], swap(v[n-1], v[j]);
        }
        sum -= v[0], sum += v[i], swap(v[0], v[i]);
    }

    rep(i, 0, q){
        ll s; cin >> s;
        if(mp.count(s)){
            swap(v[0], v[mp[s].ff]), swap(v[n-1], v[mp[s].ss]);
            rep(j, 0, n) cout << v[j] << " \n"[j == n-1]; 
            swap(v[0], v[mp[s].ff]), swap(v[n-1], v[mp[s].ss]);
        }
        else cout << -1 << endl;
    }
}

int main(){ _
    int t; cin >> t;

    while(t--) solve();

    exit(0);
}

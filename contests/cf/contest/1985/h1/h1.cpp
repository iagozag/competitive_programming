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

vi id, sz;

int find(int x){
    return id[x] = (id[x] == x ? x : find(id[x]));
}

void unio(int p, int q){
    p = find(p), q = find(q);
    if(p == q) return;
    if(sz[p] > sz[q]) swap(p, q);
    id[p] = q, sz[q] += sz[p];
}

void solve(){
    int n, m; cin >> n >> m;
    vector<vi> v(n, vi(m)); int k = 1;
    rep(i, 0, n){
        string s; cin >> s;
        rep(j, 0, m) if(s[j] == '#') v[i][j] = k++;
    }
    id = vi(k+1), iota(all(id), 0), sz = vi(k+1, 1); sz(k) = 0;

    rep(i, 0, n) rep(j, 0, m){
        if(v[i][j] > 0){
            if(i >= 1 and v[i-1][j] > 0) unio(v[i][j], v[i-1][j]);
            if(j >= 1 and v[i][j-1] > 0) unio(v[i][j], v[i][j-1]);
        }
    }

    ll ans = 0;
    rep(i, 0, n) ans = max(ans, 1LL*sz[i]);

    rep(i, 0, n){
        ll sum = 0; 
        set<int> st; vi id2 = id, sz2 = sz;
        rep(j, 0, m){
            if(i >= 1 and !st.count(find(v[i-1][j]))) 
                st.insert(id[v[i-1][j]]), sum += sz[id[v[i-1][j]]], unio(v[i][j], v[i-1][j]);
            if(!st.count(find(v[i][j]))) 
                st.insert(id[v[i][j]]), sum += sz[id[v[i][j]]];
            if(i+1 < n and !st.count(find(v[i+1][j]))) 
                st.insert(id[v[i+1][j]]), sum += sz[id[v[i+1][j]]], unio(v[i+1][j], v[i+1][j]);
        }
        ans = max(ans, sum) id = id2, sz = sz2;
    }

    cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

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
    id = vi(k), iota(all(id), 0), sz = vi(k, 1);

    rep(i, 0, n) rep(j, 0, m){
        if(v[i][j] > 0){
            if(i >= 1 and v[i-1][j] > 0) unio(v[i][j], v[i-1][j]);
            if(j >= 1 and v[i][j-1] > 0) unio(v[i][j], v[i][j-1]);
        }
    }

    vi prefr(n), prefc(m);
    rep(i, 0, n) rep(j, 0, m) if(v[i][j]) prefr[i]++, prefc[j]++;

    auto add = [&](int i, int j, set<int>& st) ->int{
        if(i < 0 or i >= n or j < 0 or j >= m or !v[i][j] or st.count(find(v[i][j]))) return 0;
        st.insert(id[v[i][j]]);
        return sz[id[v[i][j]]];
    };

    ll ans = 0;
    rep(i, 0, n){
        ll sum = m-prefr[i];
        set<int> st;
        rep(j, 0, m){
            sum += add(i-1, j, st); 
            sum += add(i, j, st); 
            sum += add(i+1, j, st); 
        }
        ans = max(ans, sum);
    }

    rep(j, 0, m){
        ll sum = n-prefc[j];
        set<int> st;
        rep(i, 0, n){
            sum += add(i, j-1, st); 
            sum += add(i, j, st); 
            sum += add(i, j+1, st); 
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

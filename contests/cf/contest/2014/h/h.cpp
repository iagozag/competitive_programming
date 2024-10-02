#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define per(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a.size())
#define endl '\n'
#define ff first
#define ss second
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

void no(){ cout << "No" << endl; }
void yes(){ cout << "Yes" << endl; }

const int MAX = 1e6, B = 450;

int freq[MAX];

struct query{
    int a, b, idx;
    query(int _a, int _b, int _idx): a(_a), b(_b), idx(_idx){}
    bool operator<(query other) const{
        return pair(a/B, b) < pair(other.a/B, other.b);
    }
};

void solve(){
    int n, q; cin >> n >> q;
    int v[n]; rep(i, 0, n){ cin >> v[i], --v[i]; }

    vector<query> qu;
    rep(i, 0, q){ int a, b; cin >> a >> b; --a, --b, qu.eb(a, b, i); }

    sort(qu.begin(), qu.end()); 

    int ans[q]; fill(ans, ans+q, 0); 
    int l = 0, r = -1, odds = 0;

    auto add = [&](int i){
        freq[v[i]]++, odds += (freq[v[i]]&1 ? 1 : -1); 
    };

    auto rem = [&](int i){
        freq[v[i]]--, odds += (freq[v[i]]&1 ? 1 : -1); 
    };

    rep(i, 0, q){
        auto [a, b, idx] = qu[i];

        while(l > a) add(--l);
        while(r < b) add(++r);
        while(l < a) rem(l++);
        while(r > b) rem(r--);

        ans[idx] = (odds == 0); 
    }

    while(l <= r) rem(l++); 

    forr(x, ans) cout << (x ? "YES" : "NO") << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

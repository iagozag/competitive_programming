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

void no(){ cout << "0" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 1e7+1, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vector<tuple<int, int, int>> v(MAX, {-1, -1, -1});
    rep(i, 0, n){
        int a; ll b, c; cin >> a >> b >> c;
        v[a] = {i+1, b, c};
    }

    vi ans;
    queue<tuple<int, int, int>> q;

    int curIdx = -1; int time = -1;
    rep(i, 0, MAX){
        auto [idx, m, c] = v[i];

        if(curIdx != -1 and time){
            time--;
            if(!time) curIdx = -1;
        }

        if(curIdx == -1 and !q.empty()){
            auto [idxq, mq, cq] = q.front(); q.pop();
            curIdx = idxq, time = mq;
        }

        if(idx == -1) continue;

        if(c){
            if(curIdx != -1) ans.eb(curIdx);
            curIdx = idx, time = m;
        }
        else q.push(v[i]);
    }

    if(!sz(ans)) return no();
    cout << sz(ans) << endl;
    rep(i, 0, sz(ans)) cout << ans[i] << " \n"[i==sz(ans)-1];
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

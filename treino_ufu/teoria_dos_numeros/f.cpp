#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repr(i,n,x) for(int i=n;i>=x;i--)
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

bool is_perfect(ll n){
    ll sum = 1;
    for (int i = 2; i*i <= n; i++) { 
        if (n % i == 0){
            if(i*i!=n) sum = sum + i + n/i;
            else sum=sum+i;
        }
    }

    return sum == n;
}

void solve(){
    ll n; cin >> n;

    vi ans;
    rep(i, 2, n) if(is_perfect(i)) ans.eb(i);
    if(is_perfect(n)) cout << "sim" << endl, ans.eb(n);
    else cout << "nao" << endl;

    if(ans.size() > 0){
        rep(i, 0, ans.size()-1) cout << ans[i] << " ";
        cout << ans[ans.size()-1];
        cout << endl;
    }
}

int main(){ _
    int t = 1;

    while(t--) solve();

    exit(0);
}

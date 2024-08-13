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

const int MAX = 2e5+10, MOD = 1e9+7;

int query(int q1, int q2){
    cout << "? " << q1 << " " << q2 << endl;
    int a; cin >> a;
    return a;
}

void solve(){
    int l = 1, r = 998, ans;
    while(l <= r){
        int m1 = l+(r-l)/3, m2 = r-(r-l)/3;
        int res = query(m1, m2);
        if(res == m1*m2) ans = m2, l = m2+1;
        else if(res == m1*(m2+1)) ans = m1, l = m1+1, r = m2-1;
        else r = m1-1;
    }

    cout << "! " << ans+1 << endl;
}

int main(){
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

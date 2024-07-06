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
void yes(int a){ cout << a << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    string s; cin >> s;
    int n = s.size();
    if(n == 3) return yes(0);

    bool c1 = 0, c2 = 0;
    rep(i, 0, n-2){
        set<char> t;
        t.insert({s[i], s[i+1], s[i+2]});
        if(t.size() == 3){
            if(i == 0 or i == n-3) c1 = 1;
            c2 = 2;
        }
    }

    if(c1) return yes(1);
    if(c2) return yes(2);

    set<char> ib, bi;
    ib.insert({s[0], s[1], s[n-1]}), bi.insert({s[0], s[n-1], s[n-2]});

    if(sz(ib) == 3 or sz(bi) == 3) return yes(2);

    if(s[0] != s[1] or s[n-1] != s[n-2]) return yes(3);

    rep(i, 0, n-1){
        if(s[i] != s[i+1]){
            if(s[0] != s[i] and s[0] != s[i+1]) return yes(3);
            else if(s[n-1] != s[i] and s[n-1] != s[i+1]) return yes(3);
        }
    }
    return yes(4);
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

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

void no(){ cout << "IMPOSSIBLE" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    ll n, m, s, d; cin >> n >> m >> s >> d;
    vl v(n); forr(x, v) cin >> x;
    sort(all(v));
    if(v[0]-1 < s) return no();

    vector<string> ans;
    ll k = 0, i = 0;
    while(true){
        if(i == n){
            string a = "RUN "; a += to_string(m-k);
            if(m != k) ans.eb(a);
            break;
        }

        string a = "RUN "; a += to_string(v[i]-1-k);
        ans.eb(a);
        k = v[i]-1;

        ll j = i;
        bool can = false; 
        while(j < n and v[j]+1-k <= d){
            if(j == n-1 or v[j+1]-v[j]-2 >= s){
                can = true, i = j+1;
                break;
            }
            j++;
        }

        if(can){
            a = "JUMP "; a += to_string(v[j]+1-k);
            ans.eb(a);
            k = v[j]+1;
        } else return no();
    }

    forr(x, ans) cout << x << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

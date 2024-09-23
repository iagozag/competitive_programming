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

void no(){ cout << "No" << endl; }
void yes(){ cout << "Yes" << endl; }

const int MAX = 1e7+10, MOD = 1e9+7;

vi nim(MAX, -1);

void solve(){
    int n, ans = 0; cin >> n;
    rep(i, 0, n){ int a; cin >> a; ans ^= nim[a]; }
    cout << (ans ? "Alice" : "Bob") << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    nim[0] = 0, nim[1] = 1, nim[2] = 0; int k = 2;
    for(int j = 4; j < MAX; j += 2) nim[j] = 0;
    rep(i, 3, MAX) if(nim[i] == -1){
        nim[i] = k;
        if(i < sqrt(MAX)+1) for(int j = i*i; j < MAX; j += i) if(nim[j] == -1) nim[j] = k;
        k++;
    }

    while(ttt--) solve();

    exit(0);
}

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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    if(n == 2){ cout << 1 << " " << 1 << endl << 1 << " " << 2 << endl; return; }
    if(n == 3){ cout << "1 1\n1 2\n3 3\n"; return; }
    
    int d = 0;
    rep(i, 1, n-1) cout << 1 << " " << i << endl, d++;

    bool u = false; int x = n, y = n;
    while(d--){
        if(!u) x--;
        else y--;
        u = !u;
    }

    cout << y << " " << x << endl;
    cout << n << " " << n << endl;
}

int main(){ _
    int ttt; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

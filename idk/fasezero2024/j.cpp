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



void solve(){
    int n, m; cin >> n >> m;
    int k, l; cin >> k >> l; --k, --l;
    vector<pii> moves = {{k, l}, {-k, l}, {-k, -l}, {k, -l}, {-l, -k}, {-l, k}, {l, -k}, {l, k}};

    vector<string> v(n+1); v[0] = string(m, '0');
    rep(i, 1, n+1){
        string s; cin >> s;
        v[i] = '0', v[i] += s;
    }

    int ma = -1, ai = 1, aj = 1;
    rep(i, 1, n+1) rep(j, 1, m+1){
        if(v[i][j] == '*') continue;

        int sum = 0;
        for(auto [a, b]: moves){
            a += i, b += j;
            if(a < 1 or a > n or b < 1 or b > m) continue;
            if(v[a][b] == '*') sum++;
        }

        if(ma < sum) ma = sum, ai = i, aj = j;
    }

    cout << ai << " " << aj << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

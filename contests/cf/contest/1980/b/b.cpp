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
    int n, f, k; cin >> n >> f >> k;
    vi v(n); forr(x, v) cin >> x;
    int fav = v[f-1]; map<int, int> mp;
    forr(x, v) mp[x]++;
    sort(all(v), greater<int>());

    bool found = false;
    for(int i = 0; i < k; i++){
        if(v[i] == fav){
            found = 1; mp[fav]--;
        }
    } 

    if(found){
        if(mp[fav] >= 1){ cout << "MAYBE" << endl; return; }
        else return yes();
    }

    return no();
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

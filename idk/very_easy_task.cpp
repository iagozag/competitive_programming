#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool check(ll m, ll n, ll x, ll y){
    if(m < x) return false;
    
    m -= x; n--;
    ll cnt = m/x + m/y;

    return(cnt >= n);
}

void solve(){
    ll n, x, y; cin >> n >> x >> y;
    if(y<x) swap(x,y);

    ll l = 0, r = 2e9+10;
    while(r > l+1){
        ll m = (l+r)/2;
        if(!check(m, n, x, y)) l = m;
        else r = m;
    }

    cout << r << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

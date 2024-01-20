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

ll is_prime(ll n){
    for(ll i = 2; i <= sqrt(n); ++i)
        if(n%i == 0) return i;

    return 0;
}

void solve(){
    ll l, r; cin >> l >> r;

    ll d_l = is_prime(l); ll d_r = is_prime(r);
    if((l == r && d_l == 0) || r <= 3) cout << -1 << endl;
    else if(d_l != 0) cout << l-d_l << " " << d_l << endl;
    else if(d_r != 0) cout << r-d_r << " " << d_r << endl;
    else if(l < 3) cout << 2 << " " << r-3 << endl;
    else cout << l-1 << " " << 2 << endl;
}

int main(){ 
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

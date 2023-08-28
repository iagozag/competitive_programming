#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll sum(ll n){
    ll i = n;
    while(i--) n += i;
    return n;
}

void solve(){
    ll n, cnt; cin >> n;
    ll ans = 0;
    vector<ll> v(n);
    for(auto& x: v) cin >> x;

    for(ll i = 0; i < n; i++){
        ll j = i, cnt = 0;
        while(v[i] == v[j] && j < n) j++, cnt++;
        i = j-1;

        ans += sum(cnt);
    }

    cout << ans << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

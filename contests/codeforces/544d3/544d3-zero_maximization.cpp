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

void solve(){
    int n; cin >> n;
    vector<long double> a(n), b(n);
    for(auto& x: a) cin >> x;
    for(auto& x: b) cin >> x;

    map<long double, int> mp; int zeros = 0;
    for(int i = 0; i < n; ++i){
        if(b[i] == 0 && a[i] == 0) { zeros++; continue; }
        else if(a[i] == 0) continue;

        mp[-b[i]/a[i]]++;
    }

    ll ans = 0;
    for(auto& x: mp) if(ans < x.s) ans = x.s;
    ans += zeros;

    cout << ans << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

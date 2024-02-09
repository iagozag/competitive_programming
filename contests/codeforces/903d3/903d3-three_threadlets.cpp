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
    vl v;
    for(int i = 0; i < 3; i++) { ll a; cin >> a; v.pb(a); }
    sort(all(v));

    int k = 0;
    if(v[2] % v[0] == 0 && v[1] % v[0] == 0) k += v[2]/v[0] + v[1]/v[0] + 1;
    else { cout << "NO\n"; return; }

    (k > 6) ? cout << "NO\n" : cout << "YES\n";
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

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
    int n, m, k, h, ans = 0; cin >> n >> m >> k >> h;
    vi v(n);
    for(auto& x: v) cin >> x;

    int extr = (m-1)*k;
    for(auto& x: v)
        if(abs(h-x)%k == 0 && abs(h-x) <= (m-1)*k && x != h) ans++;

    cout << ans << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

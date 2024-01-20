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
    int n, m; cin >> n >> m;
    vi v(n);
    for(int i = 0; i < n; i++){
        int a; cin >> a; if(a<0) v.pb(a);
    }
    sort(all(v));

    ll sum = 0;
    for (int i = 0; i < m; i++) sum += -(v[i]);

    cout << sum << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

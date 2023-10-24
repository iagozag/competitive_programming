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
    vl v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    int q; cin >> q;
    while(q--){
        int k, l; cin >> l >> k; l--;
        vl w = v;
        for(int i = 0; i < l; i++) w[i] = 0;
        for(int i = l+1; i < n; i++) w[i] &= w[i-1];
        
        ll r = n;
        while(l < r){
            ll m = (l+r)/2;
            if(w[m] >= k) l = m+1;
            else r = m;
        }
        
        (w[l-1] < k || l == 0) ? cout << -1 << " " : cout << l << " ";
    }
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}


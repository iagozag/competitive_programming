#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n, m; ll k; cin >> n >> m >> k; int q = 0;
    vector<pair<ll, int>> v(n); for(auto& x: v) cin >> x.first, x.second = q++, k -= x.first;
    sort(v.begin(), v.end()); 

    if(n == m){ for(int i = 0; i < n; i++) cout << 0 << " \n"[i==n-1]; return; }

    vector<ll> pref(n+1); for(int i = 1; i <= n; i++) pref[i] = pref[i-1]+v[i-1].first;

    vector<ll> anss(n);
    for(int i = 0; i < n; i++){
        ll l = 0, r = k, ans = k+1;
        while(l <= r){
            ll mid = l+(r-l)/2, val = v[i].first+mid+1;

            int idxr = lower_bound(v.begin(), v.end(), make_pair(val, -1))-v.begin();
            int idxl = n-m-(i >= n-m ? 1 : 0);

            ll sum = 0;
            if(idxr > idxl) sum += (idxr-idxl)*(val)-(pref[idxr]-pref[idxl]);

            if(idxl <= i and i < idxr) sum--;
            else sum += mid;

            if(sum > k) ans = mid, r = mid-1;
            else l = mid+1;
        }
        anss[v[i].second] = (ans == k+1 ? -1 : ans);
    }

    for(auto x: anss) cout << x << " ";
    cout << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

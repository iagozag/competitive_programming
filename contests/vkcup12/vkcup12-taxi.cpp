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
    ll n; cin >> n;
    map<ll,ll> mp;
    for(int i = 0; i < n; i++){
        ll a; cin >> a; mp[a]++;
    }

    ll ans = 0;
    ans += mp[4] + mp[2]/2 + mp[3];
    mp[1] -= min(mp[1], mp[3]), mp[3] = 0; mp[2] %= 2;

    if(mp[2] == 1){
        ans++;
        if(mp[1] > 0) mp[1] -= 2;
    }

    if(mp[1] > 0) ans += (mp[1]+3)/4;

    cout << ans << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}  

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
    vi v(n), ans(n, 1);
    for(auto& x: v) cin >> x;

    int cnt = 0, prev0 = -1, prev = -1, idx0, idx; map<int, int> mp;
    for(int i  = 0; i < n; i++){
        if(!mp.count(v[i])) mp[v[i]]++;
        else if(prev != v[i]){
            if(cnt == 0) prev0 = v[i], idx0 = i;
            cnt++, prev = v[i], idx = i, mp[v[i]]++;
        }

        if(cnt == 2) break;
    }

    if(cnt < 2){ cout << -1 << endl; return; }

    ans[idx0] = 2, ans[idx] = 3;
    for(auto& x: ans) cout << x << " ";
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

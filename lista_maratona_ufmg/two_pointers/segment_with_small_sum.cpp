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
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, ans = 0; ll ms; cin >> n >> ms;
    vl v(n);
    for(auto& x: v) cin >> x;

    int l = 0; ll sum = 0;
    for(int r = 0; r < n; r++){
        sum += v[r];
        while(sum > ms){
            sum -= v[l];
            l++;
        }
        ans = max(ans, r-l+1);
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

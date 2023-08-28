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
    int x, y, n; cin >> x >> y >> n;

    vi v(n);
    v[n-1] = y;
    for(int i = n-2, j = 1; i >= 0; i--){
        v[i] = v[i+1] - j;
        j++;
    }
    if(x > v[0]){
        cout << -1 << endl;
        return;
    }

    v[0] = x;
    for(auto& x: v) cout << x << " ";
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

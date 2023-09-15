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
    for(auto& x: v) cin >> x;

    ll mini = 1e9+10;
    for(int i = 0; i < n-1; i++){
        if(v[i+1]-v[i] < mini) mini = v[i+1]-v[i];
    }

    (mini >= 0) ? cout << mini/2+1 : cout << 0;
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

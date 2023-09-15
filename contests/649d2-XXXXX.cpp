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
    int n, x, sum = 0, k = 0; cin >> n >> x;
    vi v(n);
    for(auto& y: v) cin >> y;
    
    for(int i = 0; i < n; i++){
        sum += v[i];
        if(sum%x) k = max(k, i+1);
    }

    sum = 0;
    for(int i = n-1; i >= 0; i--){
        sum += v[i];
        if(sum%x) k = max(k,n-i);
    }

    (k>0) ? cout << k << endl : cout << -1 << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

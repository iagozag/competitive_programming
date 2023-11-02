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
    int n, sum = 0; cin >> n;
    vi v(n);
    for(auto& x: v) cin >> x;

    for(int i = 0; i < n-1; i++){
        if(v[i] == 0) sum++, v[i] = !v[i], v[i+1] = !v[i+1];
        if(i > 0 && v[i-1] == 0) { cout << -1 << endl; return; }
    }

    (v[n-1] == 0) ? cout << -1 : cout << sum;
    cout << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}


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
    vi a(n), b(m);
    for(auto& x: a) cin >> x;
    for(auto& x: b) cin >> x;
    sort(all(b), greater<int>());

    int i = 0, j = 0;
    while(i < n && j < m){
        if(b[j] >= a[i]) cout << b[j] << " ", j++;
        else cout << a[i] << " ", i++;
    }

    while(i < n) cout << a[i] << " ", i++;
    while(j < m) cout << b[j] << " ", j++;

    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}


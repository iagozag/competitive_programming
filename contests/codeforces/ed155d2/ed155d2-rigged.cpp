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
    map<int,int> mp;
    int st, e; cin >> st >> e;
    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        mp[a] = b;
    }

    for(auto& x: mp)
        if(x.f >= st && x.s >= e) { cout << -1 << endl; return; }

    cout << st << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

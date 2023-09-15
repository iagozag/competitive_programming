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
    map<double, double> mp;
    for(int i = 0; i < n; i++){
        double a, b; cin >> a >> b; 
        if(mp[a] == 0 || b < mp[a]) mp[a] = b;
    }

    set<int> ans;
    for(auto& x: mp){
        int m = x.f + ceil(x.s/2) - 1;
        ans.insert(m);
    }

    auto el = ans.begin();
    cout << *el << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

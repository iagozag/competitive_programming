#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    ll n; cin >> n;
    if((n*(n+1)/2)&1){ cout << "NO" << endl; return; }

    ll need = n*(n+1)/2/2;
    vector<ll> a, b; ll x = n;
    while(x){
        if(need >= x) a.emplace_back(x), need -= x; 
        else b.emplace_back(x);
        x--;
    }
    cout << "YES" << endl;
    cout << a.size() << endl;
    for(auto y: a) cout << y << " ";
    cout << endl;
    cout << b.size() << endl;
    for(auto y: b) cout << y << " ";
    cout << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

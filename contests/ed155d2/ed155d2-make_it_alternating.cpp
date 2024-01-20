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

ll fact(ll n){
    ll a = 1;
    for(ll i = 2; i <= n; i++) a *= i;

    return a;
}

void solve(){
    string st; cin >> st;
    ll rep = 0, total = 1, N = st.size();

    for(ll i = 0; i < N; i++){
        ll j = i;
        while(j < N && st[j] == st[i]) j++;

        rep += j-i-1;
        total = total*(j-i)%998244353;
        i = j-1;
    }
    
    for(int i = 1; i <= rep; i++)
        total = total*i%998244353;

    cout << rep << " " << total%998244353 << endl; 
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

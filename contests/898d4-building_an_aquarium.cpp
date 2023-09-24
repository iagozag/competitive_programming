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

int MAX = 2e5+10; ll n, x;
vector<ll> v(MAX);

bool is_possible(ll m){
    ll sum = 0;
    for(int i = 0; i < n; i++){
        if(m-v[i]>0) sum += m-v[i];
        if(sum > x) return false;
    }

    return true;
}

void solve(){
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> v[i];

    ll l = 1, r = 1e12;
    while(l < r){
        ll m = (l+r)/2;
        if(is_possible(m+1)) l=m+1;
        else r = m;
    }

    cout << l << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

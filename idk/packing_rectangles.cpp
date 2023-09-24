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

ll w, h, n;

bool is_possible(ll m){
    return (n <= (m/w)*(m/h));
}

void solve(){
    cin >> w >> h >> n;

    ll l = 0, r = 1;
    while(!is_possible(r)) r *= 2;
    
    while(l+1 < r){
        ll m = (l+r)/2;
        if(!is_possible(m)) l = m;
        else r = m;
    }

    cout << r << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

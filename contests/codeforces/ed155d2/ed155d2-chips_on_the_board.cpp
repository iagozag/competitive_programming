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
    ll min1 = LINF, min2 = LINF;
    vi va(n), vb(n);
    for(auto& x: va) { cin >> x; if(min1 > x) min1 = x; }
    for(auto& x: vb) { cin >> x; if(min2 > x) min2 = x; }

    ll sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++){
        sum1 += min1+vb[i];
        sum2 += min2+va[i];
    }

    cout << min(sum1, sum2) << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

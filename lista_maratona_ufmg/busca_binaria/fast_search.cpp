#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k, l, r; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a; cin >> a; v.pb(a);
    }
    sort(v.begin(), v.end());

    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> l >> r;

        auto lb = lower_bound(v.begin(), v.end(), l);
        auto ub = upper_bound(v.begin(), v.end(), r);
        cout << ub-lb << " "; 
    }
    cout << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

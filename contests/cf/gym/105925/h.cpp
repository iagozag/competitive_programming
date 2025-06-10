#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) (int) x.size()
#define ff first
#define ss second
#define int ll

int32_t main() { _
    int x; cin >> x;
    if(x == 1){ cout << 1 << endl; return 0; }
    int idx = -1;
    for(int i = 62; i >= 0; i--) if((x>>i)&1LL){ idx = i; break; }

    if((1LL<<idx) == x){ cout << x-1 << endl; return 0; }

    int num = 0;
    for(int i = 0, j = idx; i <= j; i++, j--){
        if((num|(1LL<<i)|(1LL<<j)) <= x) num |= ((1LL<<i) | (1LL<<j));
    }

    cout << num << endl;
}

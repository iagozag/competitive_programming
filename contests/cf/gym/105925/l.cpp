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
    int n; cin >> n;
    n *= 1e6;
    int pot = 1, ans = 1;
    while(pot < n) pot *= 2, ans ++;
    cout << ans+2 << endl;
}

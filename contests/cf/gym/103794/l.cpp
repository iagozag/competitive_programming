#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define ff first 
#define ss second
#define sz(x) (int)x.size()
#define int ll

int32_t main() { _
    string s; cin >> s; int sz = s.size();
    int n; cin >> n;
    if(n == 1){ cout << s << endl; return 0; }
    string ans = string(sz, '-');
    int i = 0, j = 0; bool down = 1;
    for(int k = 0; k < sz; k++){
        ans[j] = s[k];
        j += (down ? (n-i-1)*2 : i*2);
        if(i > 0 and i < n-1) down = !down;
        if(j >= sz) i++, j = i, down = (i != n-1);
    }
    cout << ans << endl;
    return 0;

}
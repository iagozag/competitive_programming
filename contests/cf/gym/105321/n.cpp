#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main() { _
    int n; cin >> n;
    vector<int> v(n); for(auto& x: v) cin >> x;
    sort(v.begin(), v.end());

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int a = v[i], b = v[j];

            int c = v[0];
            ans = max(ans, a*a+b*b+c*c-a*b-a*c-b*c);
            c = v.back();
            ans = max(ans, a*a+b*b+c*c-a*b-a*c-b*c);
        }
    }    

    cout << ans << endl;
}
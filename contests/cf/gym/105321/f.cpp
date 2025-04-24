#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main() { _
    int n;
    int s=0;
    cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;
    for(int i=0;i<n;i++) {
        if(v[i]) {
            s++;
            if(i>1 and v[i-1] and v[i-2]) s++;
        } else s--;
    }
    cout << s << '\n';
    return 0;
}
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
    string s, t; cin >> s >> t;
    long double c = 0, tot = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '*' and t[i] != '*') c++;
        if(s[i] == '*') tot++;
    }

    cout << fixed << setprecision(2) << (long double)(c/tot) << endl;
}

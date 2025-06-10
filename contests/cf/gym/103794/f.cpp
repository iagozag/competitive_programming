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
    int g,act=0;
    string s;
    vector<bool> v(361,false);
    v[0] = true;
    cin >> g >> s;

    for(char c:s) {
        if(c=='D') {
            for(int i=0;i<g;i++) {
                act=(act+1)%361;
                v[act] = true;
            }
        } else {
            for(int i=0;i<g;i++) {
                act=(act-1 +361)%361;
                v[act] = true;
            }
        }
    }

    for(int i=0;i<361;i++) if(v[i]==false) {
        cout << "N\n";
        return 0;
    }
    cout << "S\n";
    return 0;
}
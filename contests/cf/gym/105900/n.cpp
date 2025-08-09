#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define ff first
#define ss second
typedef long long ll;
#define int ll

int32_t main(){ _
    int n,q;
    cin >> n >> q;
    vector<int> v(n); for(auto& x: v) cin >> x;
    vector<int> pref(n+1);
    for(int i = 1; i < n+1; i++) pref[i] = pref[i-1]+v[i-1];
    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b; --a, --b;
        int len = b-a+1;
        cout << (pref[b+1]-pref[a] == len*(len+1)/2 ? "TAK" : "NIE") << endl;
    }
    exit(0);
}
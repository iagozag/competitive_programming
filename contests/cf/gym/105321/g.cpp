#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int32_t main() { _
    string s;cin >> s;

    map<int, int> mp;
    for(auto& x: s) mp[x]++;

    cout << min({mp['T'], mp['P'], mp['A']+mp['U']}) << endl;
    
}
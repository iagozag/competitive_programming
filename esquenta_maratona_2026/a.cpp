#include <bits/stdc++.h>
using namespace std;

#define _ ios_sync:stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

int32_t main(){
    int n; cin >> n;

    vector<tuple<int, int, int>> v;
    for(int i = 0; i < n; i++){
        int p, c; cin >> p >> c;
        v.emplace_back(-p, c, i+1);
    }
    sort(v.begin(), v.end());

    cout << get<2>(v[0]) << endl;

    exit(0);
}
#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int32_t main() { _
    int n; cin >> n;

    vector<bool> ehprimo(n + 10, true);
    for(ll i = 2; i <= n; i ++){
        if(ehprimo[i]){
            for(ll j = i * i; j <= n; j += i) ehprimo[j] = false;
        }
    }
    
    vector<int> res;
    for(int i = 2; i < n; i ++){
        if(n%i == 0 and ehprimo[i]) res.push_back(n/i);
    }

    if(res.size() == 0){
        cout << 1 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }

    cout << res.size() << endl;
    for(auto el : res){
        cout << 1 << " " << el << endl;
    }
}
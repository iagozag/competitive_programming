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

int32_t main() { //_
    ll y, k;
    cin >> y >> k;
    ll ynew = y;

    vector<ll> facts;
    for(ll i = 2; i*i <= ynew; i ++){
        if(ynew%i == 0){
            while(ynew%i == 0) 
                facts.push_back(i),
                ynew /= i;

        }
    }
    if(ynew != 1) facts.push_back(ynew);

    ll cur = 1;
    for(int i = 0; i < sz(facts); i ++){
        ll salto = __gcd(cur, y);
        ll times = facts[i]-1;
        if(times <= k){
            cur = cur + salto*times;
            k -= times;
        }
        else {
            cur = cur + k * salto;
            k = 0;
        }
    }

    if(k > 0){
        cur = cur + y * k;
    }

    cout << cur << endl;

}

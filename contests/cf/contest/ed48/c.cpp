#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n;
vector<vector<ll>> v;
vector<ll> preful, prefur, prefdl, prefdr;
vector<vector<ll>> pref;

ll sum_range(int i, int l, int r){
    return pref[i][r]-(l ? pref[i][l-1] : 0);
}

void solve(){
    cin >> n; v = vector<vector<ll>>(2, vector<ll>(n));
    for(int i = 0; i < 2; i++) for(int j = 0; j < n; j++) cin >> v[i][j];
    preful = prefdl = prefur = prefdr = vector<ll>(n), pref = vector<vector<ll>>(2, vector<ll>(n));
    for(int i = 0; i < n; i++){
        preful[i] = v[0][i]*i+(i ? preful[i-1] : 0);
        prefdl[i] = v[1][i]*i+(i ? prefdl[i-1] : 0);
        pref[0][i] = v[0][i]+(i ? pref[0][i-1] : 0);
        pref[1][i] = v[1][i]+(i ? pref[1][i-1] : 0);
    }
    for(int i = n-1; i >= 0; i--){
        prefur[i] = v[0][i]*(n-1-i)+(i < n-1 ? prefur[i+1] : 0);
        prefdr[i] = v[1][i]*(n-1-i)+(i < n-1 ? prefdr[i+1] : 0);
    }

    int i = 0, j = -1, b = 1; ll ans = 0, sum = 0, cnt = 0;
    while(j < n-1){
        if(b){
            ans = max(ans, sum+preful[n-1]-(j>=0?preful[j]:0)+(cnt-j-1)*sum_range(0, j+1, n-1)+
                           prefdr[j+1]+(cnt+n-j-1)*sum_range(1, j+1, n-1)), j++;

            sum += v[i][j]*(cnt++), i++, sum += v[i][j]*(cnt++); 
        } else{
            ans = max(ans, sum+prefdl[n-1]-(j>=0?prefdl[j]:0)+(cnt-j-1)*sum_range(1, j+1, n-1)+
                           prefur[j+1]+(cnt+n-j-1)*sum_range(0, j+1, n-1)), j++;

            sum += v[i][j]*(cnt++), i--, sum += v[i][j]*(cnt++); 
        }
        b = !b;
    }

    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

int n, s;
vector<int> v;
bool good(int x){
    int cnt = 1, mi = v[0];
    for(int i = 1; i < n; i++){
        if(v[i]-mi >= x) cnt++, mi = v[i];
    }

    return cnt >= s;
}

void solve(){
    cin >> n >> s;
    v = vector<int>(n);
    for(int i = 0; i < n; i++) cin >> v[i];   

    int l = 0, r = 1e9, ans = r;
    while(l <= r){
        int m = l+(r-l)/2;
        if(good(m)) ans = m, l = m+1;
        else r = m-1;
    }

    cout << ans << endl;
	exit(0);
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}


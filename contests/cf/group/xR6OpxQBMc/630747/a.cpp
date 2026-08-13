#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    for(int i = 2; i < n; i++){
        bool can = 1;
        for(int j = 2; j*j <= i; j++){
            if(i%j == 0){ can = 0; break; }
        }
        if(can){
            int other = n-i;

            for(int j = 2; j*j <= other; j++){
                if(other%j == 0){ cout << i << ' ' << other << endl; return; }
            }
        }
    }
	exit(0);
}

int32_t main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}


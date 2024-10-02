#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int cnt = 0, first = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') cnt++;
        if(s[i] == '0' and first == -1) first = i; 
    }

    for(int k = 1; k <= n/2; k++){
        if(n-k <= cnt) cout << 0 << " ";
        else{
            int i = first, need = 0;
            while(i < n-k) need++, i += k;
            cout << need << " ";
        }
    }
    cout << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}

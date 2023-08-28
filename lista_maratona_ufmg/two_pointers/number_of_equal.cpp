#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;
    ll ans = 0;
    vi a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    
    for(int i = 0, j = 0, cnt = 0; i < n; i++){
        if(i > 0 && a[i] == a[i-1]){
            ans += cnt;
            continue;
        }
        cnt = 0;

        while(a[i] > b[j] && j < m) j++;
        while(a[i] == b[j] && j < m)
            cnt++, j++;

        ans += cnt;
    }

    cout << ans << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}


#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;
    vi v(n+1); set<int> st;
    for(int i = 0; i < n; i++){
        int a; cin >> a; v[i] = a; st.insert(a);
    }

    int min;
    for(int i = 0; i <= n; i++) if(!st.count(i)){
        min = i;
        break;
    }
    v[n] = min;

    vi ans(n+1);
    if(k > n) k = n+1 + k%(n+1);
    for(int i = 0; i <= n; i++){
        int idx = i+k;
        while(idx > n) idx -= (n+1);

        ans[idx] = v[i];
    }

    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

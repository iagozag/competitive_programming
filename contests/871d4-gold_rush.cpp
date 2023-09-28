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

bool find(int n, int m){
    if(n == m) return 1;
    if(n%3 != 0) return 0;

    return find(n/3, m) || find(n*2/3, m);
}

void solve(){
    int n, m; cin >> n >> m;
    if(n == m) { cout << "YES\n"; return; }
    if(n%3 != 0 || m > n) { cout << "NO\n"; return; }

    (find(n, m)) ? cout << "YES" : cout << "NO";
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

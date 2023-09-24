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
    int n, k, x; cin >> n >> k >> x;
    if(k > n || k > x+1){ cout << -1 << endl; return; }

    ll sum = 0;
    for(int i = 0; i < k; i++) sum += i;

    if(x != k)
        for(int i = 0; i < n-k; i++) sum += x;
    else
        for(int i = 0; i < n-k; i++) sum += x-1;

    cout << sum << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

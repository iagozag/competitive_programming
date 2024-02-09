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
    ll n, m; cin >> n >> m;

    ll min = 0;
    if(n < m*2) min = n-m;
    else min += ((n/m)*(n/m-1)/2)*(m-(n%m)) + ((n/m+1)*(n/m)/2)*(n%m);

    ll now = n-(m-1);
    ll max = (n-(m-1))*((n-(m-1))-1)/2;

    cout << min << " " << max << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

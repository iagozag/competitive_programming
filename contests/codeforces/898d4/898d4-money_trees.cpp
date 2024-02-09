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
    vi vf(n), vh(n);
    for(int i = 0; i < n; i++) cin >> vf[i];
    for(int i = 0; i < n; i++) cin >> vh[i];

    int maxi = 0, sum = 0;
    for(int i = 0, j = 0; i < n; i++){
        while(j < n && (j<=i || vh[j-1]%vh[j]==0) && sum+vf[j]<=k) sum+=vf[j], j++;

        maxi = max(maxi, j-i), sum -= vf[i];
    }

    cout << maxi << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

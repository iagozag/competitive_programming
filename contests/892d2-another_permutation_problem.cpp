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
    int n, sum = 0; cin >> n;
    vi v(n);
    for(int i = 1; i <= n; i++) v[i-1] = i;

    for(int i = 0; i < n; i++){
        reverse(v.begin()+i, v.end());

        vi sums;
        for(int j = 1; j <= n; j++) sums.pb(v[j-1]*j);
        sort(sums.begin(), sums.end());

        int current = 0;
        for(int j = 0; j < n-1; j++) current += sums[j];
        sum = max(sum, current);

        reverse(v.begin()+i, v.end());
    }
    
    cout << sum << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

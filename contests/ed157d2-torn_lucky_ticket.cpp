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

bool verify_sum(string st, int n){
    int sum1 = 0, sum2 = 0;
    for(int i = 0; i < n/2; i++)
        sum1 += st[i]-'0', sum2 += st[n-i-1]-'0';

    return (sum1 == sum2);
}

void solve(){
    int n; cin >> n;
    ll sum = n;
    vector<string> v(n);
    for(auto& x: v) cin >> x;

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int size = v[i].size() + v[j].size();
            if((size&1) != 0) continue;

            if(verify_sum(v[i]+v[j], size)) sum++;
            if(verify_sum(v[j]+v[i], size)) sum++;
        }
    }

    cout << sum << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}


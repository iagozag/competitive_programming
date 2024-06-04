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
    int n; cin >> n; n--;
    vl v(n); set<ll> numbers;
    for(auto& x: v) cin >> x;
    for(int i = 1; i <= n+1; i++) numbers.insert(i);

    bool flag = true;
    vl sums(n); sums[0] = v[0];
    for(int i = 1; i < n; i++)
        sums[i] = v[i]-v[i-1];

    ll rep = 0;
    for(auto& x: sums)
        if(numbers.count(x)) numbers.erase(x);
        else rep = x;

    int sum = 0;
    for(auto& x: numbers) sum += x;

    if(numbers.size() > 2 || sum != rep && rep != 0) flag = false;
    (flag) ? cout << "YES" : cout << "NO";
    cout << endl;
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}

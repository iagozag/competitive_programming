#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a.size())
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 11, MOD = 1e9+7;

int rnd(int a, int b){
    return a + rand() % (b - a + 1);
}

void solve(){
    int n = rnd(0, 1000), m = rnd(0, 1000), sum = n+m+1;
    while(sum < 2 or sum > MAX) n = rnd(0, 1000), m = rnd(0, 1000), sum = n+m+1;

    cout << n << " " << m << endl;
    rep(i, 0, sum) cout << rnd(1, 1000000000) << " \n"[i==sum-1];
    rep(i, 0, sum) cout << rnd(1, 1000000000) << " \n"[i==sum-1];
}

int main(){ // _
    int ttt = rnd(1, 4);
    cout << ttt << endl;

    while(ttt--) solve();

    exit(0);
}

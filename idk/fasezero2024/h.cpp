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

void no(){ cout << "-1" << endl; }
void yes(){ cout << "YES" << endl; }

constexpr int MAX_N = 1e9 + 10;
constexpr int s_MAX_N = 33000;

vector<int> primes;

void fil_crivo() {
  vector<bool> is_p(s_MAX_N + 1, true);
  for (ll i = 2; i <= s_MAX_N; i++) {
    if (is_p[i]) {
      primes.push_back(i);
      for (ll j = i * i; j <= s_MAX_N; j+=i)
        is_p[j] = false;
    }
  }
}

bool is_prime(ll N) {
  if (N == 1) return false;
  for (auto p : primes) {
    if (N == p) return true;
    if (N % p == 0) {
      return false;
    }
  }
  return true;
}

void solve(){
    ll n; cin >> n;
    
    ll mi = -1, ma = -1;
    for(ll i = n/2; i > 0; i--){
        if(!is_prime(i) and !is_prime(n-i)){ mi = i, ma = n-i; break; }
    }

    if(mi == -1) return no();
    cout << mi << " " << ma << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    fil_crivo();

    while(ttt--) solve();

    exit(0);
}
